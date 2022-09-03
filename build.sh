#! /bin/bash


# Get source directory, "src" by default
printf "Enter source directory: "
read -r SOURCE_DIRECTORY
if [[ -z $SOURCE_DIRECTORY ]]; then
	SOURCE_DIRECTORY=$(realpath "$PWD/src")
	printf "\033[F\033[2KEnter source directory: $SOURCE_DIRECTORY\n"
fi

# Get archive destination, ".a" by default
printf "Enter archive destination: "
read -r DESTINATION
if [[ -z $DESTINATION ]]; then
	DESTINATION=$(realpath "$PWD/.a")
	printf "\033[F\033[2KEnter archive directory: $DESTINATION\n"
fi

# Create array of source files
shopt -s nullglob
SOURCE_FILES=($SOURCE_DIRECTORY/*)
shopt -u nullglob

# Get length of array
SOURCE_FILES_COUNT=${#SOURCE_FILES[@]}

# Create temporary directory
TEMPORARY_DIRECTORY=$(mktemp -d)

# Compile source files
printf "\n"
stty -echo
for (( i=0 ; i<$SOURCE_FILES_COUNT ; i++ )); do
	SOURCE_FILE=${SOURCE_FILES[i]}
	printf "\033[F\033[2KCompiling file $(( i+1 ))/$SOURCE_FILES_COUNT: $SOURCE_FILE\n"
	g++ $SOURCE_FILE -I include/ -o "$TEMPORARY_DIRECTORY/$(basename $SOURCE_FILE)" -c -std=c++20
done
read -N 9999999 -t 0.001
stty echo

# Archive compiled files
ar crs $DESTINATION $(ls -d $TEMPORARY_DIRECTORY/*)

# Remove temporary directory
rm -rf $TEMPORARY_DIRECTORY

printf "\033[F\033[2KDone\n"

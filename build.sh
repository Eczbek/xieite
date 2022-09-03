#! /bin/bash


SOURCE_DIRECTORY="$PWD/src/"

HEADER_DIRECTORY="$PWD/include/"

DESTINATION=${1:-"$PWD/.a"}


shopt -s nullglob
SOURCE_FILES=($SOURCE_DIRECTORY/*)
shopt -u nullglob
SOURCE_FILES_COUNT=${#SOURCE_FILES[@]}
TEMPORARY_DIRECTORY=$(mktemp -d)
stty -echo
for (( i=0 ; i<$SOURCE_FILES_COUNT ; i++ )); do
	SOURCE_FILE=$(realpath ${SOURCE_FILES[i]})
	printf "\033[2K  Compiling file $(( $i+1 ))/$SOURCE_FILES_COUNT: $SOURCE_FILE\r"
	g++ $SOURCE_FILE -I $HEADER_DIRECTORY -o "$TEMPORARY_DIRECTORY/$(basename $SOURCE_FILE)" -c -std=c++20
done
read -N 9999999 -t 0.001
stty echo
printf "\033[2K  Archiving\r"
ar crs $DESTINATION $(ls -d $TEMPORARY_DIRECTORY/*)
rm -rf $TEMPORARY_DIRECTORY
printf "\033[2K"

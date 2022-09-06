#! /bin/bash

HEADER_DIRECTORY="$PWD/include/"

SOURCE_DIRECTORY="$PWD/src/"

DESTINATION=${1:-"$PWD/.a"}

COMPILER_FLAGS="-c -std=c++20 -pthread"


SOURCE_FILES=()
mapfile -d '' SOURCE_FILES < <(find $(realpath "$SOURCE_DIRECTORY") -type f -print0)
SOURCE_FILES_COUNT=${#SOURCE_FILES[@]}
TEMPORARY_DIRECTORY="$(mktemp -d)"
stty -echo
for (( i=0 ; i<$SOURCE_FILES_COUNT ; i++ )); do
	SOURCE_FILE_PATH="$(realpath ${SOURCE_FILES[i]})"
	printf "\r\033[2KCompiling file $(( $i+1 ))/$SOURCE_FILES_COUNT: $SOURCE_FILE_PATH"
	g++ "$SOURCE_FILE_PATH" -I "$HEADER_DIRECTORY" -o "$TEMPORARY_DIRECTORY/$(basename \"$(mktemp)\")" $COMPILER_FLAGS
done
read -N 9999999 -t 0.001
stty echo
printf "\r\033[2KArchiving"
ar crs "$DESTINATION" $(ls -d $TEMPORARY_DIRECTORY/*)
rm -rf "$TEMPORARY_DIRECTORY"
printf "\r\033[2K"

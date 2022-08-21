#! /bin/bash

TEMP_DIR=`mktemp -d`
for FILE in `ls src`
do
	echo 'Compiling '$FILE
	g++ src/$FILE -o $TEMP_DIR/$FILE -c -std=c++20 -I include/
done
echo 'Archiving'
ar crs ${1:-util.a} `ls -d $TEMP_DIR/*`
rm -rf $TEMP_DIR
echo 'Done'

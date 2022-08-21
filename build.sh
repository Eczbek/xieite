#! /bin/bash

DIR=`mktemp -d`
for FILE in `ls src`
do
	echo 'Compiling '$FILE
	g++ src/$FILE -o $DIR/$FILE -c -std=c++20 -I include/
done
echo 'Archiving'
ar crs ${1:-util.a} `ls -d $DIR/*`
rm -rf $DIR
echo 'Done'

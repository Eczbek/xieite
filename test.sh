#!/usr/bin/env bash

for filename in $(find test -type f); do
	g++ -o/dev/null $filename -Iinclude -c -std=c++26 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion
	if [ $? != 0 ]; then
		printf "\x1B[91mFAILED\x1B[0m ${filename}\n"
		break
	fi
	printf "\x1B[92mPASSED\x1B[0m ${filename}\n"
done

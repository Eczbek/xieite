#!/usr/bin/env bash

out=$(mktemp)
find "$(dirname "$BASH_SOURCE")/test" -type f -print0 | xargs -P$(nproc) -0 -I% sh -c "g++ -o/dev/null % -Iinclude -c -std=c++26 -freflection -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -fconcepts-diagnostics-depth=999 -fdiagnostics-color=always 2>> $out && echo -e '\x1B[92mPASSED\x1B[0m %' || echo -e '\x1B[91mFAILED\x1B[0m %'"
cat $out

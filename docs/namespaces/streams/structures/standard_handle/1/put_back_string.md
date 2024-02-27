# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:putBackString
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Puts a string back into the input buffer.

&nbsp;

## Synopsis
#### 1)
```cpp
void putBackString(std::string_view value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    terminal.putBackString("Hello, world!\n");

    std::string input;
    std::getline(std::cin, input);

    std::cout << input << '\n';
}
```
Output:
```
Hello, world!
```

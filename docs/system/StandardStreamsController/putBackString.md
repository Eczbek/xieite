# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:putBackString
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Puts a string back into the input buffer

&nbsp;

## Synopsis
```cpp
void putBackString(std::string_view value) noexcept;
```
#### Function parameters
- `value` - A `std::string_view` to prepend to the buffer

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/system/terminal.hpp>

int main() {
    xieite::system::terminal.putBackString("Hello, world!\n");

    std::string input;

    std::getline(std::cin, input);

    std::cout << input << '\n';
}
```
Output:
```
Hello, world!
```

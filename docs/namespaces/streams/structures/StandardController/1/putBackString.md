# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../StandardController.md)\:\:putBackString
Defined in header [<xieite/streams/StandardController.hpp>](../../../../../../include/xieite/streams/StandardController.hpp)

&nbsp;

## Description
Puts a string back into the input buffer.

&nbsp;

## Synopses
#### 1)
```cpp
void putBackString(std::string_view value) const noexcept;
```

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

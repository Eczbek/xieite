# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:readCharacter
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Waits for and returns the next keypress input

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
char readCharacter() noexcept;
```
#### Return type
- `char` - The input character

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
    std::cin.putback('h');

    std::cout << xieite::system::terminal.readCharacter() << '\n';
}
```
Output:
```
h
```

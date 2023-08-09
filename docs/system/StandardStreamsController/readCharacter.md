# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:readCharacter
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Waits for and returns the next keypress input.

&nbsp;

## Synopses
#### 1)
```cpp
char readCharacter() noexcept;
```

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

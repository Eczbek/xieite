# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../standard_controller.md)\:\:readCharacter
Defined in header [<xieite/streams/standard_controller.hpp>](../../../../../../include/xieite/streams/standard_controller.hpp)

&nbsp;

## Description
Waits for and returns the next keypress input.

&nbsp;

## Synopses
#### 1)
```cpp
char readCharacter() const noexcept;
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

# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:readCharacter
Defined in header [<xieite/streams/standard_handle.hpp"](../../../../../../include/xieite/streams/standard_handle.hpp)

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
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    std::cin.putback('h');

    std::cout << terminal.readCharacter() << '\n';
}
```
Output:
```
h
```

# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:[StandardController\<inputStream, outputStream\>](../../StandardController.md)\:\:readCharacter
Defined in header [<xieite/streams/StandardController.hpp>](../../../../include/xieite/streams/StandardController.hpp)

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

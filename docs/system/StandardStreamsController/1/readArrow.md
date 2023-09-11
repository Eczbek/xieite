# [xieite](../../../xieite.md)\:\:[system](../../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../../StandardStreamsController.md)\:\:readArrow
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Waits for and returns the next arrow key input. Puts back characters if fails to parse escape sequence.

&nbsp;

## Synopses
#### 1)
```cpp
xieite::system::BufferPosition readArrow() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/system/BufferPosition.hpp>
#include <xieite/system/terminal.hpp>

int main() {
    xieite::system::terminal.putBackString("\x1B[A"); // Up arrow

    xieite::system::BufferPosition arrow = xieite::system::terminal.readArrow();

    if (arrow.row || arrow.column) {
        std::cout << "Arrow: (" << arrow.row << ", " << arrow.column << ")\n";
    } else {
        std::cout << "Character: " << xieite::system::terminal.readCharacter() << '\n';
    }
}

```
Output:
```
Arrow: (-1, 0)
```

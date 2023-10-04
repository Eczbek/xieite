# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:[StandardController](../../StandardController.md)\:\:readKey
Defined in header [<xieite/streams/StandardController.hpp>](../../../../include/xieite/streams/StandardController.hpp)

&nbsp;

## Description
Waits for and returns the key press. Puts back characters if fails to parse escape sequence.

&nbsp;

## Synopses
#### 1)
```cpp
xieite::streams::Key readKey() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/streams/Key.hpp>
#include <xieite/system/terminal.hpp>

int main() {
    xieite::system::terminal.putBackString("\x1B[C"); // Right arrow

    switch (xieite::system::terminal.readKey()) {
        case xieite::streams::Key::ArrowUp:
            std::cout << "Up\n";
            break;
        case xieite::streams::Key::ArrowDown:
            std::cout << "Down\n";
            break;
        case xieite::streams::Key::ArrowRight:
            std::cout << "Left\n";
            break;
        case xieite::streams::Key::ArrowLeft:
            std::cout << "Right\n";
            break;
        default:
            std::cout << "None\n";
    }
}

```
Output:
```
Right
```

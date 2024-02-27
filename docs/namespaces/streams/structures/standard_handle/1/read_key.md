# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:readKey
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Waits for and returns the key press. Puts back characters if fails to parse escape sequence.

&nbsp;

## Synopsis
#### 1)
```cpp
xieite::streams::Key readKey() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/streams/key.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    terminal.putBackString("\x1B[C"); // Right arrow

    switch (terminal.readKey()) {
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

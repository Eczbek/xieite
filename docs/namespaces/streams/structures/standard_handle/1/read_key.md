# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:readKey\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Waits for and returns the key press. Does not put back characters upon failure to parse escape sequence.

&nbsp;

## Synopsis
#### 1)
```cpp
xieite::streams::Key readKey() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    switch (terminal.readKey()) {
    case xieite::streams::Key::ArrowUp:
        std::println("Up");
        break;
    case xieite::streams::Key::ArrowDown:
        std::println("Down");
        break;
    case xieite::streams::Key::ArrowRight:
        std::println("Left");
        break;
    case xieite::streams::Key::ArrowLeft:
        std::println("Right");
        break;
    default:
        std::println("None");
    }
}
```
Possible output:
```
Right
```

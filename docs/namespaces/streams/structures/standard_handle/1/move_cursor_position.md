# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:moveCursorPosition\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Moves the terminal cursor's position.

&nbsp;

## Synopsis
#### 1)
```cpp
void moveCursorPosition(xieite::streams::Position difference) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.clearScreen();
    terminal.setCursorPosition(xieite::streams::Position(0, 0));
    terminal.moveCursorPosition(xieite::streams::Position(2, 3));

    std::println("Hello, world!");
}
```
Possible output:
```


  Hello, world!
```

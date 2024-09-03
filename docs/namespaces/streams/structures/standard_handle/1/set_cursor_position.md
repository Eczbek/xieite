# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorPosition\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Sets the terminal cursor's position.

&nbsp;

## Synopsis
#### 1)
```cpp
void setCursorPosition(xieite::streams::Position position) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setCursorPosition(xieite::streams::Position(2, 5));
    std::println("Hello, world!");
}
```
Possible output:
```


     Hello, world!
```

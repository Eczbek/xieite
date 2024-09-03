# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:getCursorPosition\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Gets the cursor's position in the terminal.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] xieite::streams::Position getCursorPosition() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setCursorPosition(xieite::streams::Position(0, 0));
    std::print("12345");

    auto position = terminal.getCursorPosition();
    std::println("\n({}, {})", position.row, position.column);
}
```
Possible output:
```
12345
(0, 5)
```

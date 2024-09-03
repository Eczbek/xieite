# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:getScreenSize\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Gets the terminal screen size, in rows and columns.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] xieite::streams::Position getScreenSize() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    auto size = terminal.getScreenSize();
    std::println("({}, {})", size.row, size.column);
}
```
Possible output:
```
(53, 197)
```

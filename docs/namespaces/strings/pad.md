# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:pad\(\)
Defined in fragment [xieite:strings.pad](../../../src/strings/pad.cpp)

&nbsp;

## Description
Pads a string from both sides.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string pad(std::string_view value, std::size_t size, char padding = ' ', bool alignFront = true) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    for (int i = 3; i < 10; ++i) {
        std::println("|{}|", xieite::strings::padCenter("xyz", i));
    }
}
```
Output:
```
|xyz|
|xyz |
| xyz |
| xyz  |
|  xyz  |
|  xyz   |
|   xyz   |
```

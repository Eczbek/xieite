# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:padFront\(\)
Defined in fragment [xieite:strings.padFront](../../../src/strings/pad_front.cpp)

&nbsp;

## Description
Pads the front of a string.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string padFront(std::string_view value, std::size_t size, char padding = ' ') noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::padFront("418", 7, '0'));
}
```
Output:
```
000418
```

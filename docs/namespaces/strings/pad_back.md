# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:padBack\(\)
Defined in fragment [xieite:strings.padBack](../../../src/strings/pad_back.cpp)

&nbsp;

## Description
Pads the back of a string.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string padBack(std::string_view value, std::size_t size, char padding = ' ') noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::padBack("BEEF", 7, '='));
}
```
Output:
```
BEEF===
```

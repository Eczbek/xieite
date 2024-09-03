# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:trimBack\(\)
Defined in fragment [xieite:strings.trimBack](../../../src/strings/trim_back.cpp)

&nbsp;

## Description
Trims the back of a string.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trimBack(std::string_view string, char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trimBack(std::string_view string, std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::trimBack("bababananana", "an"));
}
```
Output:
```
babab
```

# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:trim\(\)
Defined in fragment [xieite:strings.trim](../../../src/strings/trim.cpp)

&nbsp;

## Description
Trims both the front and back of a string.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trim(std::string_view string, char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trim(std::string_view string, std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::trim("bababatananana", "ban"));
}
```
Output:
```
t
```

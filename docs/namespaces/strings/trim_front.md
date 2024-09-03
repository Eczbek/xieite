# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:trimFront\(\)
Defined in fragment [xieite:strings.trimFront](../../../src/strings/trim_front.cpp)

&nbsp;

## Description
Trims the front of a string.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view trimFront(std::string_view string, char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view trimFront(std::string_view string, std::string_view characters) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::trimFront("bababananana", "ab"));
}
```
Output:
```
nanana
```

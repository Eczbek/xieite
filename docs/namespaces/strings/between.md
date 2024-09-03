# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:between\(\)
Defined in fragment [xieite:strings.between](../../../src/strings/between.cpp)

&nbsp;

## Description
Takes a substring between two other substrings.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view between(std::string_view string, std::string_view start, std::string_view end) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view between(std::string_view string, std::string_view start, char end) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr std::string_view between(std::string_view string, char start, std::string_view end) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr std::string_view between(std::string_view string, char start, char end) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::between("Hello, world!", "el", "ld"));
}
```
Output:
```
lo, wor
```

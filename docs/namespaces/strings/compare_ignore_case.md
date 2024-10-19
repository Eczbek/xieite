# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:compareIgnoreCase\(\)
Defined in fragment [xieite:strings.compareIgnoreCase](../../../src/strings/compare_ignore_case.cpp)

&nbsp;

## Description
Compares two strings, ignoring case.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::strong_ordering compareIgnoreCase(char left, char right) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::strong_ordering compareIgnoreCase(std::string_view left, std::string_view right) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::is_eq(xieite::strings::compareIgnoreCase("HELLO", "hello")));
}
```
Output:
```
true
```

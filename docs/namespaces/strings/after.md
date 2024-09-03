# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:after\(\)
Defined in fragment [xieite:strings.after](../../../src/strings/after.cpp)

&nbsp;

## Description
Takes the rest of a string after some substring.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string_view after(std::string_view string, std::string_view start) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string_view after(std::string_view string, char start) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::after("Hello, world!", ' '));
}
```
Output:
```
world!
```

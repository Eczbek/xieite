# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:replace\(\)
Defined in fragment [xieite:strings.replace](../../../src/strings/replace.cpp)

&nbsp;

## Description
Replaces instances of a substring with another.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string replace(std::string_view value, std::string_view original, std::string_view replacement) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string replace(std::string_view value, char original, std::string_view replacement) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr std::string replace(std::string_view value, std::string_view original, char replacement) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr std::string replace(std::string_view value, char original, char replacement) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::replace("1 + 2 + 3\n", " + ", '-');
}
```
Output:
```
1-2-3
```

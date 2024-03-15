# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:replace
Defined in header [<xieite/strings/replace.hpp>](../../../include/xieite/strings/replace.hpp)

&nbsp;

## Description
Replaces instances of a substring with another.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string replace(std::string_view value, std::string_view target, std::string_view replacement, std::size_t start = 0) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string replace(std::string_view value, char target, std::string_view replacement, std::size_t start = 0) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr std::string replace(std::string_view value, std::string_view target, char replacement, std::size_t start = 0) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr std::string replace(std::string_view value, char target, char replacement, std::size_t start = 0) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/replace.hpp"

int main() {
    std::println("{}", xieite::strings::replace("1 + 2 + 3\n", " + ", '-');
}
```
Output:
```
1-2-3
```

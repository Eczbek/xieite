# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:join\(\)
Defined in header [<xieite/strings/join.hpp>](../../../include/xieite/strings/join.hpp)

&nbsp;

## Description
Joins multiple strings with a delimiter.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range>
requires(std::constructible_from<std::string, std::ranges::range_const_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, std::string_view delimiter = "") noexcept;
```
#### 2)
```cpp
template<std::ranges::range Range>
requires(std::constructible_from<std::string, std::ranges::range_const_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, char delimiter) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string_view>
#include <vector>
#include "xieite/strings/join.hpp"

int main() {
    std::vector<std::string_view> strings = {
        "abc",
        "def",
        "ghi"
    };

    std::println("{}", xieite::strings::join(strings, "-"));
}
```
Output:
```
abc-def-ghi
```

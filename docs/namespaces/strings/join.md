# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:join\<\>\(\)
Defined in fragment [xieite:strings.join](../../../src/strings/join.cpp)

&nbsp;

## Description
Joins multiple strings with a delimiter.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range>
requires(std::constructible_from<std::string, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, std::string_view delimiter = "", std::string_view prefix = "", std::string_view suffix = "") noexcept;
```
#### 2)
```cpp
template<std::ranges::input_range Range>
requires(std::constructible_from<std::string, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, char delimiter, std::string_view prefix = "", std::string_view suffix = "") noexcept;
```
#### 3)
```cpp
template<std::ranges::input_range Range>
requires(std::constructible_from<std::string, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, std::string_view delimiter, char prefix, std::string_view suffix = "") noexcept;
```
#### 4)
```cpp
template<std::ranges::input_range Range>
requires(std::constructible_from<std::string, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, char delimiter, char prefix, std::string_view suffix = "") noexcept;
```
#### 5)
```cpp
template<std::ranges::input_range Range>
requires(std::constructible_from<std::string, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, std::string_view delimiter, std::string_view prefix, char suffix) noexcept;
```
#### 6)
```cpp
template<std::ranges::input_range Range>
requires(std::constructible_from<std::string, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, char delimiter, std::string_view prefix, std::string_view suffix) noexcept;
```
#### 7)
```cpp
template<std::ranges::input_range Range>
requires(std::constructible_from<std::string, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, std::string_view delimiter, char prefix, char suffix) noexcept;
```
#### 8)
```cpp
template<std::ranges::input_range Range>
requires(std::constructible_from<std::string, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::string join(Range&& range, char delimiter, char prefix, char suffix) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::vector<std::string_view> strings = {
        "abc",
        "def",
        "ghi"
    };

    std::println("{}", xieite::strings::join(strings, '-'));
}
```
Output:
```
abc-def-ghi
```

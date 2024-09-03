# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:unquote\(\)
Defined in fragment [xieite:strings.unquote](../../../src/strings/unquote.cpp)

&nbsp;

## Description
"Unquotes" a string, removing quotes and escaping escaped characters.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string quote(std::string_view value, char delimiter = '"', char escape = '\\') noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::unquote("\"Something \\\"quoted\\\" and \\\\escaped\""));
}
```
Output:
```
Something "quoted" and \escaped
```

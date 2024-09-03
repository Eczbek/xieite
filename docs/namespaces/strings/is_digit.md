# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:isDigit\(\)
Defined in fragment [xieite:strings.isDigit](../../../src/strings/is_digit.cpp)

&nbsp;

## Description
Checks if a character is a digit.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr bool isDigit(char character) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::isDigit('3'));
}
```
Output:
```
true
```

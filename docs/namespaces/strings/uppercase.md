# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:uppercase\(\)
Defined in fragment [xieite:strings.uppercase](../../../src/strings/uppercase.cpp)

&nbsp;

## Description
Converts a string or character to uppercase. Only handles characters between `a` and `z`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr char uppercase(char character) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::string uppercase(std::string_view string) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::uppercase("hello, world!"));
}
```
Output:
```
HELLO, WORLD!
```

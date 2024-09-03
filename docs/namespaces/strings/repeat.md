# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:repeat\(\)
Defined in fragment [xieite:strings.repeat](../../../src/strings/repeat.cpp)

&nbsp;

## Description
Repeats a string multiple times.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string repeat(std::size_t count, std::string_view string) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::repeat(3, "Hello, world!\n");
}
```
Output:
```
Hello, world!
Hello, world!
Hello, world!
```

# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:truncate\(\)
Defined in fragment [xieite:strings.truncate](../../../src/strings/truncate.cpp)

&nbsp;

## Description
Shortens the end of a string, replacing it with a suffix.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string truncate(std::string_view string, std::size_t length, std::string_view suffix = "") noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::truncate("Hello, world!", 8, "..."));
}
```
Output:
```
Hello...
```

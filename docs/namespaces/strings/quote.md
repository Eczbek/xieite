# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:quote\(\)
Defined in fragment [xieite:strings.quote](../../../src/strings/quote.cpp)

&nbsp;

## Description
Replicates `std::quoted` but without streams and more `constexpr`.

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
    std::println("{}", xieite::strings::quote("Something \"quoted\" and \\escaped"));
}
```
Output:
```
"Something \"quoted\" and \\escaped"
```

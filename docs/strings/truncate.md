# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:truncate
Defined in header [<xieite/strings/truncate.hpp>](../../include/xieite/strings/truncate.hpp)

&nbsp;

## Description
Shortens the end of a string, replacing it with a suffix.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string truncate(const std::string& string, std::size_t length, const std::string& suffix = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/truncate.hpp>

int main() {
    std::cout << xieite::strings::truncate("Hello, world!", 8, "...") << '\n';
}
```
Output:
```
Hello...
```

# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:something
Defined in header [<xieite/strings/something.hpp>](../../include/xieite/strings/something.hpp)

&nbsp;

## Description
What does this do? Not even I know. Do not use this.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr std::string something(const std::string& string) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/something.hpp>

int main() {
    std::cout
        << xieite::strings::something("3aaa") << '\n'
        << xieite::strings::something("11bbbbbbbbbbb") << '\n'
        << xieite::strings::something("0") << '\n';
}
```
Output:
```
aaa
bbbbbbbbbbb

```

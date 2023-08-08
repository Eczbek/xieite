# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:something
Defined in header [<xieite/strings/something.hpp>](../../include/xieite/strings/something.hpp)

&nbsp;

## Description
What does this do?

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
constexpr std::string something(const std::string& string) noexcept;
```
#### Function parameters
- `string` - A `std::string` constant reference, the value to do something with
#### Return type
- `std::string`

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

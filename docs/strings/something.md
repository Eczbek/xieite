# [xieite](../../README.md)::[strings](../strings.md)::something
Defined in header [<xieite/strings/something.hpp>](../../include/xieite/strings/something.hpp)

<br/>

What does this do?

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::string something(std::string_view string) noexcept;
```
### Parameters
- `string` - A `std::string_view` copy, the value to do something with
### Return value
- A `std::string`

<br/><br/>

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

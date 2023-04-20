# `xieite::types::demangle`
Defined in header [`<xieite/types/demangle.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/types/demangle.hpp)

<br/>

Demangles the name of a `std::type_info::name()`. Returns original string if demangling fails.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
inline std::string demangle(std::string_view mangled) noexcept;
```
### Parameters
- `mangled` - A `std::string_view` copy, the mangled type name
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string_view>
#include <xieite/types/demangle.hpp>

template<typename>
struct Type {};

int main() {
	std::string_view typeName = typeid(Type<int>).name();

	std::cout
		<< typeName << '\n'
		<< xieite::types::demangle(typeName) << '\n';
}
```
Possible output:
```
4TypeIiE
Type<int>
```

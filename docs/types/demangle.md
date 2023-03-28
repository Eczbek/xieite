# xieite::types::demangle
Defined in header `<xieite/types/demangle.hpp>`

<br/>

Demangles a `typeid` name. Returns original string if demangling fails.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
inline std::string demangle(std::string_view mangled) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <typeinfo>
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

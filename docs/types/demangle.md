# xieite::types::demangle
Defined in header `<xieite/types/demangle.hpp>`

<br/>

Demangles a `typeid` name. Returns original string if demangling fails.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
inline std::string demangle(const std::string_view mangled) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/types/demangle.hpp>

template<typename T>
struct Type {};

int main() {
	Type<int> value;

	std::cout << typeid(value).name() << '\n'
		<< xieite::types::demangle(typeid(value).name()) << '\n';
}
```
Output:
```
4TypeIiE
Type<int>
```

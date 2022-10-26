# xieite::types::demangle
Declared in `<xieite/types/demangle.hpp>`
```cpp
[[nodiscard]]
std::string demangle(const std::string_view mangled) noexcept;
```
Demangles a `typeid` name.
## Example
```cpp
#include <xieite/types/demangle.hpp>
#include <iostream>

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

# xieite::types::demangle
Declared in `<xieite/types/demangle.hpp>`

<br/>

Demangles a `typeid` name. Returns mangled if cannot demangle.

<br/><br/>

## Declaration
```cpp
[[nodiscard]]
std::string demangle(const std::string_view mangled) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
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

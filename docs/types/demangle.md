# gcufl::types::demangle
Declared in `<gcufl/types/demangle.hpp>`
```cpp
std::string demangle(const std::string_view mangled) noexcept;
```
Demangles a `typeid` name.
## Example
```cpp
#include <gcufl/types/demangle.hpp>
#include <iostream>

template<typename T>
struct Type {};

int main() {
	Type<int> value;

	std::cout << typeid(value).name() << '\n'
		<< gcufl::types::demangle(typeid(value).name()) << '\n';
}
```
Output:
```
4TypeIiE
Type<int>
```

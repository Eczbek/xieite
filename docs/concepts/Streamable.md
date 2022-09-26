# gcufl::concepts::Streamable
Declared in `<gcufl/concepts/Streamable.hpp>`
```cpp
template<typename T>
concept Streamable = requires(std::ostream& ostream, const T& value) {
	{ ostream << value } -> std::convertible_to<std::ostream&>;
};
```
Specifies that a type `T` is streamable.
## Example
```cpp
#include <gcufl/concepts/Streamable>
#include <iostream>

struct UnstreamableType {};

int main() {
	std::cout << std::boolalpha
		<< gcufl::concepts::Streamable<char> << '\n'
		<< gcufl::concepts::Streamable<UnstreamableType> << '\n';
}
```
Output:
```
true
false
```

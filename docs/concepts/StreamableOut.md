# gcufl::concepts::StreamableOut
Declared in `<gcufl/concepts/StreamableOut.hpp>`
```cpp
template<typename T>
concept StreamableOut = requires(std::ostream& outStream, const T& value) {
	{ outStream << value } -> std::convertible_to<std::ostream&>;
};
```
Specifies that a type `T` is ostream-able.
## Example
```cpp
#include <gcufl/concepts/StreamableOut.hpp>
#include <iostream>

struct UnstreamableType {};

int main() {
	std::cout << std::boolalpha
		<< gcufl::concepts::StreamableOut<char> << '\n'
		<< gcufl::concepts::StreamableOut<UnstreamableType> << '\n';
}
```
Output:
```
true
false
```

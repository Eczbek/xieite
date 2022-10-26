# xieite::concepts::StreamableOut
Declared in `<xieite/concepts/StreamableOut.hpp>`
```cpp
template<typename T>
concept StreamableOut = requires(std::ostream& outStream, T value) {
	{ outStream << value } -> std::convertible_to<std::ostream&>;
};
```
Specifies that a type `T` is ostream-able.
## Example
```cpp
#include <iostream>
#include <xieite/concepts/StreamableOut.hpp>

struct UnstreamableType {};

int main() {
	std::cout << std::boolalpha
		<< xieite::concepts::StreamableOut<char> << '\n'
		<< xieite::concepts::StreamableOut<UnstreamableType> << '\n';
}
```
Output:
```
true
false
```

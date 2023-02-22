# xieite::concepts::StreamableOut
Defined in header `<xieite/concepts/StreamableOut.hpp>`

<br/>

Specifies that type `T` is able to be streamed out.

<br/><br/>

## Declaration
```cpp
template<typename T>
concept StreamableOut = requires(std::ostream& outStream, T value) {
	{ outStream << value } -> std::convertible_to<std::ostream&>;
};
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::boolalpha, std::cout
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

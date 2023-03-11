# xieite::concepts::StreamableOutOf
Defined in header `<xieite/concepts/StreamableOutOf.hpp>`

<br/>

Specifies that type `T` is able to be streamed out.

<br/><br/>

## Declarations
```cpp
template<typename T>
concept StreamableOutOf = requires(std::ostream& outStream, T value) {
	{ outStream << value } -> std::convertible_to<std::ostream&>;
};
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::boolalpha, std::cout
#include <xieite/concepts/StreamableOutOf.hpp>

struct UnstreamableType {};

int main() {
	std::cout << std::boolalpha
		<< xieite::concepts::StreamableOutOf<char> << '\n'
		<< xieite::concepts::StreamableOutOf<UnstreamableType> << '\n';
}
```
Output:
```
true
false
```

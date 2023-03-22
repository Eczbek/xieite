# xieite::concepts::StreamableOutOf
Defined in header `<xieite/concepts/StreamableOutOf.hpp>`

<br/>

Specifies that type `Any` is able to be streamed out.

<br/><br/>

## Declarations
```cpp
template<typename Any>
concept StreamableOutOf = requires(std::ostream& outStream, Any value) {
	{ outStream << value } -> std::convertible_to<std::ostream&>;
};
```

<br/><br/>

## Example
```cpp
#include <iostream>
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

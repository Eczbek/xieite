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

struct Unstreamable {};

int main() {
	std::cout << std::boolalpha
		<< xieite::concepts::StreamableOutOf<char> << '\n'
		<< xieite::concepts::StreamableOutOf<Unstreamable> << '\n';
}
```
Output:
```
true
false
```

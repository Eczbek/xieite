# [xieite](../../README.md)::[concepts](../concepts.md)::StreamableOutOf
Defined in header [<xieite/concepts/StreamableOutOf.hpp>](../../include/xieite/concepts/StreamableOutOf.hpp)

<br/>

Specifies that a type can be "streamed" out of

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept StreamableOutOf = requires(std::ostream& outStream, Any value) {
	{ outStream << value } -> std::convertible_to<std::ostream&>;
};
```
### Template parameters
- `Any` - Any type

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/concepts/StreamableOutOf.hpp>

struct Unstreamable {};

int main() {
	std::cout
		<< std::boolalpha
		<< xieite::concepts::StreamableOutOf<char>
		<< '\n'
		<< xieite::concepts::StreamableOutOf<Unstreamable>
		<< '\n';
}
```
Output:
```
true
false
```

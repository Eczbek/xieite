# [xieite](../xieite.md)::[concepts](../concepts.md)::StreamableOut
Defined in header [<xieite/concepts/StreamableOut.hpp>](../../include/xieite/concepts/StreamableOut.hpp)

<br/>

Specifies that a type can be "streamed" out of

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept StreamableOut = requires(std::ostream& outputStream, Any value) {
	{ outputStream << value } -> std::convertible_to<std::ostream&>;
};
```
### Template parameters
- `Any` - Any type

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/concepts/StreamableOut.hpp>

struct Unstreamable {};

int main() {
	std::cout
		<< std::boolalpha
		<< xieite::concepts::StreamableOut<char> << '\n'
		<< xieite::concepts::StreamableOut<Unstreamable> << '\n';
}
```
Output:
```
true
false
```

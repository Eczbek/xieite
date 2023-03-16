# xieite::concepts::StreamableInto
Defined in header `<xieite/concepts/StreamableInto.hpp>`

<br/>

Specifies that type `Any` is able to be streamed into.

<br/><br/>

## Declarations
```cpp
template<typename Any>
concept StreamableInto = requires(std::istream& inStream, Any value) {
	{ inStream >> value } -> std::convertible_to<std::istream&>;
};
```

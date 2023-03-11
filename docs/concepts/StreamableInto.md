# xieite::concepts::StreamableInto
Defined in header `<xieite/concepts/StreamableInto.hpp>`

<br/>

Specifies that type `T` is able to be streamed into.

<br/><br/>

## Declarations
```cpp
template<typename T>
concept StreamableInto = requires(std::istream& inStream, T value) {
	{ inStream >> value } -> std::convertible_to<std::istream&>;
};
```

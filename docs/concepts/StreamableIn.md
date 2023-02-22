# xieite::concepts::StreamableIn
Defined in header `<xieite/concepts/StreamableIn.hpp>`

<br/>

Specifies that type `T` is able to be streamed into.

<br/><br/>

## Declaration
```cpp
template<typename T>
concept StreamableIn = requires(std::istream& inStream, T value) {
	{ inStream >> value } -> std::convertible_to<std::istream&>;
};
```

# xieite::concepts::StreamableIn
Declared in `<xieite/concepts/StreamableIn.hpp>`
```cpp
template<typename T>
concept StreamableIn = requires(std::istream& inStream, T value) {
	{ inStream >> value } -> std::convertible_to<std::istream&>;
};
```
Specifies that a type `T` is istream-able.

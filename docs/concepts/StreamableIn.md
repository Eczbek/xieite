# gcufl::concepts::StreamableIn
Declared in `<gcufl/concepts/StreamableIn.hpp>`
```cpp
template<typename T>
concept StreamableOut = requires(std::istream& inStream, T value) {
	{ inStream >> value } -> std::convertible_to<std::istream&>;
};
```
Specifies that a type `T` is istream-able.

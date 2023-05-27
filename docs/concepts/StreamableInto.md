# [xieite](../../README.md)::[concepts](../concepts.md)::StreamableInto
Defined in header [<xieite/concepts/StreamableInto.hpp>](../../include/xieite/concepts/StreamableInto.hpp)

<br/>

Specifies that a type can be "streamed" into

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept StreamableInto = requires(std::istream& inStream, Any value) {
	{ inStream >> value } -> std::convertible_to<std::istream&>;
};
```
### Template parameters
- `Any` - Any type

# [`xieite`](../../README.md)`::`[`concepts`](../../docs/concepts.md)`::StreamableInto`
Defined in header [`<xieite/concepts/StreamableInto.hpp>`](../../include/xieite/concepts/StreamableInto.hpp)

<br/>

Specifies that type `Any` has defined a `friend operator>>(std::istream&, Any)`.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<typename Any>
concept StreamableInto = requires(std::istream& inStream, Any value) {
	{ inStream >> value } -> std::convertible_to<std::istream&>;
};
```
### Template parameters
- `Any` - Any type

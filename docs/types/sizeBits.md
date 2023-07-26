# [xieite](../xieite.md)::[types](../types.md)::sizeBits
Defined in header [<xieite/types/sizeBits.hpp>](../../include/xieite/types/sizeBits.hpp)

<br/>

Defines number of bits in a type

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
inline constexpr std::size_t sizeBits = sizeof(Any) * xieite::system::bitsPerByte;
```
### Template parameters
- `Any` - Any type

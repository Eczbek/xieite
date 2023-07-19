# [xieite](../xieite.md)::[types](../types.md)::bits
Defined in header [<xieite/types/bits.hpp>](../../include/xieite/types/bits.hpp)

<br/>

The number of bits in a type

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
inline constexpr std::size_t bits = sizeof(Any) * CHAR_BIT;
```
### Template parameters
- `Any` - Any type

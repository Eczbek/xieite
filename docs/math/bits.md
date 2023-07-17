# [xieite](../xieite.md)::[math](../math.md)::bits
Defined in header [<xieite/math/bits.hpp>](../../include/xieite/math/bits.hpp)

<br/>

The number of bits in an integer type

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral>
inline constexpr std::size_t bits = std::numeric_limits<Integral>::digits + std::numeric_limits<Integral>::is_signed;
```
### Template parameters
- `Integral` - A type satisfying `std::integral`


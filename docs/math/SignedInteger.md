# [xieite](../xieite.md)::[math](../math.md)::SignedInteger
Defined in header [<xieite/math/SignedInteger.hpp>](../../include/xieite/math/SignedInteger.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral, bool sign>
using SignedInteger = std::conditional_t<sign, std::make_signed_t<Integral>, std::make_unsigned_t<Integral>>;
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`
- `sign` - A `bool` copy, whether or not the type should be signed
### Resulting value
- A conditionally signed integral type

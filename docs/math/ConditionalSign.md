# [xieite](../xieite.md)::[math](../math.md)::ConditionalSign
Defined in header [<xieite/math/ConditionalSign.hpp>](../../include/xieite/math/ConditionalSign.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral, bool sign>
using ConditionalSign = std::conditional_t<sign, std::make_signed_t<Integral>, std::make_unsigned_t<Integral>>;
```
### Template parameters
- `Integral` - An integral type satisfying `std::integral`
- `sign` - A `bool`, whether or not the type should be signed
### Resulting type
- A conditionally signed integral type

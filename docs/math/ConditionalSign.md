# [xieite](../xieite.md)\:\:[math](../math.md)\:\:ConditionalSign
Defined in header [<xieite/math/ConditionalSign.hpp>](../../include/xieite/math/ConditionalSign.hpp)

&nbsp;

## Synopsis
```cpp
template<std::integral Integer, bool sign>
using ConditionalSign = std::conditional_t<sign, std::make_signed_t<Integer>, std::make_unsigned_t<Integer>>;
```
#### Template parameters
- `Integer` - An integral type satisfying `std::integral`
- `sign` - A `bool`, whether or not the type should be signed
#### Resulting type
- conditionally signed integral type

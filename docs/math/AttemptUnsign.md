# [xieite](../xieite.md)::[math](../math.md)::AttemptUnsign
Defined in header [<xieite/math/AttemptUnsign.hpp>](../../include/xieite/math/AttemptUnsign.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
using AttemptUnsign = std::conditional_t<std::signed_integral<Any>, std::make_unsigned<Any>, std::type_identity<Any>>::type;
```
### Template parameters
- `Any` - Any type
### Resulting type
- If `Any` satisfies `std::signed_integral`, then its unsigned variant, otherwise `Any`

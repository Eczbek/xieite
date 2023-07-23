# [xieite](../xieite.md)::[math](../math.md)::AttemptSign
Defined in header [<xieite/math/AttemptSign.hpp>](../../include/xieite/math/AttemptSign.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
using AttemptSign = std::conditional_t<std::unsigned_integral<Any>, std::make_signed<Any>, std::type_identity<Any>>::type;
```
### Template parameters
- `Any` - Any type
### Resulting type
- If `Any` satisfies `std::unsigned_integral`, then its signed variant, otherwise `Any`

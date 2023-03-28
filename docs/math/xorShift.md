# xieite::math::xorShift
Defined in header `<xieite/math/xorShift.hpp>`

<br/>

Returns the XOR of a value and the value shifted right.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number xorShift(Number value, int bits) noexcept;
```
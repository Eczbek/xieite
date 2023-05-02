# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::xorShift`
Defined in header [`<xieite/math/xorShift.hpp>`](../../include/xieite/math/xorShift.hpp)

<br/>

Returns the XOR of a value and the value shifted right.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number xorShift(Number value, int bits) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number` copy
- `bits` - An `int` copy, the number of bits to shift to the right
### Return value
- A `Number`

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)

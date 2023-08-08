# [xieite](../xieite.md)\:\:[math](../math.md)\:\:xorShift
Defined in header [<xieite/math/xorShift.hpp>](../../include/xieite/math/xorShift.hpp)

&nbsp;

## Description
Returns the XOR of a value and the value shifted right

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr Arithmetic xorShift(Arithmetic value, std::size_t bits) noexcept;
```
#### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `value` - An `Arithmetic`
- `bits` - A `std::size_t`, the number of bits to shift to the right
#### Return type
- `Arithmetic`

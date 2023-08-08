# [xieite](../xieite.md)\:\:[math](../math.md)\:\:logarithm
Defined in header [<xieite/math/logarithm.hpp>](../../include/xieite/math/logarithm.hpp)

&nbsp;

## Description
Takes the logarithm of a value of any base

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic1, Arithmetic2> logarithm(const Arithmetic1 base, const Arithmetic2 value) noexcept;
```
#### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `base` - An `Arithmetic1`
- `value` - An `Arithmetic2`
#### Return type
- `xieite::math::Result` of `Arithmetic1` and `Arithmetic2`

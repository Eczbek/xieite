# [xieite](../../../README.md)::[math](../../math.md)::[Integer<bits, sign>](../Integer.md)::operator typename
Defined in header [<xieite/math/Integer.hpp>](../../../include/xieite/math/Integer.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr operator Integral() const noexcept;
```

<br/><br/>

```cpp
template<std::size_t integerBits, bool integerSign>
[[nodiscard]]
constexpr operator xieite::math::Integer<integerBits, integerSign>() const noexcept;
```

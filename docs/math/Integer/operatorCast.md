# `xieite::math::Integer<bits, sign>::operator typename`
Defined in header [`<xieite/math/Integer.hpp>`](../../../include/xieite/math/Integer.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr operator Integral() const noexcept;
```

<br/>

```cpp
template<std::size_t integerBits, bool integerSign>
[[nodiscard]]
constexpr operator xieite::math::Integer<integerBits, integerSign>() const noexcept;
```

<br/><br/>

## See also
- [`xieite::math::Integer`](../../../docs/math/Integer.md)

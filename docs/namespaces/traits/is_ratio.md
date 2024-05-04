# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsRatio\<\> \{\}
Defined in header [<xieite/traits/is_ratio.hpp>](../../../include/xieite/traits/is_ratio.hpp)

&nbsp;

## [Description](../concepts/ratio.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
struct IsRatio
: std::false_type {};
```
#### 2)
```cpp
template<std::intmax_t numerator_, std::intmax_t denominator_>
struct IsRatio<std::ratio<numerator_, denominator_>>
: std::true_type {};
```

&nbsp;

## [Example](../concepts/ratio.md#Example)

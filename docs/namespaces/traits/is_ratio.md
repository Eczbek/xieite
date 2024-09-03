# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsRatio\<\> \{\}
Defined in fragment [xieite:traits.IsRatio](../../../src/traits/is_ratio.cpp)

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
template<std::intmax_t numerator, std::intmax_t denominator>
struct IsRatio<std::ratio<numerator, denominator>>
: std::true_type {};
```

&nbsp;

## [Example](../concepts/ratio.md#Example)

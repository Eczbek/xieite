# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDuration\<\> \{\}
Defined in header [<xieite/traits/is_duration.hpp>](../../../include/xieite/traits/is_duration.hpp)

&nbsp;

## [Description](../concepts/duration.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
struct IsDuration
: std::false_type {};
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Ration Ratio>
struct IsDuration<std::chrono::duration<Arithmetic, Ratio>>
: std::true_type {};
```

&nbsp;

## [Example](../concepts/duration.md#Example)

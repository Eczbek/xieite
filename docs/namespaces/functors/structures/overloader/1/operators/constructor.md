# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Overloader<Derivables_...>](../../../../overloader.md)\:\:Overloader\(\)
Defined in header [<xieite/functors/overloader.hpp>](../../../../../../../include/xieite/functors/overloader.hpp)

&nbsp;

## Description
Constructs a `xieite::functors::Overloader<Derivables_...>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Overloader() noexcept;
```
#### 2)
```cpp
template<typename... DerivableReferences_>
requires((... && std::convertible_to<DerivableReferences_, Derivables_>))
constexpr Overloader(DerivableReferences_&&... callbacks) noexcept;
```

&nbsp;

## [Example](../../../../overloader.md#Example)

# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Overloader<Derivables...>](../../../../overloader.md)\:\:Overloader\(\)
Defined in header [<xieite/functors/overloader.hpp>](../../../../../../../include/xieite/functors/overloader.hpp)

&nbsp;

Constructs a `xieite::functors::Overloader`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Overloader() noexcept;
```
#### 2)
```cpp
template<typename... DerivableReferences>
requires((... && std::convertible_to<DerivableReferences, Derivables>))
constexpr Overloader(DerivableReferences&&... callbacks) noexcept;
```

&nbsp;

## [Example](../../../../overloader.md#Example)

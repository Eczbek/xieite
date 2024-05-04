# [xieite](../../../../../../xieite.md)\:\:[memory](../../../../../../memory.md)\:\:[Shredder<Type_>](../../../../shredder.md)\:\:Shredder\<\>\(\)
Defined in header [<xieite/memory/shredder.hpp>](../../../../../../../include/xieite/memory/shredder.hpp)

&nbsp;

## Description
Constructs a `xieite::memory::Shredder<Type_>`. The default constructor automatically shreds claimed memory.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Shredder() noexcept;
```
#### 2)
```cpp
template<typename... Arguments_>
requires(std::constructible_from<Type_, Arguments_...>)
constexpr Shredder(Arguments_&&... arguments) noexcept;
```

&nbsp;

## [Example](../../../../shredder.md#Example)

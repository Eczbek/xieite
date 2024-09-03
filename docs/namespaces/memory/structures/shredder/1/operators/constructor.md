# [xieite](../../../../../../xieite.md)\:\:[memory](../../../../../../memory.md)\:\:[Shredder<Type>](../../../../shredder.md)\:\:Shredder\<\>\(\)
Defined in fragment [xieite:memory.Shredder](../../../../../../../src/memory/shredder.cpp)

&nbsp;

## Description
Constructs a `xieite::memory::Shredder<Type>`. The default constructor automatically shreds claimed memory.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Shredder() noexcept;
```
#### 2)
```cpp
template<typename... Arguments>
requires(std::constructible_from<Type, Arguments...>)
constexpr Shredder(Arguments&&... arguments) noexcept;
```

&nbsp;

## [Example](../../../../shredder.md#Example)

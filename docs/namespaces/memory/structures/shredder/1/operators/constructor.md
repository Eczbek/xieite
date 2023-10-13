# [xieite](../../../../../xieite.md)\:\:[memory](../../../../../memory.md)\:\:[Shredder\<Type\>](../../../shredder.md)\:\:Shredder
Defined in header [<xieite/memory/shredder.hpp>](../../../../../../../include/xieite/memory/shredder.hpp)

&nbsp;

## Description
Constructs a `xieite::memory::Shredder`.

&nbsp;

## Synopses
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

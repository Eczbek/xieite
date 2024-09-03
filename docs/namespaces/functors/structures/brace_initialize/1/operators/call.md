# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[BraceInitialize<Target>](../../../../brace_initialize.md)\:\:operator\(\)\<\>\(\)
Defined in fragment [xieite:functors.BraceInitialize](../../../../../../../src/functors/brace_initialize.cpp)

&nbsp;

## Description
Brace-initializes `Type` with `Arguments...`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Arguments>
requires(xieite::concepts::BraceInitializable<Type, Arguments...>)
[[nodiscard]] constexpr Type operator()(Arguments&&... arguments) const
noexcept(xieite::concepts::NoThrowBraceInitializable<Type, Arguments...>);
```

&nbsp;

## [Example](../../../../brace_initialize.md#Example)

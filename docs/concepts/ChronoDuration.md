# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:ChronoDuration
Defined in header [<xieite/concepts/ChronoDuration.hpp>](../../include/xieite/concepts/ChronoDuration.hpp)

&nbsp;

## Description
Specifies that a type is a `std::chrono::duration`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept ChronoDuration = xieite::traits::IsChronoDuration<Type>::value;
```

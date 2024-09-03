# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Invocable\<\>
Defined in fragment [xieite:concepts.Invocable](../../../src/concepts/invocable.cpp)

&nbsp;

## Description
Specifies that a type is invocable with arguments and returns a type; basically a wrapper for `std::is_invocable_r_v`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Invocable, typename Signature>
concept Invocable = xieite::traits::IsInvocable<Invocable, Signature>::value;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_invocable#Examples)

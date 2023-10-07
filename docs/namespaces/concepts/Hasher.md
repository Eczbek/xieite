# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Hasher
Defined in header [<xieite/concepts/Hasher.hpp>](../../../include/xieite/concepts/Hasher.hpp)

&nbsp;

## Description
Specifies that a type is a functor for hashing values.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, typename Argument>
concept Hasher = requires(Type hasher, Argument value) {
    { std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
};
```

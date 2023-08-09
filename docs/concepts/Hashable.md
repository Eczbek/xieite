# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Hashable
Defined in header [<xieite/concepts/Hashable.hpp>](../../include/xieite/concepts/Hashable.hpp)

&nbsp;

## Description
Specifies that a type is hashable.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, typename Hasher = std::hash<Type>>
concept Hashable = requires(Type value, Hasher hasher) {
    { std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
};
```

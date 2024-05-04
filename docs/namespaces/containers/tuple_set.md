# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:TupleSet \{\}
Defined in header [<xieite/containers/tuple_set.hpp>](../../../include/xieite/containers/tuple_set.hpp)

&nbsp;

## Description
A wrapper for `std::unordered_set` which allows indexing with tuples.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename> typename, typename>
struct TupleSet;
```
#### 2)
```cpp
template<template<typename> typename Container_, typename FirstKey_, typename... RestKeys_>
struct TupleSet<Container_, std::tuple<FirstKey_, RestKeys_...>> {
    constexpr TupleSet(const std::initializer_list<std::pair<FirstKey_, TupleSet<Container_, std::tuple<RestKeys_...>>>> = {}) noexcept;

    template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
    constexpr bool operator[](KeysReference_&&) const;

    template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
    constexpr void insert(KeysReference_&&);

    template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
    constexpr bool contains(KeysReference_&&) const;
};
```
- [TupleSet\(\)](./structures/tuple_set/2/operators/constructor.md)
- [operator\[\]\(\)](./structures/tuple_set/2/operators/array_subscript.md)
- [insert\(\)](./structures/tuple_set/2/insert.md)
- [contains\(\)](./structures/tuple_set/2/contains.md)
#### 3)
```cpp
template<template<typename> typename Container_, typename Key_>
struct TupleSet<Container_, std::tuple<Key_>> {
    constexpr TupleSet(const std::initializer_list<Key_> = {}) noexcept;

    template<std::convertible_to<std::tuple<Key_>> KeyReference_>
    constexpr bool operator[](KeyReference_&&) const;

    template<std::convertible_to<std::tuple<Key_>> KeyReference_>
    constexpr void insert(KeyReference_&&);

    template<std::convertible_to<std::tuple<Key_>> KeyReference_>
    constexpr bool contains(KeyReference_&&) const;
};
```
- [TupleSet\(\)](./structures/tuple_set/3/operators/constructor.md)
- [operator\[\]\(\)](./structures/tuple_set/3/operators/array_subscript.md)
- [insert\(\)](./structures/tuple_set/3/insert.md)
- [contains\(\)](./structures/tuple_set/3/contains.md)

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include <unordered_set>
#include "xieite/containers/tuple_set.hpp"

int main() {
    using TupleSet = xieite::containers::TupleSet<std::unordered_set, std::tuple<int, char>>;

    TupleSet map = {
        { 5, 'h' },
        { 7, '4' },
        { -23, 'L' },
        { 418, ' ' }
    };

    std::println("{}", map[std::make_tuple(-23, 'L')]);
    std::println("{}", map[std::make_tuple(999, 'a')]);
}
```
Output:
```
true
false
```

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
template<template<typename> typename Container, typename FirstKey, typename... RestKeys>
struct TupleSet<Container, std::tuple<FirstKey, RestKeys...>> {
    constexpr TupleSet(const std::initializer_list<std::pair<FirstKey, TupleSet<Container, std::tuple<RestKeys...>>>> = {}) noexcept;

    template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
    constexpr bool operator[](KeysReference&&) const;

    template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
    constexpr void insert(KeysReference&&);

    template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
    constexpr bool contains(KeysReference&&) const;
};
```
- [TupleSet\(\)](./structures/tuple_set/2/operators/constructor.md)
- [operator\[\]\(\)](./structures/tuple_set/2/operators/array_subscript.md)
- [insert\(\)](./structures/tuple_set/2/insert.md)
- [contains\(\)](./structures/tuple_set/2/contains.md)
#### 3)
```cpp
template<template<typename> typename Container, typename Key>
struct TupleSet<Container, std::tuple<Key>> {
    constexpr TupleSet(const std::initializer_list<Key> = {}) noexcept;

    template<std::convertible_to<std::tuple<Key>> KeyReference>
    constexpr bool operator[](KeyReference&&) const;

    template<std::convertible_to<std::tuple<Key>> KeyReference>
    constexpr void insert(KeyReference&&);

    template<std::convertible_to<std::tuple<Key>> KeyReference>
    constexpr bool contains(KeyReference&&) const;
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

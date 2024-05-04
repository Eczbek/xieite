# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:TupleMap \{\}
Defined in header [<xieite/containers/tuple_map.hpp>](../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
A map which uses `std::tuple`s as keys, without combining the hashes of the tuple's elements together.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename, typename> typename, typename, typename>
struct TupleMap;
```
#### 2)
```cpp
template<template<typename, typename> typename Container_, typename Value_, typename FirstKey_, typename... RestKeys_>
struct TupleMap<Container_, std::tuple<FirstKey_, RestKeys_...>, Value_> {
    constexpr TupleMap(std::initializer_list<std::pair<FirstKey_, TupleMap<std::tuple<RestKeys_...>, Value_>>> = {}) noexcept;

    template<typename Self_>
    constexpr auto&& operator[](this Self_&&, const std::tuple<FirstKey_, RestKeys_...>&);

    template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_, std::convertible_to<Value_> ValueReference_>
    constexpr void insert(KeysReference_&&, ValueReference_&&);

    template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
    constexpr bool contains(KeysReference_&&) const;
};
```
- [TupleMap\(\)](./structures/tuple_map/2/operators/constructor.md)
- [operator\[\]\(\)](./structures/tuple_map/2/operators/array_subscript.md)
- [insert\(\)](./structures/tuple_map/2/insert.md)
- [contains\(\)](./structures/tuple_map/2/contains.md)
#### 3)
```cpp
template<template<typename, typename> typename Container_, typename Value_, typename Key_>
struct TupleMap<Container_, std::tuple<Key_>, Value_> {
    constexpr TupleMap(std::initializer_list<std::pair<Key_, Value_>> = {}) noexcept;

    template<typename Self_, std::convertible_to<std::tuple<Key_>> KeyReference_>
    constexpr auto&& operator[](this Self_&&, KeyReference_&&);

    template<std::convertible_to<std::tuple<Key_>> KeyReference_, std::convertible_to<Value_> ValueReference_>
    constexpr void insert(KeyReference_&&, ValueReference_&&);

    template<std::convertible_to<std::tuple<Key_>> KeyReference_>
    constexpr bool contains(KeyReference_&&) const;
};
```
- [TupleMap\(\)](./structures/tuple_map/3/operators/constructor.md)
- [operator\[\]\(\)](./structures/tuple_map/3/operators/array_subscript.md)
- [insert\(\)](./structures/tuple_map/3/insert.md)
- [contains\(\)](./structures/tuple_map/3/contains.md)

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include <unordered_map>
#include "xieite/containers/tuple_map.hpp"

int main() {
    using TupleMap = xieite::containers::TupleMap<std::unordered_map, std::tuple<int, char>, double>;

    TupleMap map = {
        { 5, {
            { 'h', 3.14159 },
            { '4', 2.71828 }
        } },
        { -23, {
            { 'L', 6.28318 },
            { ' ', 0.33333 }
        } }
    };

    std::println("{}", map[std::make_tuple(5, 'h')]);
}
```
Output:
```
3.14159
```

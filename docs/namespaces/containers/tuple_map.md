# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:TupleMap \{\}
Defined in fragment [xieite:containers.TupleMap](../../../src/containers/tuple_map.cpp)

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
template<template<typename, typename> typename Container, typename Value, typename FirstKey, typename... RestKeys>
struct TupleMap<Container, std::tuple<FirstKey, RestKeys...>, Value> {
    constexpr TupleMap(std::initializer_list<std::pair<FirstKey, TupleMap<std::tuple<RestKeys...>, Value>>> = {}) noexcept;

    template<typename Self>
    constexpr auto operator[](this Self&&, const std::tuple<FirstKey, RestKeys...>&)
    XIEITE_ARROW(/* ... */)

    template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference, std::convertible_to<Value> ValueReference>
    constexpr auto insert(KeysReference&&, ValueReference&&)
    XIEITE_ARROW(/* ... */)

    template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
    constexpr auto contains(KeysReference&&) const
    XIEITE_ARROW(/* ... */)
};
```
- [TupleMap\(\)](./structures/tuple_map/2/operators/constructor.md)
- [operator\[\]\(\)](./structures/tuple_map/2/operators/array_subscript.md)
- [insert\(\)](./structures/tuple_map/2/insert.md)
- [contains\(\)](./structures/tuple_map/2/contains.md)
#### 3)
```cpp
template<template<typename, typename> typename Container, typename Value, typename Key>
struct TupleMap<Container, std::tuple<Key>, Value> {
    constexpr TupleMap(std::initializer_list<std::pair<Key, Value>> = {}) noexcept;

    template<typename Self, std::convertible_to<std::tuple<Key>> KeyReference>
    constexpr auto operator[](this Self&&, KeyReference&&)
    XIEITE_ARROW(/* ... */)

    template<std::convertible_to<std::tuple<Key>> KeyReference, std::convertible_to<Value> ValueReference>
    constexpr auto insert(KeyReference&&, ValueReference&&)
    XIEITE_ARROW(/* ... */)

    template<std::convertible_to<std::tuple<Key>> KeyReference>
    constexpr auto contains(KeyReference&&) const
    XIEITE_ARROW(/* ... */)
};
```
- [TupleMap\(\)](./structures/tuple_map/3/operators/constructor.md)
- [operator\[\]\(\)](./structures/tuple_map/3/operators/array_subscript.md)
- [insert\(\)](./structures/tuple_map/3/insert.md)
- [contains\(\)](./structures/tuple_map/3/contains.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

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

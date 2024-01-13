# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:TupleMap
Defined in header [<xieite/containers/tuple_map.hpp>](../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
A thing.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename, typename>
struct TupleMap;
```
#### 2)
```cpp
template<typename Value, typename FirstKey, typename... RestKeys>
struct TupleMap<std::tuple<FirstKey, RestKeys...>, Value> {
    TupleMap(std::initializer_list<std::pair<FirstKey, TupleMap<std::tuple<RestKeys...>, Value>>> = {});

    const Value& operator[](const std::tuple<FirstKey, RestKeys...>&) const;

    Value& operator[](const std::tuple<FirstKey, RestKeys...>&);

    void insert(const std::tuple<FirstKey, RestKeys...>&, const Value&);

    bool contains(const std::tuple<FirstKey, RestKeys...>&) const;
};
```
##### Member functions
- [TupleMap](./structures/tuple_map/2/operators/constructor.md)
- [operator\[\]](./structures/tuple_map/2/operators/array_subscript.md)
- [insert](./structures/tuple_map/2/insert.md)
- [contains](./structures/tuple_map/2/contains.md)
#### 3)
```cpp
template<typename Value, typename Key>
struct TupleMap<std::tuple<Key>, Value> {
    TupleMap(std::initializer_list<std::pair<Key, Value>> = {});

    const Value& operator[](const std::tuple<Key>&) const;

    Value& operator[](const std::tuple<Key>&);

    void insert(const std::tuple<Key>&, const Value&);

    bool contains(const std::tuple<Key>&) const;
};
```
##### Member functions
- [TupleMap](./structures/tuple_map/3/operators/constructor.md)
- [operator\[\]](./structures/tuple_map/3/operators/array_subscript.md)
- [insert](./structures/tuple_map/3/insert.md)
- [contains](./structures/tuple_map/3/contains.md)

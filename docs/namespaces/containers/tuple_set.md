# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:TupleSet
Defined in header [<xieite/containers/tuple_set.hpp"](../../../include/xieite/containers/tuple_set.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<template<typename> typename, typename>
struct TupleSet;
```
#### 2)
```cpp
template<template<typename> typename Container, typename FirstKey, typename... RestKeys>
struct TupleSet<Container, std::tuple<FirstKey, RestKeys...>> {
    TupleSet(std::initializer_list<std::pair<FirstKey, TupleSet<std::tuple<RestKeys...>>>> = {});

    const bool operator[](const std::tuple<FirstKey, RestKeys...>&) const;

    void insert(const std::tuple<FirstKey, RestKeys...>&);

    bool contains(const std::tuple<FirstKey, RestKeys...>&) const;
};
```
##### Member functions
- [TupleSet](./structures/tuple_set/2/operators/constructor.md)
- [operator\[\]](./structures/tuple_set/2/operators/array_subscript.md)
- [insert](./structures/tuple_set/2/insert.md)
- [contains](./structures/tuple_set/2/contains.md)
#### 3)
```cpp
template<template<typename> typename Container, typename Key>
struct TupleSet<Container, std::tuple<Key>> {
    TupleSet(std::initializer_list<Key> = {});

    const bool operator[](const std::tuple<Key>&) const;

    void insert(const std::tuple<Key>&);

    bool contains(const std::tuple<Key>&) const;
};
```
##### Member functions
- [TupleSet](./structures/tuple_set/3/operators/constructor.md)
- [operator\[\]](./structures/tuple_set/3/operators/array_subscript.md)
- [insert](./structures/tuple_set/3/insert.md)
- [contains](./structures/tuple_set/3/contains.md)

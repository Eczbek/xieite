# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<FirstKey, RestKeys...>, Value>](../../../tuple_map.md)\:\:insert
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Assigns a value to a specific combination of keys.

&nbsp;

## Synopses
#### 1)
```cpp
void insert(const std::tuple<FirstKey, RestKeys...>& keys, const Value& value) noexcept;
```

# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<Key>, Value>](../../../../tuple_map.md)\:\:operator\[\]
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Extracts a value by a key.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] const Value& operator[](const std::tuple<Key>& key) const noexcept;
```
#### 2)
```cpp
[[nodiscard]] Value& operator[](const std::tuple<Key>& key) noexcept;
```

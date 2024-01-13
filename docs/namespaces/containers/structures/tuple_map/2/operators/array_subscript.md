# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleMap<std::tuple<FirstKey, RestKeys...>, Value>](../../../../tuple_map.md)\:\:operator\[\]
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Extracts a value by a specific combination of keys.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] const Value& operator[](const std::tuple<FirstKey, RestKeys...>& keys) const noexcept;
```
#### 2)
```cpp
[[nodiscard]] Value& operator[](const std::tuple<FirstKey, RestKeys...>& keys) noexcept;
```

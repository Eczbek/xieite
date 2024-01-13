# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleMap<std::tuple<FirstKey, RestKeys...>, Value>](../../../tuple_map.md)\:\:contains
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Checks if a value exists by a specific combination of keys.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] bool contains(const std::tuple<FirstKey, RestKeys...>& keys) const noexcept;
```

# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[MemoMap<Value, FirstKey, RestKeys...>](../../../memo_map.md)\:\:get
Defined in header [<xieite/functors/memo_map.hpp>](../../../../../../include/xieite/functors/memo_map.hpp)

&nbsp;

## Description
Extracts a value by a specific combination of keys.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] const Value& get(FirstKey&& firstKey, RestKeys&&... restKeys) const noexcept;
```

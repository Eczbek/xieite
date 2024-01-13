# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[MemoMap<Value, FirstKey, RestKeys...>](../../../memo_map.md)\:\:has
Defined in header [<xieite/functors/memo_map.hpp>](../../../../../../include/xieite/functors/memo_map.hpp)

&nbsp;

## Description
Checks if a value exists by a specific combination of keys.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] bool has(FirstKey&& firstKey, RestKeys&&... restKeys) const noexcept;
```

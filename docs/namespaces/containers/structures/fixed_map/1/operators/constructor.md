# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedMap<Key, Value, size, Hash, KeyEqual, Allocator>](../../../../map.md)\:\:FixedMap
Defined in header [<xieite/containers/fixed_map.hpp>](../../../../../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

Constructs a `xieite::containers::FixedMap`.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr Map() noexcept;
```
#### 2)
```cpp
template<std::ranges::range Range>
constexpr Map(const Range& entries) noexcept;
```
#### 3)
```cpp
constexpr Map(std::initializer_list<std::pair<Key, Value>> entries) noexcept;
```

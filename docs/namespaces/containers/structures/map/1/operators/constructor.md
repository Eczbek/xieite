# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Map<Key, Value, size, Hash, KeyEqual, Allocator>](../../../../map.md)\:\:Map
Defined in header [<xieite/containers/map.hpp>](../../../../../../../include/xieite/containers/map.hpp)

&nbsp;

Constructs a `xieite::containers::Map`.

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

# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedSet<Key, size, Hash, KeyEqual, Allocator>](../../../../fixed_set.md)\:\:FixedSet
Defined in header [<xieite/containers/fixed_set.hpp"](../../../../../../../include/xieite/containers/fixed_set.hpp)

&nbsp;

Constructs a `xieite::containers::FixedSet`.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr Set() noexcept;
```
#### 2)
```cpp
template<std::ranges::range Range>
constexpr Set(const Range& entries) noexcept;
```
#### 3)
```cpp
constexpr Set(std::initializer_list<Key> entries) noexcept;
```

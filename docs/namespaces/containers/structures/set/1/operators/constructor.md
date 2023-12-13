# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Set<Key, size, Hash, KeyEqual, Allocator>](../../../../set.md)\:\:Set
Defined in header [<xieite/containers/set.hpp>](../../../../../../../include/xieite/containers/set.hpp)

&nbsp;

Constructs a `xieite::containers::Set`.

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

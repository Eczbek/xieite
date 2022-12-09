# xieite::containers::OrderedMap
Declared in `<xieite/containers/OrderedMap.hpp>`

<br/>

An map for storing values under orderable keys.

<br/><br/>

## Constructor
```cpp
constexpr OrderedMap() noexcept = default;
```

## Operators
```cpp
constexpr V& operator[](const K key) noexcept;
```
```cpp
constexpr const V& operator[](const K key) const noexcept;
```

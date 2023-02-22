# xieite::containers::OrderedMap
Defined in header `<xieite/containers/OrderedMap.hpp>`

<br/>

An map for storing values by orderable keys. Expects keys type to be convertible to `std::size_t`.

<br/><br/>

## Template Parameters
```cpp
template<std::convertible_to<std::size_t> K, typename V>
```

## Constructor
```cpp
constexpr OrderedMap() noexcept = default;
```

## Operators
```cpp
[[nodiscard]]
constexpr V& operator[](const K key) noexcept;
```
```cpp
[[nodiscard]]
constexpr const V& operator[](const K key) const noexcept;
```

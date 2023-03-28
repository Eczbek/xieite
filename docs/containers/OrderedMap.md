# xieite::containers::OrderedMap
Defined in header `<xieite/containers/OrderedMap.hpp>`

<br/>

An map for storing values by orderable keys. Expects keys type to be convertible to `std::size_t`.

<br/><br/>

## Template Parameters
```cpp
template<std::convertible_to<std::size_t> Key, typename Value>
```

## Constructors
```cpp
constexpr OrderedMap() noexcept = default;
```

## Operators
```cpp
[[nodiscard]]
constexpr Value& operator[](Key key) noexcept;
```
```cpp
[[nodiscard]]
constexpr const Value& operator[](Key key) const noexcept;
```

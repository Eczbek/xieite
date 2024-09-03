# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedMap<Key, Value, size, Hash, KeyComparator, Allocator>](../../../../fixed_map.md)\:\:FixedMap\<\>\(\)
Defined in fragment [xieite:containers.FixedMap](../../../../../../../src/containers/fixed_map.cpp)

&nbsp;

## Description
Constructs a `xieite::containers::FixedMap`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr FixedMap() noexcept;
```
#### 2)
```cpp
template<std::ranges::input_range Range>
requires(std::convertible_to<std::ranges::range_value_t<Range>, std::pair<Key, Value>>)
explicit constexpr FixedMap(Range&& entries) noexcept;
```
#### 3)
```cpp
explicit(false) constexpr FixedMap(std::initializer_list<std::pair<Key, Value>> entries) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using FixedMap = xieite::containers::FixedMap<int, double, 3>;

    FixedMap foo;
    FixedMap bar = foo;

    std::array<std::pair<int, double>, 3> data {
        { 1, 2.71828 },
        { 2, 3.14159 },
        { 3, 6.28318 }
    };
    FixedMap baz = FixedMap(data);

    FixedMap qux = {
        { 1, 2.71828 },
        { 2, 3.14159 },
        { 3, 6.28318 }
    };

    std::println("{}", baz[1]);
    std::println("{}", qux[2]);
}
```
Output:
```
3.14159
6.28318
```

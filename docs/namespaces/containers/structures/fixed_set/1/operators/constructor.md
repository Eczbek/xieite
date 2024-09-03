# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedSet<Key, size, Hash, KeyComparator,_ Allocator>](../../../../fixed_set.md)\:\:FixedSet\<\>\(\)
Defined in fragment [xieite:containers.FixedSet](../../../../../../../src/containers/fixed_set.cpp)

&nbsp;

## Description
Constructs a `xieite::containers::FixedSet`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr FixedSet() noexcept;
```
#### 2)
```cpp
template<std::ranges::input_range Range>
requires(std::convertible_to<std::ranges::range_value_t<Range>, Key>)
explicit(false) constexpr FixedSet(Range&& entries) noexcept;
```
#### 3)
```cpp
explicit(false) constexpr FixedSet(std::initializer_list<Key> entries) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using FixedSet = xieite::containers::FixedSet<int, 3>;

    FixedSet foo;
    FixedSet bar = foo;

    std::array<std::pair<int, double>, 3> data {
        { 1, 2.71828 },
        { 2, 3.14159 },
        { 3, 6.28318 }
    };
    FixedSet baz = FixedSet(data);

    FixedSet qux = {
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

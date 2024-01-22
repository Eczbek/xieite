# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedMap
Defined in header [<xieite/containers/fixed_map.hpp>](../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

## Description
A compile-time wrapper for `std::unordered_map`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value*>>>
struct FixedMap {
    constexpr FixedMap();

    template<std::ranges::range Range>
    constexpr FixedMap(const Range&);

    constexpr FixedMap(std::initializer_list<std::pair<Key, Value>>);

    constexpr const Value& operator[](const Key&) const;

    constexpr Value& operator[](const Key&);

    constexpr std::array<std::pair<Key, Value>, size>::const_iterator begin() const;

    constexpr std::array<std::pair<Key, Value>, size>::iterator begin();

    constexpr std::array<std::pair<Key, Value>, size>::const_iterator end() const;

    constexpr std::array<std::pair<Key, Value>, size>::iterator end();

    constexpr bool contains(const Key&) const;

    constexpr const std::array<std::pair<Key, Value>, size>& data() const;
};
```
##### Member functions
- [FixedMap](./structures/fixed_map/1/operators/constructor.md)
- [operator\[\]](./structures/fixed_map/1/operators/array_subscript.md)
- [begin](./structures/fixed_map/1/begin.md)
- [end](./structures/fixed_map/1/end.md)
- [contains](./structures/fixed_map/1/contains.md)
- [data](./structures/fixed_map/1/data.md)


&nbsp;

## Example
```cpp
#include <iostream>
#include <utility>
#include <xieite/containers/fixed_map.hpp>

int main() {
    constexpr xieite::containers::FixedMap<std::string_view, int, 4> map {
        { "foo", 1 },
        { "bar", 2 },
        { "baz", 3 },
        { "qux", 4 }
    };

    for (std::pair<std::string_view, int> entry : map) {
        std::cout << entry.first << ": " << entry.second << '\n';
    }
}
```
Output:
```
foo: 1
bar: 2
baz: 5
qux: 4
```

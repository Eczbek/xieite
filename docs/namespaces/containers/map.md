# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:Map
Defined in header [<xieite/containers/map.hpp>](../../../include/xieite/containers/map.hpp)

&nbsp;

## Description
A compile-time wrapper for `std::unordered_map`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value&>>>
class Map {
public:
    constexpr Map();

    template<std::ranges::range Range>
    constexpr Map(const Range&);

    constexpr Map(std::initializer_list<std::pair<Key, Value>>);

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

&nbsp;

## Example
```cpp
#include <iostream>
#include <utility>
#include <xieite/containers/map.hpp>

int main() {
    constexpr xieite::containers::Map<std::string_view, int, 4> map {
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

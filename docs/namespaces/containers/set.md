# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:Set
Defined in header [<xieite/containers/set.hpp>](../../../include/xieite/containers/set.hpp)

&nbsp;

## Description
A compile-time wrapper for `std::unordered_set`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
class Set {
public:
    constexpr Set();

    template<std::ranges::range Range>
    constexpr Set(const Range&);

    constexpr Set(std::initializer_list<Key>);

    constexpr const Value& operator[](const Key&) const;

    constexpr Value& operator[](const Key&);

    constexpr std::array<Key, size>::const_iterator begin() const;

    constexpr std::array<Key, size>::iterator begin();

    constexpr std::array<Key, size>::const_iterator end() const;

    constexpr std::array<Key, size>::iterator end();

    constexpr bool contains(const Key&) const;

    constexpr const std::array<Key, size>& data() const;
};
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <utility>
#include <xieite/containers/set.hpp>

int main() {
    constexpr xieite::containers::Set<std::string_view, 4> set {
        "foo",
        "bar",
        "baz",
        "qux"
    };

    for (std::string_view key : set) {
        std::cout << key << '\n';
    }
}
```
Output:
```
foo
bar
baz
qux
```

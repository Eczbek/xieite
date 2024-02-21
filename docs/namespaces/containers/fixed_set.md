# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedSet
Defined in header [<xieite/containers/fixed_set.hpp"](../../../include/xieite/containers/fixed_set.hpp)

&nbsp;

## Description
A compile-time wrapper for `std::unordered_set`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
struct FixedSet {
    constexpr FixedSet();

    template<std::ranges::range Range>
    constexpr FixedSet(const Range&);

    constexpr FixedSet(std::initializer_list<Key>);

    constexpr bool operator[](const Key&) const;

    constexpr std::array<Key, size>::const_iterator begin() const;

    constexpr std::array<Key, size>::iterator begin();

    constexpr std::array<Key, size>::const_iterator end() const;

    constexpr std::array<Key, size>::iterator end();

    constexpr bool contains(const Key&) const;

    constexpr const std::array<Key, size>& data() const;
};
```
##### Member functions
- [FixedMap](./structures/fixed_set/1/operators/constructor.md)
- [operator\[\]](./structures/fixed_set/1/operators/array_subscript.md)
- [begin](./structures/fixed_set/1/begin.md)
- [end](./structures/fixed_set/1/end.md)
- [contains](./structures/fixed_set/1/contains.md)
- [data](./structures/fixed_set/1/data.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <utility>
#include "xieite/containers/fixed_set.hpp"

int main() {
    constexpr xieite::containers::FixedFixedSet<std::string_view, 4> set {
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

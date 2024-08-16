# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedSet\<\> \{\}
Defined in header [<xieite/containers/fixed_set.hpp>](../../../include/xieite/containers/fixed_set.hpp)

&nbsp;

## Description
A `constexpr` wrapper-like structure for `std::unordered_set`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Key, std::size_t size, typename Hash = std::hash<Key>, typename KeyComparator = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
struct FixedSet {
    constexpr FixedSet() noexcept;

    template<std::ranges::input_range Range>
    requires(std::convertible_to<std::ranges::range_value_t<Range>, Key>)
    constexpr FixedSet(Range&&) noexcept;

    constexpr FixedSet(std::initializer_list<Key>) noexcept;

    template<std::convertible_to<Key> KeyReference>
    constexpr bool operator[](KeyReference&&) const noexcept;

    template<std::convertible_to<Key> KeyReference>
    constexpr bool contains(KeyReference&&) const noexcept;

    constexpr const std::array<Key, size>& data() const noexcept;
};
```
- [FixedMap\(\)](./structures/fixed_set/1/operators/constructor.md)
- [operator\[\]\(\)](./structures/fixed_set/1/operators/array_subscript.md)
- [contains\(\)](./structures/fixed_set/1/contains.md)
- [data\(\)](./structures/fixed_set/1/data.md)

&nbsp;

## Example
```cpp
#include <print>
#include <utility>
#include "xieite/containers/fixed_set.hpp"

int main() {
    constexpr xieite::containers::FixedSet<std::string_view, 4> set = {
        "foo",
        "bar",
        "baz",
        "qux"
    };

    for (std::string_view key : set) {
        std::println("{}", key);
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

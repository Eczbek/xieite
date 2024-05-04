# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedSet\<\> \{\}
Defined in header [<xieite/containers/fixed_set.hpp>](../../../include/xieite/containers/fixed_set.hpp)

&nbsp;

## Description
A `constexpr` wrapper-like structure for `std::unordered_set`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Key_, std::size_t size_, typename Hash_ = std::hash<Key_>, typename KeyComparator_ = std::equal_to<Key_>, typename Allocator_ = std::allocator<Key_>>
struct FixedSet {
    constexpr FixedSet() noexcept;

    template<xieite::concepts::RangeOf<Key_> Range_>
    constexpr FixedSet(Range&&) noexcept;

    constexpr FixedSet(std::initializer_list<Key_>) noexcept;

    template<std::convertible_to<Key_> KeyReference_>
    constexpr bool operator[](KeyReference_&&) const noexcept;

    template<std::convertible_to<Key_> KeyReference_>
    constexpr bool contains(KeyReference_&&) const noexcept;

    constexpr const std::array<Key_, size_>& data() const noexcept;
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

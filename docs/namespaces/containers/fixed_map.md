# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedMap\<\> \{\}
Defined in header [<xieite/containers/fixed_map.hpp>](../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

## Description
A `constexpr` wrapper-like structure for `std::unordered_map`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Key_, typename Value_, std::size_t size_, typename Hash_ = std::hash<Key_>, typename KeyComparator_ = std::equal_to<Key_>, typename Allocator_ = std::allocator<std::pair<const Key_, Value_*>>>
struct FixedMap {
    constexpr FixedMap() noexcept;

    template<xieite::concepts::RangeOf<std::pair<Key_, Value_>> Range_>
    constexpr FixedMap(Range_&&) noexcept;

    constexpr FixedMap(std::initializer_list<std::pair<Key_, Value_>>) noexcept;

    template<typename Self_, std::convertible_to<Key_> KeyReference_>
    constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_>>> operator[](this Self_&&, KeyReference_&&) noexcept;

    template<typename Self_, std::convertible_to<Key_> KeyReference_>
    constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_>>> at(this Self_&&, KeyReference_&&) noexcept;

    template<std::convertible_to<Key_> KeyReference_>
    constexpr bool contains(KeyReference_&&) const noexcept;

    constexpr const std::array<std::pair<Key_, Value_>, size_>& data() const noexcept;
};
```
- [FixedMap\(\)](./structures/fixed_map/1/operators/constructor.md)
- [operator\[\]\(\)](./structures/fixed_map/1/operators/array_subscript.md)
- [at\(\)](./structures/fixed_map/1/at.md)
- [contains\(\)](./structures/fixed_map/1/contains.md)
- [data\(\)](./structures/fixed_map/1/data.md)


&nbsp;

## Example
```cpp
#include <print>
#include <utility>
#include "xieite/containers/fixed_map.hpp"

int main() {
    constexpr xieite::containers::FixedMap<std::string_view, int, 4> map = {
        { "foo", 1 },
        { "bar", 2 },
        { "baz", 3 },
        { "qux", 4 }
    };

    for (auto [key, value] : map.data()) {
        std::println("{}: {}", key, value);
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

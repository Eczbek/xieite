# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedMap \{\}
Defined in header [<xieite/containers/fixed_map.hpp>](../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

## Description
A `constexpr` wrapper-like structure for `std::unordered_map`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyComparator = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value*>>>
struct FixedMap {
    constexpr FixedMap() noexcept;

    template<xieite::concepts::RangeOf<std::pair<Key, Value>> Range>
    constexpr FixedMap(Range&&) noexcept;

    constexpr FixedMap(std::initializer_list<std::pair<Key, Value>>) noexcept;

    template<typename Self, std::convertible_to<Key> KeyReference>
    constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value>>> operator[](this Self&&, KeyReference&&) noexcept;

    template<typename Self, std::convertible_to<Key> KeyReference>
    constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value>>> at(this Self&&, KeyReference&&) noexcept;

    template<std::convertible_to<Key> KeyReference>
    constexpr bool contains(KeyReference&&) const noexcept;

    constexpr const std::array<std::pair<Key, Value>, size>& data() const noexcept;
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

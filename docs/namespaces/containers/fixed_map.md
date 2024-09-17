# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:FixedMap\<\> \{\}
Defined in fragment [xieite:containers.FixedMap](../../../src/containers/fixed_map.cpp)

&nbsp;

## Description
A `constexpr` wrapper-like structure for `std::unordered_map`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyComparator = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value*>>>
struct FixedMap {
    FixedMap() = default;

    template<std::ranges::input_range Range>
    requires(std::convertible_to<std::ranges::range_value_t<Range>, std::pair<Key, Value>>)
    constexpr FixedMap(Range&&) noexcept;

    constexpr FixedMap(std::initializer_list<std::pair<Key, Value>>) noexcept;

    template<typename Self, std::convertible_to<Key> KeyReference>
    constexpr auto&& operator[](this Self&&, KeyReference&&) noexcept;

    template<typename Self, std::convertible_to<Key> KeyReference>
    constexpr auto&& at(this Self&&, KeyReference&&) noexcept;

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
import std;
import xieite;

int main() {
    constexpr xieite::containers::FixedMap<std::string_view, int, 4> map = {
        { "foo", 1 },
        { "bar", 2 },
        { "baz", 5 },
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

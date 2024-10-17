# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:makeSparseArray\<\>\(\)
Defined in fragment [xieite:containers.makeSparseArray](../../../src/containers/make_sparse_array.cpp)

&nbsp;

## Description
Creates a sparse (map-like?) `std::array`. The key type is constrained to 2^16 possible values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Key, typename Value, typename Range = std::initializer_list<Pair<Key, Value>>>
requires((std::numeric_limits<Key>::digits <= 16) && (xieite::types::arity<std::ranges::range_value_t<Range>> == 2))
[[nodiscard]] constexpr auto makeSparseArray(Range&& entries) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

constexpr auto map = xieite::containers::makeSparseArray<char, int>({
    { 'a', 1 },
    { 'b', 2 },
    { 'c', 3 }
});

int main() {
    std::print("{}\n", map['a']);
    std::print("{}\n", map['b']);
    std::print("{}\n", map['c']);
}
```
Output:
```
1
2
3
```

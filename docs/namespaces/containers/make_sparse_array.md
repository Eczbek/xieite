# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:makeSparseArray\<\>\(\)
Defined in fragment [xieite:containers.makeSparseArray](../../../src/containers/make_sparse_array.cpp)

&nbsp;

## Description
Creates a sparse (map-like?) `std::array`. The key type is constrained to 2^16 possible values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Key, typename Value, std::ranges::input_range Range = std::initializer_list<std::pair<Key, Value>>, xieite::concepts::Invocable<Value(std::ranges::range_common_reference_t<Range>)> Functor = decltype(XIEITE_LIFT_PREFIX_GLOBAL(static_cast<Value>))>
requires((std::numeric_limits<Key>::digits <= 16) && (xieite::types::arity<std::ranges::range_value_t<Range>> == 2))
[[nodiscard]] constexpr std::array<Value, (1uz << xieite::bits::size<Key>)> makeSparseArray(Range&& entries, Functor&& converter = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, Value(std::ranges::range_common_reference_t<Range>)>)
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

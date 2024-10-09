# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:makeArray\<\>\(\)
Defined in fragment [xieite:containers.makeArray](../../../src/containers/make_array.cpp)

&nbsp;

## Description
Attempts to create `std::array`s from other ranges.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Value, std::size_t size, std::ranges::input_range Range, xieite::concepts::Invocable<Value(std::ranges::range_common_reference_t<Range>)> Functor = decltype(XIEITE_LIFT_PREFIX_CAPTURE(, static_cast<Value>))>
[[nodiscard]] constexpr std::array<Value, size> makeArray(Range&& range, Functor&& converter = Functor())
XIEITE_ARROW_BASE(/* ... */)
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::vector<int> source = { 1, 2, 3, 4, 5 };

    auto result = xieite::containers::makeArray<int, 5>(source);

    for (int item : result) {
        std::println("{}", item);
    }
}
```
Output:
```
14
```

# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:makeArray\<\>\(\)
Defined in fragment [xieite:containers.makeArray](../../../src/containers/make_array.cpp)

&nbsp;

## Description
Attempts to create a `std::array` from another other range.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Value, std::size_t size, std::ranges::input_range Range = std::initializer_list<Value>, xieite::concepts::Invocable<Value(std::ranges::range_common_reference_t<Range>)> Functor = decltype(XIEITE_LIFT_PREFIX_GLOBAL(static_cast<Value>))>
[[nodiscard]] constexpr std::array<Value, size> makeArray(Range&& range, Functor&& converter = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, Value(std::ranges::range_common_reference_t<Range>)>)
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

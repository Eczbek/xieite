# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:spliceTuple\(\)
Defined in fragment [xieite:containers.spliceTuple](../../../src/containers/splice_tuple.cpp)

&nbsp;

## Description
Can be used to insert, replace, and remove elements from a tuple.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start, std::size_t end = start, xieite::concepts::SpecializationOf<std::tuple> Tuple1, xieite::concepts::SpecializationOf<std::tuple> Tuple2 = std::tuple<>>
[[nodiscard]] constexpr auto spliceTuple(Tuple1&& tuple1, Tuple2&& tuple2 = Tuple2()) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto foo = std::make_tuple(1, 2, 3);

    auto bar = std::make_tuple(6.28318, 'h');

    std::apply([](auto... values) {
        (..., std::println("{}", values));
    }, xieite::containers::spliceTuple<1, 2>(foo, bar));
}
```
Output:
```
1
6.28318
h
3
```

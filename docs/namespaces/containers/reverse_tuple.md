# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:reverseTuple\<\>\(\)
Defined in fragment [xieite:containers.reverseTuple](../../../src/containers/reverse_tuple.cpp)

&nbsp;

## Description
Reverses the order of elements in a `std::tuple`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Types>
[[nodiscard]] constexpr xieite::types::List<Types...>::Reverse::To<std::tuple> reverseTuple(const std::tuple<Types...>& tuple) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto tuple = std::make_tuple<int, char, float>(5, 'h', 3.14159);

    auto result = xieite::containers::reverseTuple(tuple);

    std::apply([](auto... values) {
        (..., std::println("{}", values));
    }, result);
}
```
Output:
```
3.14159
h
5
```

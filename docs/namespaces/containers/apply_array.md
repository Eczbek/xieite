# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:applyArray\<\>\(\)
Defined in fragment [xieite:containers.applyArray](../../../src/containers/apply_array.cpp)

&nbsp;

## Description
Passes the elements of a `std::array` to a functor or constructor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
constexpr auto applyArray(Functor&& functor, Array&& array)
XIEITE_ARROW(/* ... */)
```
#### 2)
```cpp
template<typename Structure, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
[[nodiscard]] constexpr auto applyArray(Array&& array)
XIEITE_ARROW(/* ... */)
```

&nbsp;

## Example
```cpp
import std;
import xieite;

void foo(int x, int y, int z) {
    std::println("{} {} {}", x, y, z);
}

int main() {
    std::array<int, 3> array = { 1, 2, 3 };

    xieite::containers::applyArray(foo, 17, 3, 418);
}
```
Output:
```
17 3 418
```

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
requires(xieite::types::List<Value>::template Repeat<size>::template Prepend<Functor>::template To<std::is_invocable>::value)
constexpr decltype(auto) applyArray(Functor&& functor, Array&& array)
noexcept(xieite::types::List<Value>::template Repeat<size>::template Prepend<Functor>::template To<std::is_nothrow_invocable>::value);
```
#### 2)
```cpp
template<typename Structure, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
requires(xieite::types::List<Value>::template Repeat<size>::template Prepend<Structure>::template To<std::is_constructible>::value)
[[nodiscard]] constexpr Structure applyArray(Array&& array)
noexcept(xieite::types::List<Value>::template Repeat<size>::template Prepend<Structure>::template To<std::is_nothrow_constructible>::value);
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

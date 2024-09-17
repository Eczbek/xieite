# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:fibonacci\<\>
Defined in fragment [xieite:math.fibonacci](../../../src/math/fibonacci.cpp)

&nbsp;

## Description
A lookup table of all representable values of the fibonacci sequence.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
constexpr std::array<Arithmetic, /* size */> fibonacci = /* ... */
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::fibonacci<std::size_t>[45]);
}
```
Output:
```
1134903170
```

# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:factorial\<\>
Defined in fragment [xieite:math.factorial](../../../src/math/factorial.cpp)

&nbsp;

## Description
A lookup table of all representable factorial values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
inline constexpr std::array<Arithmetic, /* size */> factorial = /* ... */
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::factorial<std::size_t>[17]);
}
```
Output:
```
355687428096000
```

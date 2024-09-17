# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:tau\<\>
Defined in fragment [xieite:math.tau](../../../src/math/tau.cpp)

&nbsp;

## Description
Defines a constant for tau.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
constexpr Arithmetic tau = xieite::math::pi<Arithmetic> * 2;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::tau<double>);
}
```
Possible output:
```
6.283185307179586
```

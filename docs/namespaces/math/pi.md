# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:pi\<\>
Defined in fragment [xieite:math.pi](../../../src/math/pi.cpp)

&nbsp;

## Description
Defines integer values of Pi.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
constexpr double pi = std::numbers::pi;
```
#### 2)
```cpp
template<std::floating_point Fractional>
constexpr Fractional pi<Fractional> = std::numbers::pi_v<Fractional>;
```
#### 3)
```cpp
template<std::integral Integral>
constexpr Integral pi<Integral> = static_cast<Integral>(std::numbers::pi);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::pi<double>);
    std::println("{}", xieite::math::pi<int>);
}
```
Output:
```
3.14159
3
```

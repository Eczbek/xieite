# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isPrime\<\>\(\)
Defined in fragment [xieite:math.isPrime](../../../src/math/is_prime.cpp)

&nbsp;

## Description
Checks whether an integer is only evenly divisible by itself and 1.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr bool isPrime(Integral value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::isPrime(17));
}
```
Output:
```
true
```

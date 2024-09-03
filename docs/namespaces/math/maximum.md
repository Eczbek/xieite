# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:maximum\<\>\(\)
Defined in fragment [xieite:math.maximum](../../../src/math/maximum.cpp)

&nbsp;

## Description
Finds the maximum of several values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
requires(sizeof...(Arithmetics) > 0)
[[nodiscard]] constexpr std::common_type_t<Arithmetics...> maximum(Arithmetics... values) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::maximum(1, 3, 2, 4, 5));
}
```
Output:
```
5
```

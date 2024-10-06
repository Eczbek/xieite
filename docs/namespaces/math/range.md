# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:range\<\>\(\)
Defined in fragment [xieite:math.range](../../../src/math/range.cpp)

&nbsp;

## Description
Generates a constant range.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t size, auto start = 0uz, std::same_as<decltype(start)> auto step = 1uz, std::integral Value = decltype(start)>
constexpr std::array<Value, size> range = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    for (auto n : xieite::math::range<5>) {
        std::println("{}", n);
    }
}
```
Output:
```
0
1
2
3
4
```

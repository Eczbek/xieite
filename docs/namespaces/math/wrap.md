# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:wrap\<\>\(\)
Defined in fragment [xieite:math.wrap](../../../src/math/wrap.cpp)

&nbsp;

## Description
"Wraps" a number between two limits, inclusively.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic wrap(Arithmetic value, std::common_type_t<Arithmetic> limit1, std::common_type_t<Arithmetic> limit2) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    for (int i = 0; i < 10; ++i) {
        std::println("{}", xieite::math::wrap(i, 4, -2));
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
-2
-1
0
1
2
```

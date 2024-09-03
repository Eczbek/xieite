# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:splitBoolean\(\)
Defined in fragment [xieite:math.splitBoolean](../../../src/math/split_boolean.cpp)

&nbsp;

## Description
"Splits" a boolean. `true` remains `1`, but `false` becomes `-1`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr int splitBoolean(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::splitBoolean(false));
}
```
Output:
```
-1
```

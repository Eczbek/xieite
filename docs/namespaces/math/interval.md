# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Interval\<\> \{\}
Defined in fragment [xieite:math.Interval](../../../src/math/interval.cpp)

&nbsp;

## Description
A simple structure for storing an interval between two numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
struct Interval {
    Arithmetic start;
    Arithmetic end;
};
```
- start
- end

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto interval = xieite::math::Interval<int>(-5, 23);

    std::println("{} {}", interval.start, interval.end);
}
```
Output:
```
-5 23
```

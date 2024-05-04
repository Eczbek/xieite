# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Interval\<\> \{\}
Defined in header [<xieite/math/interval.hpp>](../../../include/xieite/math/interval.hpp)

&nbsp;

## Description
A simple structure for storing an interval between two numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
struct Interval {
    Arithmetic_ start;
    Arithmetic_ end;
};
```
##### Members
- start
- end

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/interval.hpp"

int main() {
    auto interval = xieite::math::Interval<int>(-5, 23);

    std::println("{} {}", interval.start, interval.end);
}
```
Output:
```
-5 23
```

# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:unroll\<\>\(\)
Defined in fragment [xieite:functors.unroll](../../../src/functors/unroll.cpp)

&nbsp;

## Description
Unrolls an index sequence integer pack thing.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral auto count>
/* discardable */ constexpr auto unroll(auto&& lambda)
XIEITE_ARROW(/* ... */)
```
#### 2)
```cpp
template<typename... Types>
/* discardable */ constexpr auto unroll(auto&& lambda)
XIEITE_ARROW(xieite::functors::unroll<sizeof...(Types)>(XIEITE_FORWARD(lambda)))
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::functors::unroll<5>(
        []<int... i> {
            (..., std::print("{}\n", i));
        }
    );
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

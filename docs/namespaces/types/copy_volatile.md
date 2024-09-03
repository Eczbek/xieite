# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyVolatile\<\>
Defined in fragment [xieite:types.CopyVolatile](../../../src/types/copy_volatile.cpp)

&nbsp;

## Description
Copies the volatileness of `Source` to `Target`, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyVolatile = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<volatile int, xieite::types::CopyVolatile<volatile float, int>>);
    std::println("{}", std::same_as<volatile int&, xieite::types::CopyVolatile<volatile float, int&>>);
}
```
Output:
```
true
true
```

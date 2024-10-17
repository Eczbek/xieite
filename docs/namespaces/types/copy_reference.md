# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyReference\<\>
Defined in fragment [xieite:types.CopyReference](../../../src/types/copy_reference.cpp)

&nbsp;

## Description
Copies the reference type of `Source` to `Target`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyReference = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float, int>>());
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float, int&>>());
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float, int&&>>());
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&, int>>());
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&, int&>>());
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&, int&&>>());
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&&, int>>());
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&&, int&>>());
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&&, int&&>>());
}
```
Possible output:
```
int
int
int
int&
int&
int&
int&&
int&&
int&&
```

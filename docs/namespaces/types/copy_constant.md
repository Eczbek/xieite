# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyConstant\<\>
Defined in fragment [xieite:types.CopyConstant](../../../src/types/copy_constant.cpp)

&nbsp;

## Description
Copies the constness of `Source` to `Target`, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyConstant = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<const int, xieite::types::CopyConstant<const float, int>>);
    std::println("{}", std::same_as<const int&, xieite::types::CopyConstant<const float, int&>>);
}
```
Output:
```
true
true
```

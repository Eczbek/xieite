# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyConstantData\<\>
Defined in fragment [xieite:types.CopyConstantData](../../../src/types/copy_constant_data.cpp)

&nbsp;

## Description
Copies the constness of `Source` to the data type of `Target`, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, xieite::concepts::Pointer Target>
using CopyConstantData = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<const int*, xieite::types::CopyConstantData<const float, int*>>);
    std::println("{}", std::same_as<const int*&, xieite::types::CopyConstantData<const float, int*&>>);
}
```
Output:
```
true
true
```

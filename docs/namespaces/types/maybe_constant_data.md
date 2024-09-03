# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeConstantData\<\>
Defined in fragment [xieite:types.MaybeConstantData](../../../src/types/maybe_constant_data.cpp)

&nbsp;

## Description
An alias to a pointer to an optionally constant qualified data type, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Pointer Type, bool qualified>
using MaybeConstantData = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<const int*, xieite::types::MaybeConstantData<int*, true>>);
    std::println("{}", std::same_as<int*, xieite::types::MaybeConstantData<const int*, false>>);
    std::println("{}", std::same_as<const int*&, xieite::types::MaybeConstantData<int*&, true>>);
}
```
Output:
```
true
true
true
```

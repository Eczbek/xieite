# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeVolatileData\<\>
Defined in fragment [xieite:types.MaybeVolatileData](../../../src/types/maybe_volatile_data.cpp)

&nbsp;

## Description
An alias to a pointer to an optionally volatile qualified data type, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Pointer Type, bool qualified>
using MaybeVolatileData = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<volatile int*, xieite::types::MaybeVolatileData<int*, true>>);
    std::println("{}", std::same_as<int*, xieite::types::MaybeVolatileData<volatile int*, false>>);
    std::println("{}", std::same_as<volatile int*&, xieite::types::MaybeVolatileData<int*&, true>>);
}
```
Output:
```
true
true
true
```

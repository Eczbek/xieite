# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:TrySigned\<\>
Defined in fragment [xieite:types.TrySigned](../../../src/types/try_signed.cpp)

&nbsp;

## Description
Attempts to get the signed complement of an unsigned type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using TrySigned = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<int, xieite::types::TrySigned<unsigned int>>);
    std::println("{}", std::same_as<double, xieite::types::TrySigned<double>>);
}
```
Output:
```
true
true
```

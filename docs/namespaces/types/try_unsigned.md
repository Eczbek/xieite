# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:TryUnsigned\<\>
Defined in fragment [xieite:types.TryUnsigned](../../../src/types/try_unsigned.cpp)

&nbsp;

## Description
Attempts to get the unsigned complement of a signed type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using TryUnsigned = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<unsigned int, xieite::types::TryUnigned<int>>);
    std::println("{}", std::same_as<double, xieite::types::TryUnigned<double>>);
}
```
Possible output:
```
true
true
```

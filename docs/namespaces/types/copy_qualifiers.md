# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyQualifiers\<\>
Defined in fragment [xieite:types.CopyQualifiers](../../../src/types/copy_qualifiers.cpp)

&nbsp;

## Description
Copies the constness, volatileness, and reference type of `Source` to `Target`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyQualifiers = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<int* const volatile&&, xieite::types::CopyQualifiers<volatile const float&&, int*&>>);
}
```
Output:
```
true
```

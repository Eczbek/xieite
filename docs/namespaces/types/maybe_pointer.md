# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybePointer\<\>
Defined in fragment [xieite:types.MaybePointer](../../../src/types/maybe_pointer.cpp)

&nbsp;

## Description
An alias to an optionally pointer type, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool value>
using MaybePointer = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<int*, xieite::types::MaybePointer<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybePointer<int*, false>>);
    std::println("{}", std::same_as<int*&, xieite::types::MaybePointer<int&, true>>);
}
```
Output:
```
true
true
true
```

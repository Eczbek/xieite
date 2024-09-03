# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeVolatile\<\>
Defined in fragment [xieite:types.MaybeVolatile](../../../src/types/maybe_volatile.cpp)

&nbsp;

## Description
An alias to an optionally volatile qualified type, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool qualified>
using MaybeVolatile = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<volatile int, xieite::types::MaybeVolatile<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybeVolatile<volatile int, false>>);
    std::println("{}", std::same_as<volatile int&, xieite::types::MaybeVolatile<int&, true>>);
}
```
Output:
```
true
true
true
```

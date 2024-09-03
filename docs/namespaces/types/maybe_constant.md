# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeConstant\<\>
Defined in fragment [xieite:types.MaybeConstant](../../../src/types/maybe_constant.cpp)

&nbsp;

## Description
An alias to an optionally constant qualified type, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool qualified>
using MaybeConstant = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<const int, xieite::types::MaybeConstant<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybeConstant<const int, false>>);
    std::println("{}", std::same_as<const int&, xieite::types::MaybeConstant<int&, true>>);
}
```
Output:
```
true
true
true
```

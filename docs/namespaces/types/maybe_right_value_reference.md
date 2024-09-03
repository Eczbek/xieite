# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeLeftValueReference\<\>
Defined in fragment [xieite:types.MaybeLeftValueReference](../../../src/types/maybe_left_value_reference.cpp)

&nbsp;

## Description
An alias to an optionally lvalue reference qualified type

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool qualified>
using MaybeLeftValueReference = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<int&, xieite::types::MaybeLeftValueReference<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybeLeftValueReference<int&, false>>);
}
```
Output:
```
true
true
```

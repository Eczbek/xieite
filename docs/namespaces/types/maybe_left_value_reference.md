# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeRightValueReference\<\>
Defined in fragment [xieite:types.MaybeRightValueReference](../../../src/types/maybe_right_value_reference.cpp)

&nbsp;

## Description
An alias to an optionally rvalue reference qualified type

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool qualified>
using MaybeRightValueReference = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::same_as<int&&, xieite::types::MaybeRightValueReference<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybeRightValueReference<int&&, false>>);
}
```
Output:
```
true
true
```

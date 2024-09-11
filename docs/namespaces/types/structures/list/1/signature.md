# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Signature\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Creates a function signature type if none of the parameters are (possibly `const` or `volatile` qualified) `void`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using Signature = /* Type(Types...) */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, int>;

    std::println("{}", xieite::types::name<List::Signature<bool>>);
}
```
Possible output:
```
bool(int, int)
```

# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:AsFunction\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Creates a function signature type if none of the parameters satisfy `std::is_void_v`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Return>
using AsFunction = /* Return(Types...) */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, int>;

    std::println("{}", xieite::types::name<List::AsFunction<bool>>());
}
```
Possible output:
```
bool(int, int)
```

# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Value\<\>
Defined in fragment [xieite:types.Value](../../../src/types/value.cpp)

&nbsp;

## Description
A simple alias for a value wrapper (for metaprogramming purposes).

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename value>
using Value = std::integral_constant<decltype(value), value>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::types::Value<4>::value);
}
```
Possible output:
```
4
```

# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:name\<\>
Defined in fragment [xieite:types.name](../../../src/types/name.cpp)

&nbsp;

## Description
Extracts the stringified name of a type at compile-time without additional formatting (very compiler-dependant).

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
inline constexpr std::string_view name = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::types::name<std::vector<int>>);
}
```
Possible output:
```
std::vector<int>
```

# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:identifier\<\>
Defined in fragment [xieite:types.identifier](../../../src/types/identifier.cpp)

&nbsp;

## Description
Assigns an identifier to each unique type. Not guaranteed to give the same identifier to unique types across translation units or time. Same rules apply as [`xieite::functors::counter<>()`](../functors/counter.md#Description).

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
constexpr std::size_t identifier = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::types::identifier<int>);
    std::println("{}", xieite::types::identifier<float>);
    std::println("{}", xieite::types::identifier<char>);
    std::println("{}", xieite::types::identifier<int>);
}
```
Possible output:
```
0
1
2
0
```

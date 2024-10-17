# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:ZipRange\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Zips `Types...` with another range of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Range>
using ZipRange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Foo = xieite::types::List<int, char, long>;

    using Bar = xieite::types::List<float, short, bool>;

    std::println("{}", xieite::types::name<Foo::ZipRange<Bar>>());
}
```
Possible output:
```
xieite::types::List<xieite::types::List<int, float>, xieite::types::List<char, short>, xieite::types::List<long, bool>>
```

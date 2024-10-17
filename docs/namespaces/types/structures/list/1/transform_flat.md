# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:TransformFlat\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Applies a flat transformation to every set amount of types within the list, in order. The transformation **must** return a `std::type_identity` of a `xieite::types::List`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t arity, auto transformer>
requires(!(sizeof...(Types) % arity))
using TransformFlat = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Foo = xieite::types::List<int, char, long, float, short, bool>;

    using Bar = Foo::TransformFlat<2, []<typename T, typename U, typename...> {
        return std::type_identity<xieite::types::List<U, T>>();
    }>;

    std::println("{}", xieite::types::name<Bar>());
}
```
Possible output:
```
xieite::types::List<char, int, float, long, bool, short>
```

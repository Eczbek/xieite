# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Transform\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Applies a transformation to every set amount of types within the list, in order.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t arity, auto transformer>
requires(!(sizeof...(Types) % arity))
using Transform = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Foo = xieite::types::List<int, char, long, float, short, bool>;

    using Bar = Foo::Transform<2, []<typename T, typename U> {
        return std::declval<std::pair<T, U>>();
    }>;

    std::println("{}", xieite::types::name<Bar>);
}
```
Possible output:
```
xieite::types::List<std::pair<int, char>, std::pair<long, float>, std::pair<short, bool>>
```

# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Filter\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Filters types according to a selector callback.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto selector = /* lambda */>
using Filter = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    static constexpr auto callback = []<typename Type> {
        return std::integral<Type>;
    };

    using List = xieite::types::List<int, float, short, double, long>;

    std::println("{}", xieite::types::name<List::Filter<callback>>);
}
```
Possible output:
```
xieite::types::List<int, short, long>
```

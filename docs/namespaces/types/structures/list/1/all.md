# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:all\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Checks if a callback returns `true` for all types in the list.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto selector>
static constexpr bool all = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    static constexpr auto callback1 = []<typename Type> {
        return std::integral<Type>;
    };

    static constexpr auto callback2 = []<typename Type> {
        return std::floating_point<Type>;
    };

    using List = xieite::types::List<int, int, char, int, char, char, int>;

    std::println("{}", List::all<callback1>);
    std::println("{}", List::all<callback2>);
}
```
Possible output:
```
true
false
```

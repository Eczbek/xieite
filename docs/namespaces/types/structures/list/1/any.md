# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:any\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Checks if a callback returns `true` for any type in the list.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto selector>
static constexpr bool any = /* ... */;
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

    std::println("{}", List::any<callback1>);
    std::println("{}", List::any<callback2>);
}
```
Possible output:
```
true
false
```

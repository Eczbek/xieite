# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:find\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Finds the index of a type for which a callback returns `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto selector>
requires(xieite::types::List<Types...>::any<selector>)
static constexpr std::size_t find = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    static constexpr auto callback = []<typename Type> {
        return std::same_as<Type, double>;
    };

    using List = xieite::types::List<int, char, float, double, void, short, long, bool>;

    std::println("{}", List::find<callback>);
}
```
Possible output:
```
3
```

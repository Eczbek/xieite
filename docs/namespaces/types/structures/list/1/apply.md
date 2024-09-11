# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Apply\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Applies `Types...` to a callback and evaluates to its return type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto callback>
using Apply = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    static constexpr auto callback = []<typename... Types> {
        return std::type_identity<std::tuple<Types...>>();
    };

    using List = xieite::types::List<int, char, short, long>;

    std::println("{}", xieite::types::name<List::Apply<callback>::type>);
}
```
Possible output:
```
std::tuple<int, char, short, long>
```

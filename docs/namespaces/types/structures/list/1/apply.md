# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:apply\<\>\(\)
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Applies `Types...` to a lambda callback.

&nbsp;

## Synopsis
#### 1)
```cpp
static constexpr decltype(auto) apply(auto callback) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>;

    auto callback = []<typename... Types> {
        (..., std::println("{}", xieite::types::name<Types>));
    };

    List::apply(callback);
}
```
Possible output:
```
int
char
short
long
```

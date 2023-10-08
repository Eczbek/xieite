# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:Append
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

&nbsp;

Appends types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... OtherTypes>
using Append = xieite::types::List<Types..., OtherTypes...>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Append<float, double>;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<int, char, short, long, float, double>
```
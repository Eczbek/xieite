# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:Prepend
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

&nbsp;

Prepends types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... OtherTypes>
using Prepend = xieite::types::List<Types..., OtherTypes...>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Prepend<float, double>;

    std::cout << xieite::types::demangle(typeid(List).name()) << '\n';
}
```
Output:
```
xieite::types::List<float, double, int, char, short, long>
```

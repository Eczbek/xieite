# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NotAll\<\>
Defined in header [<xieite/concepts/not_all.hpp>](../../../include/xieite/concepts/not_all.hpp)

&nbsp;

## Description
Negates type traits. Expects trait-like template structures. Passing no trait templates evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept NotAll = (... && !Traits<Type>::value);
```

&nbsp;

## Example
```cpp
#include <print>
#include <type_traits>
#include "xieite/concepts/not_all.hpp"

template<xieite::concepts::NotAll<std::is_floating_point, std::is_unsigned>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<double>();
    test<int>();
}
```
Output:
```
yep
yep
```

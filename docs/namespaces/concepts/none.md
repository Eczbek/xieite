# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:None
Defined in header [<xieite/concepts/none.hpp>](../../../include/xieite/concepts/none.hpp)

&nbsp;

## Description
Negates type traits. Expects trait-like template structures. Passing no trait templates evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept None = (... && !Trait<Type>::value);
```

&nbsp;

## Example
```cpp
#include <print>
#include <type_traits>
#include "xieite/concepts/none.hpp"

template<xieite::concepts::None<std::is_integral>>
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
nope
```

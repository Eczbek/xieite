# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:reverseArguments\<\>\(\)
Defined in header [<xieite/functors/reverse_arguments.hpp>](../../../include/xieite/functors/reverse_arguments.hpp)

&nbsp;

## Description
Passes arguments to a functor or a constructor in reversed order.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Arguments_, typename Functor_>
requires(xieite::types::List<Arguments_...>::Reverse::template Prepend<Functor_>::template Apply<std::is_invocable>::value)
constexpr typename xieite::types::List<Arguments_...>::Reverse::Prepend<Functor_>::Apply<std::invoke_result>::type reverseArguments(Functor_&& functor, Arguments_&&... arguments)
noexcept(xieite::types::List<Arguments_...>::Reverse::template Prepend<Functor_>::template Apply<std::is_nothrow_invocable>::value);
```
#### 2)
```cpp
template<typename Structure, typename... Arguments_>
requires(xieite::types::List<Arguments_...>::Reverse::template Prepend<Structure>::template Apply<std::is_constructible>::value)
[[nodiscard]] constexpr Structure reverseArguments(Arguments_&&... arguments)
noexcept(xieite::types::List<Arguments_...>::Reverse::template Prepend<Structure>::template Apply<std::is_nothrow_constructible>::value);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/reverse_arguments.hpp"

void foo(int x, char y, double z) {
    std::println("{} {} {}", x, y, z);
}

struct Bar {
    Bar(int x, char y, double z) {
        std::println("{} {} {}", x, y, z);
    }
};

int main() {
    xieite::functors::reverseArguments(foo, 3.14159, 'h', 17);

    Bar bar = xieite::functors::reverseArguments<Bar>(6.28318, 'E', 418);
}
```
Output:
```
17 h 3.14159
418 E 6.28318
```

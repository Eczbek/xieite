# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:distributeArguments\<\>\(\)
Defined in header [<xieite/functors/distribute_arguments.hpp>](../../../include/xieite/functors/distribute_arguments.hpp)

&nbsp;

## Description
Distributes arguments among several calls to a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t arity, xieite::concepts::InvocableWithArity<arity> Functor, typename... Arguments>
requires((arity > 0) && !(sizeof...(Arguments) % arity))
constexpr void distributeArguments(Functor&& functor, Arguments&&... arguments)
noexcept(xieite::concepts::NoThrowInvocableWithArity<Functor, arity>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/distribute_arguments.hpp"

int main() {
    auto lambda = [](int x, int y, int z) -> void {
        std::println("{} {} {}", x, y, z);
    };

    xieite::functors::distributeArguments<3>(lambda, 1, 2, 3, 4, 5, 6);
}
```
Output:
```
1 2 3
4 5 6
```

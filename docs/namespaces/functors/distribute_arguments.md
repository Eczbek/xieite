# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:distributeArguments\<\>\(\)
Defined in header [<xieite/functors/distribute_arguments.hpp>](../../../include/xieite/functors/distribute_arguments.hpp)

&nbsp;

## Description
Distributes arguments among several calls to a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t arity_, xieite::concepts::InvocableWithArity<arity_> Functor_, typename... Arguments_>
requires((arity_ > 0) && !(sizeof...(Arguments_) % arity_))
constexpr void distributeArguments(Functor_&& functor, Arguments_&&... arguments)
noexcept(xieite::concepts::NoThrowInvocableWithArity<Functor_, arity_>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/distribute_arguments.hpp"

int main() {
    auto lambda = [](int x, int y, int z) {
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

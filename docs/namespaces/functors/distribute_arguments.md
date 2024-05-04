# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:distributeArguments\<\>\(\)
Defined in header [<xieite/functors/distribute_arguments.hpp>](../../../include/xieite/functors/distribute_arguments.hpp)

&nbsp;

## Description
Distributes arguments among several calls to a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t argumentCount_, xieite::concepts::InvocableWithArgumentCount<argumentCount_> Functor_, typename... Arguments_>
requires((argumentCount_ > 0) && !(sizeof...(Arguments_) % argumentCount_))
constexpr void distributeArguments(Functor_&& functor, Arguments_&&... arguments)
noexcept(xieite::concepts::NoThrowInvocableWithArgumentCount<Functor_, argumentCount_>);
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

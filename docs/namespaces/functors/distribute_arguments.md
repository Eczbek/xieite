# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:distributeArguments\(\)
Defined in header [<xieite/functors/distribute_arguments.hpp>](../../../include/xieite/functors/distribute_arguments.hpp)

&nbsp;

## Description
Distributes arguments among several calls to a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t argumentCount, xieite::concepts::InvocableWithArgumentCount<argumentCount> Functor, typename... Arguments>
requires((argumentCount > 0) && !(sizeof...(Arguments) % argumentCount))
constexpr void distributeArguments(Functor&& functor, Arguments&&... arguments)
noexcept(xieite::concepts::NoThrowInvocableWithArgumentCount<Functor, argumentCount>);
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

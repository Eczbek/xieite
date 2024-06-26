# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:recursivelyDistributeArguments\<\>\(\)
Defined in header [<xieite/functors/recursively_distribute_arguments.hpp>](../../../include/xieite/functors/recursively_distribute_arguments.hpp)

&nbsp;

## Description
Distributes arguments among several calls to a functor, but recursively such that one of the arguments to succeeding calls is the result of the previous.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t arity_, std::size_t previousResultIndex_ = 0, xieite::concepts::InvocableWithArity<arity_> Functor_, typename... Arguments_>
requires((arity_ > previousResultIndex_) && (arity_ <= sizeof...(Arguments_)) && ((arity_ == 1) || (arity_ > 1) && !((sizeof...(Arguments_) - 1) % (arity_ - 1))))
constexpr decltype(auto) recursivelyDistributeArguments(Functor_&& functor, Arguments_&&... arguments)
noexcept(xieite::concepts::NoThrowInvocableWithArity<Functor_, arity_>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/recursively_distribute_arguments.hpp"

int main() {
    auto lambda = [](int x, int total) {
        std::println("total: {}", total);
        return total + x;
    };

    int total = xieite::functors::recursivelyDistributeArguments<2, 1>(lambda, 1, 2, 3, 4, 5);
    std::println("total: {}", total);
}
```
Output:
```
total: 2
total: 3
total: 6
total: 10
total: 15
```

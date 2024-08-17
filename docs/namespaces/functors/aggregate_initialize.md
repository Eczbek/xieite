# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:AggregateInitialize\<\> \{\}
Defined in header [<xieite/functors/aggregate_initialize.hpp>](../../../include/xieite/functors/aggregate_initialize.hpp)

&nbsp;

## Description
A functor which simply aggregate-initializes a type with arguments.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
struct AggregateInitialize {
    template<typename... Arguments>
    requires(xieite::concepts::AggregateInitializable<Type, Arguments...>)
    constexpr Type operator()(Arguments&&...) const
    noexcept(xieite::concepts::NoThrowAggregateInitializable<Type, Arguments...>);
};
```
- [operator\(\)\<\>\(\)](./structures/aggregate_initialize/1/operators/call.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/aggregate_initialize.hpp"

struct Thing {
    int a;
    double b;
    void* c;
};

int main() {
    auto thing = xieite::functors::AggregateInitialize<Thing>()(418, 3.14159, nullptr);

    std::println("{} {} {}", thing.a, thing.b, thing.c);
}
```
Possible output:
```
418 3.14159 0x0
```

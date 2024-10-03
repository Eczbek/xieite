# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:tryConstantArguments\<\>\(\)
Defined in fragment [xieite:functors.tryConstantArguments](../../../src/functors/try_constant_arguments.cpp)

&nbsp;

## Description
Attempts to invoke a function with arguments made constant, if possible.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, typename... Arguments>
requires(std::invocable<Functor, xieite::types::MaybeConstant<Arguments, true>...> || std::invocable<Functor, Arguments...>)
constexpr decltype(auto) tryConstantArguments(Functor&& functor, Arguments&&... arguments)
noexcept(std::invocable<Functor, xieite::types::MaybeConstant<Arguments, true>...> ? std::is_nothrow_invocable_v<Functor, xieite::types::MaybeConstant<Arguments, true>...> : std::is_nothrow_invocable_v<Functor, Arguments...>);
```

&nbsp;

## Example
```cpp
#include <xieite/lift.hpp>
import std;
import xieite;

struct A {
    int operator!() {
        return 1;
    }

    int operator!() const {
        return 2;
    }
};

struct B {
    int operator!() {
        return 3;
    }
};

int main() {
    std::print("{}\n", xieite::functors::tryConstantArguments(XIEITE_LIFT_PREFIX(!), A()));
    std::print("{}\n", xieite::functors::tryConstantArguments(XIEITE_LIFT_PREFIX(!), B()));
}
```
Output:
```
2
3
```

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
requires(xieite::types::List<Arguments...>::template Transform<1, []<typename Argument, typename... First> { return std::type_identity<std::conditional_t<xieite::types::List<Arguments...>::template Slice<sizeof...(First) + 1>::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>::template To<std::is_invocable>::value, xieite::types::MaybeConstant<Argument, true>, Argument>>(); }>::template Prepend<Functor>::template To<std::is_invocable>::value)
/* discardable */ constexpr typename xieite::types::List<Arguments...>::template Transform<1, []<typename Argument, typename... First> { return std::type_identity<std::conditional_t<xieite::types::List<Arguments...>::template Slice<sizeof...(First) + 1>::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>::template To<std::is_invocable>::value, xieite::types::MaybeConstant<Argument, true>, Argument>>(); }>::template Prepend<Functor>::template To<std::invoke_result_t> tryConstantArguments(Functor&& functor, Arguments&&... arguments)
noexcept(xieite::types::List<Arguments...>::template Transform<1, []<typename Argument, typename... First> { return std::type_identity<std::conditional_t<xieite::types::List<Arguments...>::template Slice<sizeof...(First) + 1>::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>::template To<std::is_invocable>::value, xieite::types::MaybeConstant<Argument, true>, Argument>>(); }>::template Prepend<Functor>::template To<std::is_nothrow_invocable>::value);
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

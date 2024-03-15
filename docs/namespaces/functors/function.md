# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Function \{\}
Defined in header [<xieite/functors/function.hpp>](../../../include/xieite/functors/function.hpp)

&nbsp;

## Description
`std::function` but constexpr.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
struct Function;
```
#### 2)
```cpp
template<typename Result, typename... Arguments>
struct Function<Result(Arguments...)> {
    constexpr Function() noexcept;

    template<typename Functor>
    requires(std::same_as<std::remove_cvref_t<Functor>, xieite::functors::Function<Result(Arguments...)>>)
    constexpr Function(Functor&&) noexcept;

    template<xieite::concepts::Functable<Result(Arguments...)> Functor>
    requires(!std::same_as<std::remove_cvref_t<Functor>, xieite::functors::Function<Result(Arguments...)>>)
    constexpr Function(Functor&&) noexcept;

    constexpr operator bool() const noexcept;

    template<typename... ArgumentReferences>
    requires((... && std::convertible_to<ArgumentReferences, Arguments>))
    constexpr Result operator()(ArgumentReferences&&...) const;
};
```
- [Function\(\)](./structures/function/2/operators/constructor.md)
- [operator typename\(\)](./structures/function/2/operators/cast.md)
- [operator\(\)\(\)](./structures/function/2/operators/call.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/function.hpp"

int add(int a, int b) {
    return a + b;
}

int main() {
    xieite::functors::Function<int(int, int)> foo = &add;

    int x = 4;
    xieite::functors::Function<int(int)> bar = [&x](int a) {
        return a * x;
    };

    xieite::functors::Function<int()> baz = [i = 0] mutable {
        return i++;
    };

    xieite::functors::Function<int()> qux = baz;

    std::println("{}", foo(1, 2));
    std::println("{}", bar(3));
    std::println("{}", baz());
    std::println("{}", baz());
    std::println("{}", qux());
}
```
Output:
```
3
12
0
1
0
```

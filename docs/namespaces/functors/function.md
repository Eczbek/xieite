# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Function\<\> \{\}
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
template<typename Return_, typename... Arguments_>
struct Function<Return_(Arguments_...)> {
    constexpr Function() noexcept;

    constexpr Function(const xieite::functors::Function<Return_(Arguments_...)>&) noexcept;

    template<xieite::concepts::Functable<Return_(Arguments_...)> Functor_>
    requires(!std::same_as<std::remove_cvref_t<Functor_>, xieite::functors::Function<Return_(Arguments_...)>>)
    constexpr Function(Functor_&&) noexcept;

    explicit constexpr operator bool() const noexcept;

    template<typename... ArgumentReferences_>
    requires((... && std::convertible_to<ArgumentReferences_, Arguments_>))
    constexpr Return_ operator()(ArgumentReferences_&&...) const;
};
```
- [Function\<\>\(\)](./structures/function/2/operators/constructor.md)
- [operator typename\(\)](./structures/function/2/operators/cast.md)
- [operator\(\)\<\>\(\)](./structures/function/2/operators/call.md)

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

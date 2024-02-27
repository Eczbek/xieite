# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Function
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
    constexpr Function();

    template<xieite::concepts::Functable<Result(Arguments...)> Functor>
    constexpr Function(const Functor&);

    constexpr operator bool() const;

    constexpr Result operator()(Arguments...) const;
};
```
##### Member functions
- [Function](./structures/function/2/operators/constructor.md)
- [operator typename](./structures/function/2/operators/cast.md)
- [operator()](./structures/function/2/operators/call.md)

&nbsp;

## Example
```cpp
#include <iostream>
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

    xieite::functors::Function<int()> baz = [] {
        static int i = 0;
        return i++;
    };

    xieite::functors::Function<int()> qux = baz;

    std::cout
        << foo(1, 2) << '\n'
        << bar(3) << '\n'
        << baz() << '\n'
        << qux() << '\n';
}
```
Output:
```
3
12
0
1
```

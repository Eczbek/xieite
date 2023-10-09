# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Infix
Defined in header [<xieite/functors/infix.hpp>](../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
An infix operator thing.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename>
struct Infix;
```
#### 2)
```cpp
template<std::invocable<xieite::types::Placeholder> Functor>
struct Infix<Functor> {
    constexpr Infix(Functor&&);

    template<typename Argument>
    requires(std::invocable<Functor, Argument&&>)
    friend constexpr std::invoke_result_t<Functor, Argument&&> operator>(const xieite::functors::Infix<Functor>&, Argument&&);

    template<typename Argument>
    requires(std::invocable<Functor, Argument&&>)
    friend constexpr std::invoke_result_t<Functor, Argument&> operator<(Argument&&, const xieite::functors::Infix<Functor>&);
};
```
##### Member functions
- [operator>](./structures/infix/2/operators/more.md)
- [operator<](./structures/infix/2/operators/less.md)
#### 3)
```cpp
template<std::invocable<xieite::types::Placeholder, xieite::types::Placeholder> Functor>
class Infix<Functor> {
private:
    template<typename LeftArgument>
    struct Intermediate;

public:
    constexpr Infix(Functor&&);

    template<typename LeftArgument>
    requires(std::invocable<Functor, LeftArgument&&, xieite::types::Placeholder>)
    [[nodiscard]] friend constexpr xieite::functors::Infix<Functor>::Intermediate<LeftArgument&&> operator<(LeftArgument&&, const xieite::functors::Infix<Functor>&);
};
```
##### Member structures
- [Intermediate](./structures/infix/3/intermediate.md)
##### Member functions
- [operator<](./structures/infix/3/operators/less.md)

&nbsp;

### Deduction guides
```cpp
template<typename Functor>
xieite::functors::Infix(Functor&&) -> xieite::functors::Infix<Functor>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/infix.hpp>

int main() {
    auto multiply = xieite::functors::Infix([](int x, int y) {
        return x * y;
    });

    auto increment = xieite::functors::Infix([](int x) {
        return x + 1;
    });

    std::cout
        << (2 <multiply> 2) << '\n'
        << (1 <increment) << '\n'
        << (increment> 7) << '\n';
}
```
Output:
```
4
2
8
```

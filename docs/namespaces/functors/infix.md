# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Infix\<\> \{\}
Defined in header [<xieite/functors/infix.hpp>](../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
An infix operator thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
struct Infix;
```
#### 2)
```cpp
template<typename Return_, typename Argument_>
struct Infix<Return_(Argument_)>
: xieite::functors::Function<Return_(Argument_)> {
    using xieite::functors::Function<Return_(Argument_)>::Function;

    template<std::convertible_to<Argument_> ArgumentReference_>
    friend constexpr Return_ operator>(const xieite::functors::Infix<Return_(Argument_)>&, ArgumentReference_&&);

    template<std::convertible_to<Argument_> ArgumentReference_>
    friend constexpr Return_ operator<(ArgumentReference_&&, const xieite::functors::Infix<Return_(Argument_)>&);
};
```
##### Members
- [operator\>\<\>\(\)](./structures/infix/2/operators/more.md)
- [operator\<\<\>\(\)](./structures/infix/2/operators/less.md)
#### 3)
```cpp
template<typename Return_, typename LeftArgument_, typename RightArgument_>
struct Infix<Return_(LeftArgument_, RightArgument_)>
: xieite::functors::Function<Return_(LeftArgument_, RightArgument_)> {
private:
    template<typename LeftArgumentReference_>
    struct Intermediate;

public:
    using xieite::functors::Function<Return_(LeftArgument_, RightArgument_)>::Function;

    template<std::convertible_to<LeftArgument_> LeftArgumentReference_>
    friend constexpr xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgumentReference_> operator<(LeftArgumentReference_&&, const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>&) noexcept;
};
```
##### Members
- [Intermediate \{\}](./structures/infix/3/intermediate.md)
- [operator\<\<\>\(\)](./structures/infix/3/operators/less.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/infix.hpp"

int main() {
    xieite::functors::Infix<int(int, int)> multiply = [](int x, int y) {
        return x * y;
    };

    xieite::functors::Infix<int(int)> increment = [](int x) {
        return x + 1;
    };

    std::println("{}", 2 <multiply> 2);
    std::println("{}", multiply(4, 8));
    std::println("{}", 1 <increment);
    std::println("{}", increment> 7);
    std::println("{}", increment(98));
}
```
Output:
```
4
32
2
8
99
```

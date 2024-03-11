# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Infix \{\}
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
template<typename Result, typename Argument>
struct Infix<Result(Argument)>
: xieite::functors::Function<Result(Argument)> {
    using xieite::functors::Function<Result(Argument)>::Function;

    template<std::convertible_to<Argument> ArgumentReference>
    friend constexpr Result operator>(const xieite::functors::Infix<Result(Argument)>&, ArgumentReference&&);

    template<std::convertible_to<Argument> ArgumentReference>
    friend constexpr Result operator<(ArgumentReference&&, const xieite::functors::Infix<Result(Argument)>&);
};
```
- [operator>](./structures/infix/2/operators/more.md)
- [operator<](./structures/infix/2/operators/less.md)
#### 3)
```cpp
template<typename Result, typename LeftArgument, typename RightArgument>
struct Infix<Result(LeftArgument, RightArgument)>
: xieite::functors::Function<Result(LeftArgument, RightArgument)> {
private:
    template<typename LeftArgumentReference>
    struct Intermediate;

public:
    using xieite::functors::Function<Result(LeftArgument, RightArgument)>::Function;

    template<std::convertible_to<LeftArgument> LeftArgumentReference>
    friend constexpr xieite::functors::Infix<Result(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference> operator<(LeftArgumentReference&&, const xieite::functors::Infix<Result(LeftArgument, RightArgument)>&) noexcept;
};
```
##### Members
- [Intermediate \{\}](./structures/infix/3/intermediate.md)
- [operator<\(\)](./structures/infix/3/operators/less.md)

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

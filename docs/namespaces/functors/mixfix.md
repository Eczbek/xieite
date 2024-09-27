# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Mixfix\<\> \{\}
Defined in fragment [xieite:functors.Mixfix](../../../src/functors/mixfix.cpp)

&nbsp;

## Description
A mixfix operator thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
struct Mixfix;
```
#### 2)
```cpp
template<typename Return, typename Argument>
struct Mixfix<Return(Argument)>
: xieite::functors::Function<Return(Argument)> {
    using xieite::functors::Function<Return(Argument)>::Function;

    template<std::convertible_to<Argument> ArgumentReference>
    friend constexpr Return operator>(const Mixfix&, ArgumentReference&&);

    template<std::convertible_to<Argument> ArgumentReference>
    friend constexpr Return operator<(ArgumentReference&&, const Mixfix&);
};
```
- [operator\>\<\>\(\)](./structures/mixfix/2/operators/more.md)
- [operator\<\<\>\(\)](./structures/mixfix/2/operators/less.md)
#### 3)
```cpp
template<typename Return, typename LeftArgument, typename RightArgument>
struct Mixfix<Return(LeftArgument, RightArgument)>
: xieite::functors::Function<Return(LeftArgument, RightArgument)> {
private:
    template<typename LeftArgumentReference>
    struct Intermediate;

public:
    using xieite::functors::Function<Return(LeftArgument, RightArgument)>::Function;

    template<std::convertible_to<LeftArgument> LeftArgumentReference>
    friend constexpr Mixfix::Intermediate<LeftArgumentReference> operator<(LeftArgumentReference&&, const Mixfix&) noexcept;
};
```
- [Intermediate \{\}](./structures/mixfix/3/intermediate.md)
- [operator\<\<\>\(\)](./structures/mixfix/3/operators/less.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::functors::Mixfix<int(int, int)> multiply = [](int x, int y) {
        return x * y;
    };

    xieite::functors::Mixfix<int(int)> increment = [](int x) {
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

# [xieite](../xieite.md)\:\:[functors](../functors.md)\:\:Infix
Defined in header [<xieite/functors/Infix.hpp>](../../include/xieite/functors/Infix.hpp)

&nbsp;

## Description
An infix operator thing.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename, auto>
struct Infix;
```
#### 2)
```cpp
template<typename Result, typename Argument, xieite::concepts::Functable<Result(Argument)> auto callback>
struct Infix<Result(Argument), callback> {
	constexpr Result operator>(const Argument&) const;

	friend constexpr Result operator<(const Argument&, const xieite::functors::Infix<Result(Argument), callback>);
};
```
##### Member functions
- [operator>](./Infix/2/operatorMore.md)
- [operator<](./Infix/2/operatorLess.md)
#### 3)
```cpp
template<typename Result, typename LeftArgument, typename RightArgument, xieite::concepts::Functable<Result(LeftArgument, RightArgument)> auto callback>
struct Infix<Result(LeftArgument, RightArgument), callback> {
	friend constexpr xieite::functors::Infix<Result(LeftArgument, RightArgument), callback>::Intermediate operator<(const LeftArgument&, const xieite::functors::Infix<Result(LeftArgument, RightArgument), callback>);
};
```
##### Member structures
- [Intermediate](./Infix/3/Intermediate.md)
##### Member functions
- [operator<](./Infix/3/operatorLess.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/Infix.hpp>

int main() {
    xieite::functors::Infix<int(int, int), [](int x, int y) {
        return x * y;
    }> multiply;

    xieite::functors::Infix<int(int), [](int x) {
        return x + 1;
    }> increment;

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

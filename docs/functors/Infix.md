# [xieite](../xieite.md)\:\:[functors](../functors.md)\:\:Infix
Defined in header [<xieite/functors/Infix.hpp>](../../include/xieite/functors/Infix.hpp)

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
template<std::invocable<xieite::types::Placeholder> Callback>
struct Infix<Callback> {
	constexpr Infix(const Callback& = Callback());

	constexpr xieite::functors::Result<Callback> operator>(const xieite::functors::Argument<Callback, 0>&) const;

	friend constexpr xieite::functors::Result<Callback> operator<(const xieite::functors::Argument<Callback, 0>&, const xieite::functors::Infix<Callback>&);
};
```
##### Member functions
- [Infix](./Infix/2/constructor.md)
- [operator>](./Infix/2/operatorMore.md)
- [operator<](./Infix/2/operatorLess.md)
#### 3)
```cpp
template<std::invocable<xieite::types::Placeholder, xieite::types::Placeholder> Callback>
struct Infix<Callback> {
	constexpr Infix(const Callback& = Callback());

	friend constexpr xieite::functors::Infix<Callback>::Intermediate operator<(const xieite::functors::Argument<Callback, 0>&, const xieite::functors::Infix<Callback>&);
};
```
##### Member structures
- [Intermediate](./Infix/3/Intermediate.md)
##### Member functions
- [Infix](./Infix/3/constructor.md)
- [operator<](./Infix/3/operatorLess.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/Infix.hpp>

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

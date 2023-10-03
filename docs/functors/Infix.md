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
template<std::invocable<xieite::types::Placeholder> auto callback>
struct Infix<callback> {
    template<typename Argument>
    requires(std::invocable<decltype(callback), const Argument&>)
    friend constexpr std::invoke_result_t<decltype(callback), const Argument&> operator>(xieite::functors::Infix<callback>, const Argument&);

    template<typename Argument>
    requires(std::invocable<decltype(callback), Argument&>)
    friend constexpr std::invoke_result_t<decltype(callback), Argument&> operator>(xieite::functors::Infix<callback>, Argument&);

    template<typename Argument>
    requires(std::invocable<decltype(callback), const Argument&>)
    friend constexpr std::invoke_result_t<decltype(callback), const Argument&> operator<(const Argument&, xieite::functors::Infix<callback>);

    template<typename Argument>
    requires(std::invocable<decltype(callback), Argument&>)
    friend constexpr std::invoke_result_t<decltype(callback), Argument&> operator<(Argument&, xieite::functors::Infix<callback>);
    };
```
##### Member functions
- [operator>](./Infix/2/operators/more.md)
- [operator<](./Infix/2/operators/less.md)
#### 3)
```cpp
template<std::invocable<xieite::types::Placeholder, xieite::types::Placeholder> auto callback>
class Infix<callback> {
private:
    template<typename LeftArgument>
    struct Intermediate;

public:
    template<typename LeftArgument>
    requires(std::invocable<decltype(callback), const LeftArgument&, xieite::types::Placeholder>)
    [[nodiscard]] friend constexpr Infix<callback>::Intermediate<const LeftArgument&> operator<(const LeftArgument&, xieite::functors::Infix<callback>) noexcept;

    template<typename LeftArgument>
    requires(std::invocable<decltype(callback), LeftArgument&, xieite::types::Placeholder>)
    [[nodiscard]] friend constexpr Infix<callback>::Intermediate<LeftArgument&> operator<(LeftArgument&, xieite::functors::Infix<callback>) noexcept;
};
```
##### Member structures
- [Intermediate](./Infix/3/Intermediate.md)
##### Member functions
- [operator<](./Infix/3/operators/less.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/Infix.hpp>

int main() {
    xieite::functors::Infix<[](int x, int y) {
        return x * y;
    }> multiply;

    xieite::functors::Infix<[](int x) {
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

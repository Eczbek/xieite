# [xieite](../xieite.md)\:\:[functors](../functors.md)\:\:Prefix
Defined in header [<xieite/functors/Prefix.hpp>](../../include/xieite/functors/Prefix.hpp)

&nbsp;

## Description
An prefix operator thing

&nbsp;

## Synopses

&nbsp;

```cpp
template<typename Type, xieite::concepts::Functable<Type> auto>
struct Prefix;
```
#### Template parameters
- `Type` - The function type
- unnamed `auto` value satisfying `xieite::concepts::Functable` of `Type`

&nbsp;

```cpp
template<typename Result, typename RightArgument, auto callback>
struct Prefix<Result(RightArgument), callback> {
    constexpr Result operator>(const RightArgument&) const;
};
```
#### Template parameters
- `Result` - The return type
- `RightArgument` - The right parameter type
- `callback` - A value of any type value
#### Public members
## Contents
`- <a href="./Prefix/operatorMode.md">operator></a>

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/Prefix.hpp>

int main() {
    xieite::functors::Prefix<int(int), [](int x) {
        return x + 1;
    }> increment;

    std::cout << (increment> 2) << '\n';
}
```
Output:
```
3
```

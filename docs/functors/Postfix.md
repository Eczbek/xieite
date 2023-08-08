# [xieite](../xieite.md)\:\:[functors](../functors.md)\:\:Postfix
Defined in header [<xieite/functors/Postfix.hpp>](../../include/xieite/functors/Postfix.hpp)

&nbsp;

## Description
A postfix operator thing

&nbsp;

## Synopses

&nbsp;

```cpp
template<typename Type, xieite::concepts::Functable<Type> auto>
struct Postfix;
```
#### Template parameters
- `Type` - The function type
- unnamed `auto` value satisfying `xieite::concepts::Functable` of `Type`

&nbsp;

```cpp
template<typename Result, typename LeftArgument, auto callback>
struct Postfix<Result(LeftArgument), callback> {
    friend constexpr Result operator<(const LeftArgument&, const xieite::functors::Postfix<Result(LeftArgument), callback>&);
};
```
#### Template parameters
- `Result` - The return type
- `LeftArgument` - The left parameter type
- `callback` - A value of any type value
#### Public members
## Contents
`- <a href="./Postfix/operatorMode.md">operator<</a>

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/Postfix.hpp>

int main() {
    xieite::functors::Postfix<int(int), [](int x) {
        return x - 1;
    }> decrement;

    std::cout << (2 <decrement) << '\n';
}
```
Output:
```
1
```

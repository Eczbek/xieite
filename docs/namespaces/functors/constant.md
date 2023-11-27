# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Constant
Defined in header [<xieite/functors/constant.hpp>](../../../include/xieite/functors/constant.hpp)

&nbsp;

## Description
Provides a wrapper for a mutable value.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct Constant {
    template<typename... Arguments>
    constexpr Constant(Arguments&&...);

    constexpr Type& operator()() const&;
};
```
##### Member functions
- [Constant](./structures/constant/1/operators/constructor.md)
- [operator()](./structures/constant/1/operators/call.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <random>
#include <xieite/functors/constant.hpp>

int main() {
	const auto generator = xieite::functors::Constant<std::mt19937>(std::random_device()());
	const auto distribution = xieite::functors::Constant<std::uniform_int_distribution<int>>(0, 10);

	std::cout << distribution()(generator()) << '\n';
}
Output:
```
foo
bar
```

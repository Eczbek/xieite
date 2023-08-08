# [xieite](../xieite.md)\:\:[math](../math.md)\:\:pi
Defined in header [<xieite/math/pi.hpp>](../../include/xieite/math/pi.hpp)

&nbsp;

## Description
Defines integer values of Pi

&nbsp;

## Synopses

&nbsp;

```cpp
template<typename>
inline constexpr double pi = std::numbers::pi;
```
#### Template parameters
- unnamed unconstrained type

&nbsp;

```cpp
template<std::floating_point Floating>
inline constexpr Floating pi<Floating> = std::numbers::pi_v<Floating>;
```
#### Template parameters
- `Floating` - A floating point type satisfying `std::floating_point`

&nbsp;

```cpp
template<std::integral Integer>
inline constexpr Integer pi<Integer> = static_cast<Integer>(std::numbers::pi);
```
#### Template parameters
- `Integer` - An integral type satisfying `std::integral`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/pi.hpp>

int main() {
    std::cout
        << xieite::math::pi<double> << '\n'
        << xieite::math::pi<int> << '\n';
}
```
Output:
```
3.14159
3
```

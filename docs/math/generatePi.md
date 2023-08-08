# [xieite](../xieite.md)\:\:[math](../math.md)\:\:generatePi
Defined in header [<xieite/math/generatePi.hpp>](../../include/xieite/math/generatePi.hpp)

&nbsp;

## Description
Calculates digits of Pi

&nbsp;

## Synopsis
```cpp
template<std::integral Integer = int>
constexpr std::vector<Integer> generatePi(std::size_t digits) noexcept;
```
#### Template parameters
- `Integer` - An integral type satisfying `std::integral`
#### Function parameters
- `digits` - A `std::size_t`, how many digits to calculate
#### Return type
- `std::vector` of `Integer`s, digits of Pi in order

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/generatePi.hpp>

int main() {
    for (int digit : xieite::math::generatePi(50)) {
        std::cout << digit;
    }
    std::cout << '\n';
}
```
Output:
```
31415926535897932384626433832795028841971693993751
```

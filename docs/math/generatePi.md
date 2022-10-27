# xieite::math::generatePi
Declared in `<xieite/math/generatePi.hpp>`
```cpp
template<std::integral V = int>
constexpr std::vector<V> generatePi(std::size_t digits) noexcept;
```
Generates digits of PI.
## Example
```cpp
#include <iostream>
#include <xieite/math/generatePi.hpp>

int main() {
    for (const int digit : xieite::math::generatePi(50))
        std::cout << digit;
    std::cout << '\n';
}
```
Output:
```
31415926535897932384626433832795028841971693993751
```

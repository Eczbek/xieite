# gcufl::math::fromBase
```cpp
template <std::integral N = int>
N fromBase(std::string_view value, const int base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
Converts a number from any base to base-10
## Example
```cpp
#include <iostream>
#include <gcufl/math>

int main() {
	std::cout << gcufl::math::fromBase("egg", 20) << '\n';
}
```
Output:
```
5936
```

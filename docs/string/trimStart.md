# xieite::string::trimStart
Defined in header `<xieite/string/trimStart.hpp>`

<br/>

Trims the start of a string.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr std::string trimStart(const std::string& string, char character) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::string trimStart(const std::string& string, std::vector<char>& characters) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/string/trimStart.hpp>

int main() {
	std::cout << xieite::string::trimStart("bababananana", { 'a', 'b' }) << '\n';
}
```
Output:
```
nanana
```

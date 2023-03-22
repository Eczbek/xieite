# xieite::string::trimEnd
Defined in header `<xieite/string/trimEnd.hpp>`

<br/>

Trims the end of a string.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr std::string trimEnd(const std::string& string, const char character) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::string trimEnd(const std::string& string, const std::vector<char>& characters) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/string/trimEnd.hpp>

int main() {
	std::cout << xieite::string::trimEnd("bababananana", { 'a', 'n' }) << '\n';
}
```
Output:
```
babab
```

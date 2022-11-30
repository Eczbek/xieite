# xieite::string::trimStart
Declared in `<xieite/string/trimStart.hpp>`

<br/>

Trims the start of a string.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
std::string trimStart(const std::string& string, const char character) noexcept;
```
```cpp
[[nodiscard]]
std::string trimStart(const std::string& string, const std::set<char>& characters) noexcept;
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

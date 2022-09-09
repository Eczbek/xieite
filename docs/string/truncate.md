# gcufl::string::truncate
Declared in `<gcufl/string/truncate.hpp>`
<br/><br/>
```cpp
std::string truncate(const std::string& string, const std::size_t length, const std::string& suffix = "") noexcept;
```
Replaces the end of a string.
## Example
```cpp
#include <gcufl/string/truncate.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::string::truncate("Hello, world!", 8, "...") << '\n';
}
```
Output:
```
Hello...
```

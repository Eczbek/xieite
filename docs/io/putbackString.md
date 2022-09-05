# gcufl::io::putbackString
```cpp
void putbackString(std::string_view string) noexcept;
```
Adds a string to the `std::cin` buffer.
## Example
```cpp
#include <gcufl/io.hpp>
#include <iostream>
#include <string>

int main() {
	gcufl::io::putbackString("Hello, world!\n");

	std::string input;
	std::getline(std::cin, input);
	std::cout << input << '\n';
}
```
Output:
```
Hello, world!
```

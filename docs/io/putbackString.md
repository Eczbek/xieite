# gcufl::io::putbackString
```cpp
void putbackString(std::string_view string) noexcept;
```
Adds a string to the `std::cin` buffer.
## Example
```cpp
#include <iostream>
#include <string>
#include <gcufl/io.hpp>

int main() {
	gcufl::io::putbackString("Hello, world!\n");

	std::string buffer;
	std::getline(std::cin, buffer);
	std::cout << buffer << '\n';
}
```
Output:
```
Hello, world!
```

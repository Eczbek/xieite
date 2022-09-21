# gcufl::files::read
Declared in `<gcufl/files/read.hpp>`
```cpp
std::string read(const std::string& path) noexcept;
```
Reads the content of a file into a `std::string`.
## Example
```cpp
#include <gcufl/files/read.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::files::read("./main.cpp") << '\n';
}
```
Possible output:
```
#include <gcufl/files/read.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::files::read("./main.cpp") << '\n';
}
```

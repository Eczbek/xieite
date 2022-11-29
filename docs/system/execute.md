# xieite::system::execute
Declared in `<xieite/system/execute.hpp>`
```cpp
std::string execute(const std::string_view command, const std::size_t bufferSize = 1024) noexcept;
```
Executes a command and returns its output.
## Example
```cpp
#include <iostream>
#include <xieite/system/execute.hpp>

int main() {
	std::cout << xieite::system::execute("echo Hello, world!");
}
```
Possible output:
```
Hello, world!
```

# xieite::system::execute
Declared in `<xieite/system/execute.hpp>`
```cpp
std::string execute(const std::string_view command) noexcept;
```
Executes a command and returns its output.
## Example
```cpp
#include <iostream>
#include <xieite/system/execute.hpp>

int main() {
	std::cout << xieite::system::execute("uuidgen");
}
```
Possible output:
```
55634ceb-cda3-4357-a5b6-4377ac3be926
```

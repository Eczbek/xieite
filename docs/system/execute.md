# gcufl::system::execute
Declared in `<gcufl/system/execute.hpp>`
```cpp
std::string execute(const std::string_view command) noexcept;
```
Executes a command and returns it's output.
## Example
```cpp
#include <gcufl/system/execute.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::system::execute("uuidgen");
}
```
Possible output:
```
55634ceb-cda3-4357-a5b6-4377ac3be926
```

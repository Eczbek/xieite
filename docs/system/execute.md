# xieite::system::execute
Declared in `<xieite/system/execute.hpp>`

<br/>

Executes a command and returns its output.

<br/><br/>

## Declaration
```cpp
std::string execute(const std::string_view command, const std::size_t bufferSize = 1024) noexcept;
```

<br/><br/>

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

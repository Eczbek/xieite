# xieite::system::execute
Defined in header `<xieite/system/execute.hpp>`

<br/>

Executes a command and returns its output.

<br/><br/>

## Declarations
```cpp
inline std::string execute(std::string_view command, std::size_t chunkSize = 1024) noexcept;
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

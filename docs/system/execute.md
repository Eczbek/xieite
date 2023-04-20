# `xieite::system::execute`
Defined in header [`<xieite/system/execute.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/system/execute.hpp)

<br/>

Executes a command and returns its output.

<br/><br/>

## Synopsis

<br/>

```cpp
inline std::string execute(std::string_view command, std::size_t chunkSize = 1024) noexcept;
```
### Parameters
- `command` - A `std::string_view` copy
- `chunkSize` - A `std::size_t` copy, how many bytes of the output to read at a time internally
### Return value
- A `std::string`

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

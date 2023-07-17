# [xieite](../xieite.md)::[system](../system.md)::execute
Defined in header [<xieite/system/execute.hpp>](../../include/xieite/system/execute.hpp)

<br/>

Executes a command and returns its output

<br/><br/>

## Synopsis

<br/>

```cpp
inline std::string execute(std::string_view command) noexcept;
```
### Parameters
- `command` - A `std::string_view` copy
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
Output:
```
Hello, world!
```

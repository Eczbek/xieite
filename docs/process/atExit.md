# [xieite](../../README.md)::[process](../process.md)::atExit
Defined in header [<xieite/process/atExit.hpp>](../../include/xieite/process/atExit.hpp)

<br/>

Executes given callbacks when the program ends. Is thread-safe

<br/><br/>

## Synopsis

<br/>

```cpp
inline void atExit(const std::function<void()>& callback) noexcept;
```
### Parameters
- `callback` - A constant reference to a `std::function` which accepts and returns nothing

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/process/atExit.hpp>

int main() {
	xieite::process::atExit([] {
		std::cout << "world!\n";
	});

	std::cout << "Hello, ";
}
```
Output:
```
Hello, world!
```

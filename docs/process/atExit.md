# xieite::process::atExit
Defined in header `<xieite/process/atExit.hpp>`

<br/>

Executes given callbacks when the program ends. Is thread-safe.

<br/><br/>

## Declarations
```cpp
inline void atExit(const std::function<void()>& callback) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/process/atExit.hpp>

int main() {
	xieite::process::atExit([]() -> void {
		std::cout << "Hello, world!\n";
	});
}
```
Output:
```cpp
Hello, world!
```

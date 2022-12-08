# xieite::console::setMode
Declared in `<xieite/console/setMode.hpp>`

<br/>

Enables or disables a mode in console. Possible modes are enumerated in `xieite::console::modes`.

<br/><br/>

## Declaration
```cpp
void setMode(const int mode, const bool value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/modes.hpp>
#include <xieite/console/setMode.hpp>

int main() {
	std::cout << "Hello, world!\n";
	xieite::console::setMode(xieite::console::modes::saveScreen, true);
	
	for (int i = 0; i < 10; ++i)
		std::cout << "spam eggs\n";
	
	xieite::console::setMode(xieite::console::modes::saveScreen, false);
}
```
Output:
```
Hello, world!
```

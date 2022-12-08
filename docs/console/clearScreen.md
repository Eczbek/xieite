# xieite::console::clearScreen
Declared in `<xieite/console/clearScreen.hpp>`

<br/>

Clears the entire screen.

<br/><br/>

## Declaration
```cpp
void clearScreen() noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/clearScreen.hpp>

int main() {
	std::cout << "Lots\nof\ntext!\n";
	xieite::console::clearScreen();
}
```
Output:
```
```

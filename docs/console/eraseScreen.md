# xieite::console::eraseScreen
Declared in `<xieite/console/eraseScreen.hpp>`

<br/>

Erases the entire screen.

<br/><br/>

## Declaration
```cpp
void eraseScreen() noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/eraseScreen.hpp>

int main() {
	std::cout << "Lots\nof\ntext!\n";
	xieite::console::eraseScreen();
}
```
Output:
```
```

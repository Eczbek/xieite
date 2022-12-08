# xieite::console::clearLine
Declared in `<xieite/console/clearLine.hpp>`

<br/>

Clears the line on which the cursor is.

<br/><br/>

## Declaration
```cpp
void clearLine() noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/clearLine.hpp>

int main() {
	std::cout << "Hello,";
	xieite::console::clearLine();
	std::cout << "world!\n";
}
```
Output:
```
world!
```

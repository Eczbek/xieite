# xieite::console::eraseLine
Declared in `<xieite/console/eraseLine.hpp>`

<br/>

Erases the line on which the cursor is.

<br/><br/>

## Declaration
```cpp
void eraseLine() noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/eraseLine.hpp>

int main() {
	std::cout << "Hello,";
	xieite::console::eraseLine();
	std::cout << "world!\n";
}
```
Output:
```
world!
```

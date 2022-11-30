# xieite::console::setStyle
Declared in `<xieite/console/setStyle.hpp>`

<br/>

Sets the text style.

<br/><br/>

## Declarations
```cpp
void setStyle(const char style) noexcept;

void setStyle(const char effect, const char foreground) noexcept;

void setStyle(const char effect, const char foreground, const char background) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/codes/foregrounds.hpp>
#include <xieite/console/setStyle.hpp>

int main() {
	xieite::console::setStyle(xieite::console::codes::foregrounds::brightRed);
	std::cout << "Hello, world!\n";
}
```
Output: (in bright red color)
```
Hello, world!
```

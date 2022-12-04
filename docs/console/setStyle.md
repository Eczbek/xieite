# xieite::console::setStyle
Declared in `<xieite/console/setStyle.hpp>`

<br/>

Sets the text style.

<br/><br/>

## Declarations
```cpp
void setStyle(const char style) noexcept;
```
```cpp
void setStyle(const char effect, const char foreground) noexcept;
```
```cpp
void setStyle(const char effect, const char foreground, const char background) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/styleForegrounds.hpp>
#include <xieite/console/setStyle.hpp>

int main() {
	xieite::console::setStyle(xieite::console::styleForegrounds::brightRed);
	std::cout << "Hello, world!\n";
}
```
Output: (in bright red color)
```
Hello, world!
```

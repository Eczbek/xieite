# xieite::console::codes
Defined in header `<xieite/console/codes.hpp>`

<br/>

A namespace of preset ANSI codes for terminal manipulation, to be printed directly. These should work in most terminals but not all are guaranteed to provide support.

<br/><br/>

## Definitions
```cpp
constexpr std::string_view enableBold = "\x1b[1m";
```
```cpp
constexpr std::string_view enableDim = "\x1b[2m";
```
```cpp
constexpr std::string_view enableItalic = "\x1b[3m";
```
```cpp
constexpr std::string_view enableUnderline = "\x1b[4m";
```
```cpp
constexpr std::string_view enableBlink = "\x1b[5m";
```
```cpp
constexpr std::string_view enableInverse = "\x1b[7m";
```
```cpp
constexpr std::string_view enableInvisible = "\x1b[8m";
```
```cpp
constexpr std::string_view enableStrikethrough = "\x1b[9m";
```
```cpp
constexpr std::string_view disableBold = "\x1b[21m";
```
```cpp
constexpr std::string_view disableDim = "\x1b[22m";
```
```cpp
constexpr std::string_view disableItalic = "\x1b[23m";
```
```cpp
constexpr std::string_view disableUnderline = "\x1b[24m";
```
```cpp
constexpr std::string_view disableBlink = "\x1b[25m";
```
```cpp
constexpr std::string_view disableInverse = "\x1b[27m";
```
```cpp
constexpr std::string_view disableInvisible = "\x1b[28m";
```
```cpp
constexpr std::string_view disableStrikethrough = "\x1b[29m";
```
```cpp
constexpr std::string_view eraseScreenFromCursor = "\x1b[0J";
```
```cpp
constexpr std::string_view eraseScreenUntilCursor = "\x1b[1J";
```
```cpp
constexpr std::string_view eraseScreen = "\x1b[2J";
```
```cpp
constexpr std::string_view eraseLineFromCursor = "\x1b[0K";
```
```cpp
constexpr std::string_view eraseLineUntilCursor = "\x1b[1K";
```
```cpp
constexpr std::string_view eraseLine = "\x1b[2K";
```
```cpp
constexpr std::string_view showCursor = "\x1b[?25h";
```
```cpp
constexpr std::string_view hideCursor = "\x1b[?25l";
```
```cpp
constexpr std::string_view saveScreen = "\x1b[?47h";
```
```cpp
constexpr std::string_view restoreScreen = "\x1b[?47l";
```
```cpp
constexpr std::string_view enableAlternativeBuffer = "\x1b[?1049h";
```
```cpp
constexpr std::string_view disableAlternativeBuffer = "\x1b[?1049l";
```
```cpp
constexpr std::string_view resetColors = "\x1b[0m";
```
```cpp
constexpr std::string_view resetForeground = "\x1b[38m";
```
```cpp
constexpr std::string_view resetBackground = "\x1b[48m";
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/console/codes.hpp>

int main() {
	std::cout
		<< "Hello, "
		<< xieite::console::codes::eraseLine
		<< "world!\n";
}
```
Output:
```
       world!
```

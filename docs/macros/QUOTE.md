# [`XIEITE`](../../docs/macros.md)`_QUOTE...`
Defined in header [`<xieite/macros/QUOTE.hpp>`](../../include/xieite/macros/QUOTE.hpp)

<br/>

Converts an expression to a string literally.

<br/><br/>

## Synopses

<br/>

```cpp
#define XIEITE_QUOTE(expressions...) \
	XIEITE_QUOTE_PRIMITIVE(expressions)
```
### Parameters
- `expressions` - Any expressions to be expanded

<br/>

```cpp
#define XIEITE_QUOTE_PRIMITIVE(expressions...) \
	#expressions
```
- `expressions` - Any expressions

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/QUOTE.hpp>

int main() {
	std::cout << XIEITE_QUOTE(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```

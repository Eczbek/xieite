# `XIEITE_QUOTE`
Defined in header [`<xieite/macros/QUOTE.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/macros/QUOTE.hpp)

<br/>

Converts an expression to a string literally.

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE_QUOTE(expression) \
	XIEITE_QUOTE_PRIMITIVE(expression)
```
### Parameters
- `expression` - Any expression

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

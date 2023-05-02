# [`XIEITE`](../../docs/macros.md)`_CONCATENATE...`
Defined in header [`<xieite/macros/CONCATENATE.hpp>`](../../include/xieite/macros/CONCATENATE.hpp)

<br/>

Concatenates two expressions literally.

<br/><br/>

## Synopses

<br/>

```cpp
#define XIEITE_CONCATENATE(expression1, expression2) \
	XIEITE_CONCATENATE_PRIMITIVE(expression1, expression2)
```
### Parameters
- `expression1` - Any expression to be expanded
- `expression2` - Any expression to be expanded

<br/>

```cpp
#define XIEITE_CONCATENATE_PRIMITIVE(expression1, expression2) \
	expression1 ## expression2
```
### Parameters
- `expression1` - Any expression
- `expression2` - Any expression

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/CONCATENATE.hpp>

int main() {
	std::cout << (XIEITE_CONCATENATE(4, 5) + 1) << '\n';
}
```
Output:
```
46
```

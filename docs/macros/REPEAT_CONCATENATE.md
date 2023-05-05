# [`XIEITE`](../../docs/macros.md)`_REPEAT_CONCATENATE`
Defined in header [`<xieite/macros/REPEAT_CONCATENATE.hpp>`](../../include/xieite/macros/REPEAT_CONCATENATE.hpp)

<br/>

Repeats the concatenation of an expression with itself.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
#define XIEITE_REPEAT_CONCATENATE(count, argument) \
	XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT_CONCATENATE, , argument)
```
### Parameters
- `count` - An unsigned value between 0 and 32767, inclusively
- `argument` - Any expression

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/REPEAT_CONCATENATE.hpp>

int main() {
	std::cout << (XIEITE_REPEAT_CONCATENATE(3, 5) + 1) << '\n';
}
```
Output:
```
556
```

<br/><br/>

## See also
- [`XIEITE_LOOP`](../../docs/macros/LOOP.md)

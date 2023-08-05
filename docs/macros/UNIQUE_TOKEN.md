# [XIEITE](../macros.md)\_UNIQUE\_TOKEN
Defined in header [<xieite/macros/UNIQUE_TOKEN.hpp>](../../include/xieite/macros/UNIQUE_TOKEN.hpp)

<br/>

Creates a unique token

<br/><br/>

## Synopsis

<br/>

```cpp
#define XIEITE__UNIQUE_TOKEN XIEITE__CONCATENATE(XIEITE_INTERNAL_UNIQUE_TOKEN_, __COUNTER__)
```

<br/><br/>

## Example
```cpp
#include <xieite/macros/UNIQUE_TOKEN.hpp>

int main() {
	int XIEITE__UNIQUE_TOKEN = 999;

	double XIEITE__UNIQUE_TOKEN = 3.14159;
}
```

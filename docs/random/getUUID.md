# [`xieite`](../../README.md)`::`[`random`](../../docs/random.md)`::getUUID`
Defined in header [`<xieite/random/getUUID.hpp>`](../../include/xieite/random/getUUID.hpp)

<br/>

Generates a UUID. Compile with `-luuid`.

<br/><br/>

## Synopsis

<br/>

```cpp
inline std::string getUUID() noexcept;
```
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/random/getUUID.hpp>

int main() {
	std::cout << xieite::random::getUUID() << '\n';
}
```
Very unlikely output:
```
bf59be9f-2e6d-4236-b456-e64161efd709
```

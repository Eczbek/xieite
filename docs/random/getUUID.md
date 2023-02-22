# xieite::random::getUUID
Defined in header `<xieite/random/getUUID.hpp>`

<br/>

Generates a UUID. Compile with `-luuid`.

<br/><br/>

## Declaration
```cpp
inline std::string getUUID() noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/random/getUUID.hpp>

int main() {
	std::cout << xieite::random::getUUID() << '\n';
}
```
Very unlikely output:
```
bf59be9f-2e6d-4236-b456-e64161efd709
```

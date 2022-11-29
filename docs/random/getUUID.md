# xieite::random::getUUID
Declared in `<xieite/random/getUUID.hpp>`
```cpp
std::string getUUID() noexcept;
```
Generates a UUID using `libuuid`.
## Example
```cpp
#include <iostream>
#include <xieite/random/getUUID.hpp>

int main() {
	std::cout << xieite::random::getUUID() << '\n';
}
```
Possible output:
```
bf59be9f-2e6d-4236-b456-e64161efd709
```

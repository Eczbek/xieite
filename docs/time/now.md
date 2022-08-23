# gcufl::time::now
```cpp
template <typename D = std::chrono::nanoseconds>
long now() noexcept;
```
Gets the current time duration.
## Example
```cpp
#include <iostream>
#include <gcufl/time>

int main() {
	std::cout << gcufl::time::now() << '\n';
}
```
Possible output:
```
1661279136481376354
```

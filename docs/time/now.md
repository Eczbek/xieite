# gcufl::time::now
```cpp
template <gcufl::traits::Duration D = std::chrono::nanoseconds>
D::rep now() noexcept;
```
Gets the current time duration.
## Example
```cpp
#include <gcufl/time.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::time::now() << '\n';
}
```
Possible output:
```
1661279136481376354
```

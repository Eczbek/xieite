# `gcufl::time::now`
Defined in `<gcufl/time/now.hpp>`
<br/><br/>
```cpp
template <gcufl::concepts::Duration D = std::chrono::nanoseconds>
D::rep now() noexcept;
```
Returns the current time since epoch.
## Example
```cpp
#include <gcufl/time/now.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::time::now() << '\n';
}
```
Possible output:
```
1661279136481376354
```

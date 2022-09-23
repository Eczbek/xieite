# gcufl::Timer::get
Declared in `<gcufl/Timer.hpp>`
```cpp
template<gcufl::concepts::Duration D = std::chrono::nanoseconds>
D::rep get() noexcept;
```
Gets the current value of a timer.
## Example
```cpp
#include <gcufl/Timer.hpp>
#include <iostream>
#include <vector>

int main() {
	gcufl::Timer timer;

	std::vector<bool> values;
	for (std::size_t i = 0; i < 1'000'000; ++i)
		values.push_back(i);

	std::cout << timer.get<std::chrono::milliseconds>() << '\n';
}
```
Possible output:
```
48
```

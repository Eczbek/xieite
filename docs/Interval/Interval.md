# gcufl::Interval::Interval
```cpp
template <std::invocable C, gcufl::traits::Duration D>
Interval(const C& callback, const D timeout) noexcept;
```
Starts an interval loop in a separate thread.
## Example
```cpp
#include <chrono>
#include <gcufl/Interval.hpp>
#include <iostream>

int main() {
	gcufl::Interval interval([]() {
		std::cout << "test\n";
	}, std::chrono::milliseconds(250));
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
```
Output (during 1 second):
```
test
test
test
test
```

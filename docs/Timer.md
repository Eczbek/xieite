# xieite::Timer
Declared in `<xieite/Timer.hpp>`

A simple timer.

## Constructor
```cpp
Timer() noexcept;
```

## Methods
```cpp
template<xieite::concepts::Duration D = std::chrono::nanoseconds>
[[nodiscard]]
D::rep get() noexcept;
		
void reset() noexcept;
```

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/Timer.hpp>

int main() {
	xieite::Timer timer;

	std::vector<std::size_t> values;
	for (std::size_t i = 0; i < 1'000'000; ++i)
		values.push_back(i);

	std::cout << timer.get<std::chrono::milliseconds>() << '\n';
}
```
Possible output:
```
26
```

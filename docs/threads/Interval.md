# `xieite::threads::Interval`
Defined in header [`<xieite/threads/Interval.hpp>`](../../include/xieite/threads/Interval.hpp)

<br/>

Runs a callback every set amount of time. Compile with `-pthread`.

<br/><br/>

## Synopsis

<br/>

### Member functions
- [`Interval`](../../docs/threads/Interval/constructor.md)
- [`~Interval`](../../docs/threads/Interval/destructor.md)
- [`good`](../../docs/threads/Interval/good.md)
- [`stop`](../../docs/threads/Interval/stop.md)

<br/><br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Interval.hpp>

int main() {
	xieite::threads::Interval interval([]() {
		static int i = 0;

		std::cout << ++i << '\n';
	}, std::chrono::seconds(1));

	std::this_thread::sleep_for(std::chrono::seconds(5));
}
```
Possible output:
```
1
2
3
4
```

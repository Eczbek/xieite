# [`xieite`](../../README.md)`::`[`threads`](../../docs/threads.md)`::Timeout`
Defined in header [`<xieite/threads/Timeout.hpp>`](../../include/xieite/threads/Timeout.hpp)

<br/>

Runs a callback once after a set amount of time. Compile with `-pthread`.

<br/><br/>

## Synopsis

<br/><br/>

### Member functions
- [`Timeout`](../../docs/threads/Timeout/constructor.md)
- [`~Timeout`](../../docs/threads/Timeout/destructor.md)
- [`good`](../../docs/threads/Timeout/good.md)
- [`stop`](../../docs/threads/Timeout/stop.md)

<br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Timeout.hpp>

int main() {
	xieite::threads::Timeout timeout([]() {
		std::cout << "Hello, world!\n";
	}, std::chrono::seconds(3));

	std::this_thread::sleep_for(std::chrono::seconds(1));

	timeout.stop();
}
```
Output:
```
```

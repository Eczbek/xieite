# `xieite::threads::Timeout`
Defined in header [`<xieite/threads/Timeout.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/threads/Timeout.hpp)

<br/>

Runs a callback once after a set amount of time. Compile with `-pthread`.

<br/><br/>

## Synopsis

<br/>

### Member functions
- [`Timeout`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Timeout/constructor.md)
- [`~Timeout`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Timeout/destructor.md)
- [`operator bool`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Timeout/operatorCast.md)
- [`cancel`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Timeout/cancel.md)

<br/><br/>

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

	timeout.cancel();
}
```
Output:
```
```

# [`xieite`](../../README.md)`::`[`threads`](../../docs/threads.md)`::Loop`
Defined in header [`<xieite/threads/Loop.hpp>`](../../include/threads/Loop.hpp)

<br/>

Runs a callback constantly. Compile with `-pthread`.

<br/><br/>

## Synopsis

<br/><br/>

### Member functions
- [`Loop`](../../docs/threads/Loop/constructor.md)
- [`~Loop`](../../docs/threads/Loop/destructor.md)
- [`good`](../../docs/threads/Loop/good.md)
- [`stop`](../../docs/threads/Loop/stop.md)

<br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Loop.hpp>

int main() {
	xieite::threads::Loop loop([]() {
		static int i = 0;

		std::this_thread::sleep_for(std::chrono::seconds(1));
		
		std::cout << ++i << '\n';
	});

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

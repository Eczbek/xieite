# `xieite::threads::Loop`
Defined in header [`<xieite/threads/Loop.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/threads/Loop.hpp)

<br/>

Runs a callback constantly. Compile with `-pthread`.

<br/><br/>

## Synopsis

<br/>

### Member functions
- [`Loop`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Loop/constructor.md)
- [`~Loop`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Loop/destructor.md)
- [`operator bool`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Loop/operatorCast.md)
- [`cancel`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Loop/cancel.md)

<br/><br/>

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

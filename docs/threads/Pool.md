# [xieite](../xieite.md)::[threads](../threads.md)::Pool
Defined in header [<xieite/threads/Pool.hpp>](../../include/xieite/threads/Pool.hpp)

<br/>

Creates a "pool" of threads for distributing jobs between. Compile with `-pthread`

<br/><br/>

## Synopsis

<br/>

```cpp
struct Pool {
	Pool(std::size_t = std::thread::hardware_concurrency());

	void setThreadCount(std::size_t);

	std::size_t getThreadCount() const;

	void enqueue(const std::function<void()>&);
};
```
### Public members
<pre><code>Pool/
|- <a href="./Pool/constructor.md">Pool</a>
|- <a href="./Pool/setThreadCount.md">setThreadCount</a>
|- <a href="./Pool/getThreadCount.md">getTHreadCount</a>
`- <a href="./Pool/enqueue.md">enqueue</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Pool.hpp>

int main() {
	xieite::threads::Pool loop([] {
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

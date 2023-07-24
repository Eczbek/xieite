# [xieite](../xieite.md)::[threads](../threads.md)::Timeout
Defined in header [<xieite/threads/Timeout.hpp>](../../include/xieite/threads/Timeout.hpp)

<br/>

Runs a callback once after a set amount of time. Compile with `-pthread`

<br/><br/>

## Synopsis

<br/>

```cpp
struct Timeout {
	template<std::invocable<> Invocable, xieite::concepts::TemporalDuration TemporalDuration>
	Timeout(const Invocable&, TemporalDuration) noexcept;

	bool good() const;

	void stop();
};
```
### Public members
<pre><code>Timeout/
|- <a href="./Timeout/constructor.md">Timeout</a>
|- <a href="./Timeout/good.md">good</a>
`- <a href="./Timeout/stop.md">stop</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Timeout.hpp>

int main() {
	xieite::threads::Timeout timeout([] {
		std::cout << "Hello, world!\n";
	}, std::chrono::seconds(3));

	std::this_thread::sleep_for(std::chrono::seconds(1));

	timeout.stop();
}
```
Output:
```
```

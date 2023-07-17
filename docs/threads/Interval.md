# [xieite](../xieite.md)::[threads](../threads.md)::Interval
Defined in header [<xieite/threads/Interval.hpp>](../../include/xieite/threads/Interval.hpp)

<br/>

Runs a callback every set amount of time. Compile with `-pthread`

<br/><br/>

## Synopsis

<br/>

```cpp
struct Interval {
	Interval(const std::invocable auto&, xieite::concepts::TemporalDuration auto);

	bool good() const;

	void stop();
};
```
### Public members
<pre><code>Interval/
|- <a href="./Interval/constructor.md">Interval</a>
|- <a href="./Interval/good.md">good</a>
`- <a href="./Interval/stop.md">stop</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Interval.hpp>

int main() {
	xieite::threads::Interval interval([] {
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

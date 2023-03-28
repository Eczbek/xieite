# xieite::threads::Interval
Defined in header `<xieite/threads/Interval.hpp>`

<br/>

Runs a callback every set amount of time. The `operator bool` checks whether the interval loop has been cancelled, and the `cancel` method will immediately return to the caller thread, without waiting for the interval loop to complete. Extends `xieite::threads::Loop`. Compile with `-pthread`.

<br/><br/>

## Constructors
```cpp
template<std::invocable<> Invocable>
Interval(Invocable&& callback, xieite::concepts::TemporalDuration auto duration) noexcept;
```

## Operators inherited from `xieite::threads::Loop`
```cpp
operator bool() const noexcept;
```
(`operator!` is defined implicitly)

## Other methods inherited from `xieite::threads::Loop`
```cpp
void cancel() noexcept;
```

<br/><br/>

## Example
```cpp
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Interval.hpp>

int main() {
	std::atomic<int> i = 0;

	xieite::threads::Interval interval([&i]() -> void {
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

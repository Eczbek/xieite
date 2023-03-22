# xieite::threads::Timeout
Defined in header `<xieite/threads/Timeout.hpp>`

<br/>

Runs a callback once after a set amount of time. The `operator bool` checks whether the callback has been cancelled, and the `cancel` method will immediately return to the caller thread, without waiting for the timeout to complete. Extends `xieite::threads::Interval`. Compile with `-pthread`.

<br/><br/>

## Constructors
```cpp
template<std::invocable<> Invocable>
Timeout(Invocable&& callback, const xieite::concepts::TemporalDuration auto duration) noexcept;
```

## Operators inherited from `xieite::threads::Interval`
```cpp
operator bool() const noexcept;
```
(`operator!` is defined implicitly)

## Other methods inherited from `xieite::threads::Interval`
```cpp
void cancel() noexcept;
```

<br/><br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Timeout.hpp>

int main() {
	xieite::threads::Timeout timeout([]() -> void {
		std::cout << "Hello, world!\n";
	}, std::chrono::seconds(3));

	std::this_thread::sleep_for(std::chrono::seconds(1));

	timeout.cancel();
}
```
Output:
```
```

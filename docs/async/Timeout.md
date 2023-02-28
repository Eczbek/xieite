# xieite::async::Timeout
Defined in header `<xieite/async/Timeout.hpp>`

<br/>

Runs a callback once after a set amount of time. The `operator bool` checks whether the callback has been cancelled, and the `cancel` method will immediately return to the caller thread, without waiting for the timeout to complete. Compile with `-pthread`.

<br/><br/>

## Constructors
```cpp
template<std::invocable<> C, xieite::concepts::TemporalDuration D>
Timeout(C&& callback, const D duration) noexcept;
```

## Destructors
```cpp
~Timeout();
```

## Operators
```cpp
operator bool() const noexcept;
```
(`operator!` is defined implicitly)

## Other methods
```cpp
void cancel() noexcept;
```

<br/><br/>

## Example
```cpp
#include <chrono> // std::chrono::seconds
#include <iostream> // std::cout
#include <thread> // std::this_thread::sleep_for
#include <xieite/async/Timeout.hpp>

int main() {
	xieite::async::Timeout timeout([]() -> void {
		std::cout << "Hello, world!\n";
	}, std::chrono::seconds(3));

	std::this_thread::sleep_for(std::chrono::seconds(1));

	timeout.cancel();
}
```
Output:
```
```

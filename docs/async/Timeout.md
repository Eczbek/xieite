# xieite::async::Timeout
Declared in `<xieite/async/Timeout.hpp>`

<br/>

Runs a callback after a set amount of time. Compile with `-pthread`.

<br/><br/>

## Constructor
```cpp
template<std::invocable<> C, xieite::concepts::Duration D>
inline Timeout(C&& callback, const D duration) noexcept;
```

## Destructor
```cpp
inline ~Timeout();
```

## Operators
```cpp
inline operator bool() const noexcept;
```
(`operator!` is defined implicitly)

## Other Methods
```cpp
inline void cancel() noexcept;
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

# xieite::async::Interval
Declared in `<xieite/async/Interval.hpp>`

<br/>

Runs a callback every set amount of time. Compile with `-pthread`.

<br/><br/>

## Constructor
```cpp
template<std::invocable<> C, xieite::concepts::Duration D>
inline Interval(C&& callback, const D duration) noexcept;
```

## Destructor
```cpp
inline ~Interval();
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
#include <atomic> // std::atomic
#include <chrono> // std::chrono::seconds
#include <iostream> // std::cout
#include <thread> // std::this_thread::sleep_for
#include <xieite/async/Interval.hpp>

int main() {
	std::atomic<int> i = 0;

	xieite::async::Interval interval([&i]() -> void {
		std::cout << ++i << '\n';
	}, std::chrono::seconds(1));

	std::this_thread::sleep_for(std::chrono::seconds(5));
}
```
Output:
```
1
2
3
4
```

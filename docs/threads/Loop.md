# xieite::threads::Loop
Defined in header `<xieite/threads/Loop.hpp>`

<br/>

Runs a thread-blocking callback constantly. The `operator bool` checks whether the loop has been cancelled, and the `cancel` method will immediately return to the caller thread, without waiting for the loop to complete. Compile with `-pthread`.

<br/><br/>

## Constructors
```cpp
template<std::invocable<> Invocable>
Loop(Invocable&& callback) noexcept;
```

## Destructor
```cpp
~Loop();
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
#include <xieite/threads/Loop.hpp>

int main() {
	xieite::threads::Loop loop([]() -> void {
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

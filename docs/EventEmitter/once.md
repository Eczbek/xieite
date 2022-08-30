# gcufl::EventEmitter:once
```cpp
template <typename... P, std::invocable<P...> C>
void once(const std::string& event, const C& callback) noexcept;
```
Adds a one-time-use event callback by key.
## Example
```cpp
#include <iostream>
#include <gcufl/EventEmitter.hpp>

int main() {
	gcufl::EventEmitter eventEmitter;

	eventEmitter.once<int, char>("print", [](const int a, const char b) {
		std::cout << a << ' ' << b << '\n';
	});

	eventEmitter.emit("print", 4, 'h');

	eventEmitter.emit("print", 7, 'm');
}
```
Output:
```
4, h
```

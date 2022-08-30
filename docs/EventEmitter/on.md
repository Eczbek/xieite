# gcufl::EventEmitter::on
```cpp
template <typename... P, std::invocable<P...> C>
void on(const std::string& event, const C& callback) noexcept;
```
Adds an event callback by key.
## Example
```cpp
#include <iostream>
#include <gcufl/EventEmitter.hpp>

int main() {
	gcufl::EventEmitter eventEmitter;

	eventEmitter.on<int, char>("print", [](const int a, const char b) {
		std::cout << a << ' ' << b << '\n';
	});

	eventEmitter.emit("print", 4, 'h');
}
```
Output:
```
4, h
```

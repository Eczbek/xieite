# gcufl::EventEmitter::off
```cpp
void off(const std::string& event) noexcept;
```
Removes an event by key.
## Example
```cpp
#include <iostream>
#include <gcufl/EventEmitter.hpp>

int main() {
	gcufl::EventEmitter eventEmitter;

	eventEmitter.on<int, char>("print", [](const int a, const char b) {
		std::cout << a << ", " << b << '\n';
	});

	eventEmitter.emit("print", 4, 'h');

	eventEmitter.off("print");

	eventEmitter.emit("print", 7, 'm');
}
```
Output:
```
4, h
```

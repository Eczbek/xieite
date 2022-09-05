# gcufl::EventEmitter::emit
```cpp
template <typename... A>
void emit(const std::string& event, A... arguments);
```
Emits an event by key with arguments.
## Example
```cpp
#include <gcufl/EventEmitter.hpp>
#include <iostream>

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

# gcufl::traits::Streamable
```cpp
template <typename V>
concept Streamable = requires(std::ostream& stream, const V& value);
```
A concept for streamable classes.
## Example
```cpp
#include <iostream>
#include <gcufl/traits.hpp>

template <gcufl::traits::Streamable V>
void print(const V& value) {
	std::cout << value;
}

int main() {
	print("Hello, world!\n");
}
```
Output:
```
Hello, world!
```

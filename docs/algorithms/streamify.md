# gcufl::algorithms::streamify
Declared in `<gcufl/algorithms/streamify.hpp>`
```cpp
template<std::forward_iterator I>
requires(gcufl::concepts::StreamableOut<typename std::iterator_traits<I>::value_type>)
constexpr std::stringstream streamify(I begin, const I end, const std::string_view delimiter = " ") noexcept;
```
Streams an iterable.
## Example
```cpp
#include <array>
#include <gcufl/algorithms/streamify.hpp>
#include <iostream>

int main() {
	std::array<int, 5> values { 1, 2, 3, 4, 5 };
	std::cout << gcufl::algorithms::streamify(values.begin(), values.end(), ", ").rdbuf() << '\n';
}
```
Output:
```
1, 2, 3, 4, 5
```

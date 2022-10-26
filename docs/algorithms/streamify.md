# xieite::algorithms::streamify
Declared in `<xieite/algorithms/streamify.hpp>`
```cpp
template<std::forward_iterator I>
requires(xieite::concepts::StreamableOut<typename std::iterator_traits<I>::value_type>)
[[nodiscard]]
constexpr std::stringstream streamify(I begin, const I end, const std::string_view delimiter = " ") noexcept;
```
Streams an iterable.
## Example
```cpp
#include <array>
#include <xieite/algorithms/streamify.hpp>
#include <iostream>

int main() {
	std::array<int, 5> values { 1, 2, 3, 4, 5 };
	std::cout << xieite::algorithms::streamify(values.begin(), values.end(), ", ").rdbuf() << '\n';
}
```
Output:
```
1, 2, 3, 4, 5
```

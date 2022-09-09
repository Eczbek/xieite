# `gcufl::math::wrap`
Defined in `<gcufl/math/wrap.hpp>`
<br/><br/>
```cpp
template <gcufl::concepts::Arithmetic N>
constexpr N wrap(const N value, const N max, const N min = 0) noexcept;
```
Wraps a number between two others.
<br/>
The limit `max` is exclusive.
## Example
```cpp
#include <gcufl/math/wrap.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::math::wrap(23, 4, -2) << '\n';
}
```
Output:
```
-1
```

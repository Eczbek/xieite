# [`xieite`](../../README.md)`::`[`types`](../../docs/types.md)`::count`
Defined in header [`<xieite/types/count.hpp>`](../../include/xieite/types/count.hpp)

<br/>

Counts the number of types passed.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename... Any>
inline constexpr std::size_t count = sizeof...(Any);
```
### Template parameters
- `Any...` - Any types

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/types/count.hpp>

int main() {
	std::cout << xieite::types::count<int, int, int> << '\n';
}
```
Output:
```
3
```

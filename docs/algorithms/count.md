# `xieite::algorithms::count`
Defined in header [`<xieite/algorithms/count.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/algorithms/count.hpp)

<br/>

Counts the number of arguments provided.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::size_t count(auto&&... arguments) noexcept;
```
### Parameters
- `arguments` - Any right-value references
### Return value
- A `std::size_t`, the number of arguments passed

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/count.hpp>

int main() {
	std::cout << xieite::algorithms::count(1, 0.4, 'e', "aaaaaaaaaaaa") << '\n';
}
```
Output:
```
4
```

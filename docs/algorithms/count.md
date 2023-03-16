# xieite::algorithms::count
Defined in header `<xieite/algorithms/count.hpp>`

<br/>

Counts the number of arguments provided.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr std::size_t count(auto&&... arguments) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/algorithms/count.hpp>

int main() {
	std::cout << xieite::algorithms::count(1, 0.4, 'e', "aaaaaaaaaaaa") << '\n';
}
```
Output:
```
4
```

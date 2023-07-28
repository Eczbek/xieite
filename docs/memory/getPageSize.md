# [xieite](../xieite.md)::[memory](../memory.md)::getPageSize
Defined in header [<xieite/memory/getPageSize.hpp>](../../include/xieite/memory/getPageSize.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
inline std::size_t getPageSize() noexcept;
```
### Return value
- A `std::size_t`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/memory/getPageSize.hpp>

int main() {
	std::cout << xieite::memory::getPageSize() << '\n';
}
```
Possible output:
```
4096
```

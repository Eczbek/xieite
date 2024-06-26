# [xieite](../../../../../xieite.md)\:\:[memory](../../../../../memory.md)\:\:[Shredder<Type_>](../../../shredder.md)\:\:data\<\>\(\)
Defined in header [<xieite/memory/shredder.hpp>](../../../../../../include/xieite/memory/shredder.hpp)

&nbsp;

## Description
Returns the underlying data.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self_>
[[nodiscard]] constexpr auto&& data(this Self_&&) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/memory/shredder.hpp"

int main() {
    xieite::memory::Shredder<int> thing = 5;

    std::println("{}", thing.data());
}
```
Output:
```
5
```

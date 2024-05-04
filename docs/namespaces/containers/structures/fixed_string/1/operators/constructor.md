# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedString<characters_, Character_>](../../../../fixed_string.md)\:\:FixedString\<\>\(\)
Defined in header [<xieite/containers/fixed_string.hpp>](../../../../../../../include/xieite/containers/fixed_string.hpp)

&nbsp;

## Description
Constructs a `xieite::containers::FixedString`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t otherCharacters_>
constexpr FixedString(const Character_(&data)[otherCharacters_]) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/fixed_string.hpp"

int main() {
    xieite::containers::FixedString string = "Hello, world!";

    std::println("{}", string.data);
}
```
Output:
```
Hello, world!
```

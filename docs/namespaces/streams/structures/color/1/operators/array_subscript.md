# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[Color<channels_>](../../../../color.md)\:\:operator\[\]\(\)
Defined in header [<xieite/streams/color.hpp>](../../../../../../../include/xieite/streams/color.hpp)

&nbsp;

## Description
Accesses a color channel by index.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self_>
[[nodiscard]] constexpr decltype(auto) operator[](this Self_&&, std::size_t index) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/color.hpp"

int main() {
    auto color = xieite::streams::Color<3>(0xFF7F00);

    std::println("{}", color[1]);
}
```
Output:
```
false
```

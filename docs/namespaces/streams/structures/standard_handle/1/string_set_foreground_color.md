# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringSetForegroundColor\<\>\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which sets the text color when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t channels>
requires(channels >= 3)
[[nodiscard]] static constexpr std::string stringSetForegroundColor(const xieite::graphics::Color<channels>& color) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/color.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string color = xieite::streams::StandardHandle::stringSetForegroundColor(xieite::streams::Color<3>(255, 0, 0));

    std::string message = color + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:

![image](./set_foreground_color.png)

# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringClearScreenFrom\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which, when printed, clears from the cursor until the end of the screen.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringClearScreenFrom() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string clear = xieite::streams::StandardHandle::stringClearScreenFrom();

    std::string message = "Hello,\nworld!\r" + clear;

    std::println("{}", message);
}
```
Possible output:
```
Hello,
      
```

# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringClearScreenUntil\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which, when printed, clears from the beginning of the screen until the cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringClearScreenUntil() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string clear = xieite::streams::StandardHandle::stringClearScreenUntil();

    std::string message = "Hello, " + clear + "world!";

    std::println("{}", message);
}
```
Possible output:
```
       world!
```

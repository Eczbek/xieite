# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringMoveCursorPosition\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which moves the terminal cursor's position when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringMoveCursorPosition(xieite::streams::Position difference) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/position.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string offset = xieite::streams::StandardHandle::stringMoveCursorPosition(xieite::streams::Position(2, 3));

    std::string message = offset + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:
```


  Hello, world!
```

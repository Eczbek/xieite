# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:timestamp
Defined in header [<xieite/strings/timestamp.hpp>](../../../include/xieite/strings/timestamp.hpp)

&nbsp;

## Description
Stringifies a `std::chrono::duration`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Duration Duration>
[[nodiscard]] constexpr std::string timestamp(Duration value, bool date = true, bool time = true, bool subsecond = false) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/metadata/compilation_timestamp.hpp"
#include "xieite/strings/timestamp.hpp"

int main() {
    std::println("{}", xieite::strings::timestamp(xieite::metadata::compilationTimestamp));
}
```
Output:
```
2024-01-16 00:41:24
```

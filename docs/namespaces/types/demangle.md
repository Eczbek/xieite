# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:demangle\(\)
Defined in header [<xieite/types/demangle.hpp>](../../../include/xieite/types/demangle.hpp)

&nbsp;

## Description
Demangles the value of `std::type_info::name()`. Returns the original string if demangling fails. Requires `XIEITE_COMPILER_TYPE_GCC` to be true.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] inline std::string demangle(const std::string& mangled) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/types/demangle.hpp"

template<typename>
struct Thing {};

int main() {
    std::string typeName = typeid(Thing<int>).name();

    std::println("{}", typeName);
    std::println("{}", xieite::types::demangle(typeName));
}
```
Possible output:
```
5ThingIiE
Thing<int>
```

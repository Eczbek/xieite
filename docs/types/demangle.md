# [xieite](../xieite.md)\:\:[types](../types.md)\:\:demangle
Defined in header [<xieite/types/demangle.hpp>](../../include/xieite/types/demangle.hpp)

&nbsp;

## Description
Demangles the name of a `std::type_info`. Returns original string if demangling fails

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
inline std::string demangle(std::string mangled) noexcept;
```
#### Function parameters
- `mangled` - A `std::string`, the mangled type name
#### Return type
- `std::string`

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/types/demangle.hpp>

template<typename>
struct Type {};

int main() {
    std::string typeName = typeid(Type<int>).name();

    std::cout
        << typeName << '\n'
        << xieite::types::demangle(typeName) << '\n';
}
```
Possible output:
```
4TypeIiE
Type<int>
```

# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:TypeWrapper \{\}
Defined in header [<xieite/types/type_wrapper.hpp>](../../../include/xieite/types/type_wrapper.hpp)

&nbsp;

## Description
A simple type wrapper for metaprogramming purposes.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
struct TypeWrapper {
    using Type = Type_;
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/name.hpp"
#include "xieite/types/type_wrapper.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::TypeWrapper<int>::Type>);
}
```
Possible output:
```
int
```

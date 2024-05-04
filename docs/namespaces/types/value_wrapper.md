# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:ValueWrapper\<\> \{\}
Defined in header [<xieite/types/value_wrapper.hpp>](../../../include/xieite/types/value_wrapper.hpp)

&nbsp;

## Description
A simple value wrapper for metaprogramming purposes.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename value_>
struct ValueWrapper {
    static constexpr auto value = value_;
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/value_wrapper.hpp"

int main() {
    std::println("{}", xieite::types::ValueWrapper<4>::value);
}
```
Possible output:
```
4
```

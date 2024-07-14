# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:ValueIdentity\<\> \{\}
Defined in header [<xieite/types/value_identity.hpp>](../../../include/xieite/types/value_identity.hpp)

&nbsp;

## Description
A simple value wrapper for metaprogramming purposes.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename value_>
struct ValueIdentity {
    static constexpr auto value = value_;
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/value_identity.hpp"

int main() {
    std::println("{}", xieite::types::ValueIdentity<4>::value);
}
```
Possible output:
```
4
```

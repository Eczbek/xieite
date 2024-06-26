# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleTo\<\>
Defined in header [<xieite/concepts/no_throw_convertible_to.hpp>](../../../include/xieite/concepts/no_throw_convertible_to.hpp)

&nbsp;

## Description
Specifies that a type can be converted to another without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename Target_>
concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<Source_, Target_>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <stdexcept>
#include "xieite/concepts/no_throw_convertible_to.hpp"

struct Nope {
    operator int() {
        throw std::runtime_error("nope");
    }
};

int main() {
    std::println("{}", xieite::concepts::NoThrowConvertibleTo<double, int>);
    std::println("{}", xieite::concepts::NoThrowConvertibleTo<Nope, int>);
}
```
Output:
```
true
false
```

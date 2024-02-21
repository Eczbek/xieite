# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleTo
Defined in header [<xieite/concepts/no_throw_convertible_to.hpp"](../../../include/xieite/concepts/no_throw_convertible_to.hpp)

&nbsp;

## Description
Specifies that a type can be converted to another without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename Target>
concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<Source, Target>;
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

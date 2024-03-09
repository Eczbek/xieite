# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:UnrepresentableValue
Defined in header [<xieite/exceptions/unrepresentable_value.hpp>](../../../include/xieite/exceptions/unrepresentable_value.hpp)

&nbsp;

An exception type that indicates an unrepresentable value. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct UnrepresentableValue
: xieite::exceptions::Unspecified {
    UnrepresentableValue(std::string_view = "");
};
```
##### Member functions
- [UnrepresentableValue](./structures/unrepresentable_value/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/unrepresentable_value.hpp"

int main() {
    throw xieite::exceptions::UnrepresentableValue("Something");
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::UnrepresentableValue'
  what():  Something
Aborted (core dumped)
```

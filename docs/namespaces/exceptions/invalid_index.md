# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:InvalidIndex
Defined in header [<xieite/exceptions/invalid_index.hpp>](../../../include/xieite/exceptions/invalid_index.hpp)

&nbsp;

An exception type that indicates accessing an invalid index in a range. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct InvalidIndex
: xieite::exceptions::Unspecified {
    InvalidIndex(std::string_view = "");
};
```
##### Member functions
- [InvalidIndex](./structures/invalid_index/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/invalid_index.hpp"

int main() {
    throw xieite::exceptions::InvalidIndex("Something");
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::InvalidIndex'
  what():  Something
Aborted (core dumped)
```

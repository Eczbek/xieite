# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:InvalidKey \{\}
Defined in header [<xieite/exceptions/invalid_key.hpp>](../../../include/xieite/exceptions/invalid_key.hpp)

&nbsp;

## Description
An exception type that indicates accessing an invalid key in a map or a set. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct InvalidKey
: xieite::exceptions::Unspecified {
    InvalidKey(std::string_view = "");
};
```
- [InvalidKey](./structures/invalid_key/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/invalid_key.hpp"

int main() {
    throw xieite::exceptions::InvalidKey("Something");
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::InvalidKey'
  what():  Something
Aborted (core dumped)
```

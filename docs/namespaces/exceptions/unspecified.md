# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:Unspecified \{\}
Defined in header [<xieite/exceptions/unspecified.hpp>](../../../include/xieite/exceptions/unspecified.hpp)

&nbsp;

## Description
An exception type that doesn't indicate anything in particular. Extends `std::exception`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Unspecified
: std::exception {
    Unspecified(std::string_view = "") noexcept;

    const char* what() const noexcept;
};
```
- [Unspecified](./structures/unspecified/1/operators/constructor.md)
- [what](./structures/unspecified/1/what.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/unspecified.hpp"

int main() {
    throw xieite::exceptions::Unspecified("Something");
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::Unspecified'
  what():  Something
Aborted (core dumped)
```

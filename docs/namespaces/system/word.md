# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:Word
Defined in header [<xieite/system/word.hpp>](../../../include/xieite/system/word.hpp)

&nbsp;

## Description
An alias to the system's unsigned "word" integer type. See header file for details.

&nbsp;

## Synopsis
#### 1)
```cpp
using Word = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/system/word.hpp"
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::system::Word>);
}
```
Possible output:
```
long unsigned int
```

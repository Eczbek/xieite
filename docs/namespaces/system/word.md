# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:Word
Defined in fragment [xieite:system.Word](../../../src/system/word.cpp)

&nbsp;

## Description
An alias to the system's unsigned "word" integer type. See definition for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
using Word = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::types::name<xieite::system::Word>);
}
```
Possible output:
```
long unsigned int
```

# [xieite](../../../../../xieite.md)\:\:[memory](../../../../../memory.md)\:\:[Shredder<Type>](../../../shredder.md)\:\:shred\(\)
Defined in fragment [xieite:memory.Shredder](../../../../../../src/memory/shredder.cpp)

&nbsp;

## Description
Shreds the stored data.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr void shred() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::memory::Shredder<int> thing = 5;

    thing.shred();

    std::println("{}", thing.shred());
}
```
Output:
```
0
```

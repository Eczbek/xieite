# [xieite](../../../../../xieite.md)\:\:[memory](../../../../../memory.md)\:\:[Shredder<Type>](../../../shredder.md)\:\:data\<\>\(\)
Defined in fragment [xieite:memory.Shredder](../../../../../../src/memory/shredder.cpp)

&nbsp;

## Description
Returns the underlying data.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self>
[[nodiscard]] constexpr auto&& data(this Self&&) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::memory::Shredder<int> thing = 5;

    std::println("{}", thing.data());
}
```
Output:
```
5
```

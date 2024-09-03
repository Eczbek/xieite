# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:Shredder \{\}
Defined in fragment [xieite:memory.Shredder](../../../src/memory/shredder.cpp)

&nbsp;

## Description
A wrapper that allows clearing its memory. Automatically shreds on destruction.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::TriviallyDestructible Type>
struct Shredder {
    constexpr Shredder() noexcept;

    template<typename... Arguments>
    requires(std::constructible_from<Type, Arguments...>)
    constexpr Shredder(Arguments&&...) noexcept;

    template<typename Self>
    constexpr auto&& data(this Self&&) noexcept;

    constexpr void shred() noexcept;
};
```
- [Shredder\<\>\(\)](./structures/shredder/1/operators/constructor.md)
- [data\<\>\(\)](./structures/shredder/1/data.md)
- [shred\(\)](./structures/shredder/1/shred.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    {
        int a = 4;
    }
    int b;
    std::println("{}", b);

    {
        xieite::memory::Shredder<int> c = 17;
    }
    int d;
    std::println("{}", d);
}
```
Possible output:
```
4
0
```

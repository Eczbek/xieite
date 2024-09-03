# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:BraceInitialize\<\> \{\}
Defined in fragment [xieite:functors.BraceInitialize](../../../src/functors/brace_initialize.cpp)

&nbsp;

## Description
A functor which simply brace-initializes a type with arguments.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
struct BraceInitialize {
    template<typename... Arguments>
    requires(xieite::concepts::BraceInitializable<Type, Arguments...>)
    constexpr Type operator()(Arguments&&...) const
    noexcept(xieite::concepts::NoThrowBraceInitializable<Type, Arguments...>);
};
```
- [operator\(\)\<\>\(\)](./structures/brace_initialize/1/operators/call.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Thing {
    int a;
    double b;
    void* c;
};

int main() {
    auto thing = xieite::functors::BraceInitialize<Thing>()(418, 3.14159, nullptr);

    std::println("{} {} {}", thing.a, thing.b, thing.c);
}
```
Possible output:
```
418 3.14159 0x0
```

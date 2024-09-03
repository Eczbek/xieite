# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAny\<\>
Defined in fragment [xieite:concepts.SameAsAny](../../../src/concepts/same_as_any.cpp)

&nbsp;

## Description
Specifies that a type is the same as at least one of several other types. Passing no target types evalutes to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsAny = (... || std::same_as<Source, Targets>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

template<xieite::concepts::SameAsAny<bool, char, int>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<char>();
    test<Nope>();
}
```
Output:
```
yep
nope
```

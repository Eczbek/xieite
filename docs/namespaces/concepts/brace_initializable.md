# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:BraceInitializable\<\>
Defined in fragment [xieite:concepts.BraceInitializable](../../../src/concepts/brace_initializable.cpp)

&nbsp;

## Description
Specifies that a type is brace-initializable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename... Arguments>
concept BraceInitializable = /* ... */;
```

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
    std::println("{}", xieite::concepts::BraceInitializable<Thing, float, bool&, decltype([] {})>);
    std::println("{}", xieite::concepts::BraceInitializable<Thing, int, double, void*>);
}
```
Output:
```
false
true
```

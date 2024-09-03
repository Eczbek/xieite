# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowBraceInitializable\<\>
Defined in fragment [xieite:concepts.NoThrowBraceInitializable](../../../src/concepts/no_throw_brace_initializable.cpp)

&nbsp;

## Description
Specifies that a type is brace-initializable without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename... Arguments>
concept NoThrowBraceInitializable = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Exceptional {
    Exceptional(const Exceptional&) {
        throw "nope";
    }
};

struct Foo {
    Exceptional x;
};

struct Bar {
    int x;
};

int main() {
    std::println("{}", xieite::concepts::NoThrowBraceInitializable<Foo, float***&&>);
    std::println("{}", xieite::concepts::NoThrowBraceInitializable<Foo, Exceptional>);
    std::println("{}", xieite::concepts::NoThrowBraceInitializable<Bar, int>);
}
```
Output:
```
false
false
true
```

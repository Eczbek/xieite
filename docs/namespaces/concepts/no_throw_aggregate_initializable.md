# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowAggregateInitializable\<\>
Defined in header [<xieite/concepts/no_throw_aggregate_initializable.hpp>](../../../include/xieite/concepts/no_throw_aggregate_initializable.hpp)

&nbsp;

## Description
Specifies that a type aggregate-initializable without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename... Arguments>
concept NoThrowAggregateInitializable = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/no_throw_aggregate_initializable.hpp"

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
    std::println("{}", xieite::concepts::NoThrowAggregateInitializable<Foo, float***&&>);
    std::println("{}", xieite::concepts::NoThrowAggregateInitializable<Foo, Exceptional>);
    std::println("{}", xieite::concepts::NoThrowAggregateInitializable<Bar, int>);
}
```
Output:
```
false
false
true
```

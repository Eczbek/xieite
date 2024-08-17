# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:AggregateInitializable\<\>
Defined in header [<xieite/concepts/aggregate_initializable.hpp>](../../../include/xieite/concepts/aggregate_initializable.hpp)

&nbsp;

## Description
Specifies that a type aggregate-initializable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename... Arguments>
concept AggregateInitializable = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/aggregate_initializable.hpp"

struct Thing {
    int a;
    double b;
    void* c;
};

int main() {
    std::println("{}", xieite::concepts::AggregateInitializable<Thing, float, bool&, decltype([] {})>);
    std::println("{}", xieite::concepts::AggregateInitializable<Thing, int, double, void*>);
}
```
Output:
```
false
true
```

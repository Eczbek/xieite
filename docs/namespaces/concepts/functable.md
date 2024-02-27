# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Functable
Defined in header [<xieite/concepts/functable.hpp>](../../../include/xieite/concepts/functable.hpp)

&nbsp;

## Description
Specifies that a functor type has a specific "signature" thing.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, typename Pointer>
concept Functable = xieite::traits::IsFunctable<Functor, Pointer>::value;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/functable.hpp"

template<xieite::concepts::Functable<int(int)>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test([](int x) -> int {
        return x;
    });

    test([](double) -> void {});
}
```
Output:
```
yep
nope
```

# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Functor\<\>
Defined in header [<xieite/concepts/functor.hpp>](../../../include/xieite/concepts/functor.hpp)

&nbsp;

## Description
Specifies that a functor type has a specific "signature" thing.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, typename Signature>
concept Functor = xieite::traits::IsFunctor<Functor, Signature>::value;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/functor.hpp"

template<xieite::concepts::Functor<int(int)>>
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

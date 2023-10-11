# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Functable
Defined in header [<xieite/concepts/functable.hpp>](../../../include/xieite/concepts/functable.hpp)

&nbsp;

## Description
Specifies that a type is a functor which accepts and returns specific types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Functor, typename Pointer>
concept Functable = xieite::traits::Functable<Functor, Pointer>::value;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/concepts/functable.hpp>

int main() {
    auto lambda = [](int x) {
        return x;
    };

    std::cout << std::boolalpha << xieite::concepts::Functable<decltype(lambda), int(int)> << '\n';
}
```
Output:
```
true
```
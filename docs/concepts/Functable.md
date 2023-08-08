# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Functable
Defined in header [<xieite/concepts/Functable.hpp>](../../include/xieite/concepts/Functable.hpp)

&nbsp;

## Description
Specifies that a type is a functor which accepts and returns specific types.

&nbsp;

## Synopsis
```cpp
template<typename Functor, typename Pointer>
concept Functable = xieite::traits::IsFunctable<Functor, Pointer>::value;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/concepts/Functable.hpp>

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

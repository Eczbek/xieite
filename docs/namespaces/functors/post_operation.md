# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:postOperation\<\>\(\)
Defined in header [<xieite/functors/post_operation.hpp>](../../../include/xieite/functors/post_operation.hpp)

&nbsp;

## Description
Returns a copy of a value before passing it to a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, std::invocable<Type_&> Functor_>
[[nodiscard]] constexpr Type_ postOperation(Type_& value, Functor_&& functor)
noexcept(xieite::concepts::NoThrowInvocable<Functor_, Type_&>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/post_operation.hpp"

int main() {
    int x = 5;

    auto increment = [](int& y) {
        y += 5;
    };

    std::println("{}", xieite::functors::postOperation(x, increment));
    std::println("{}", x);
}
```
Possible output:
```
5
10
```

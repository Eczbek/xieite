# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Hashable\<\>
Defined in header [<xieite/concepts/hashable.hpp>](../../../include/xieite/concepts/hashable.hpp)

&nbsp;

## Description
Specifies that a type is hashable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, typename Hasher_ = std::hash<Type_>>
concept Hashable = requires(Type_ value, Hasher_ hasher) {
    { std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/hashable.hpp"

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Hashable<int>);
    std::println("{}", xieite::concepts::Hashable<Nope>);
}
```
Output:
```
true
false
```

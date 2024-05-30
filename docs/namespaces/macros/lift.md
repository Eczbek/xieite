# [XIEITE](../../macros.md)\_LIFT\(\)
Defined in header [<xieite/macros/lift.hpp>](../../../include/xieite/macros/lift.hpp)

&nbsp;

## Description
"Lifts" a template function, allowing it to be invoked like a lambda. See header file for the definition. [Also, I found this blog post about it](https://devcodef1.com/news/1167084/lift-f-macro-behavior).

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_LIFT(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <functional>
#include <print>
#include "xieite/macros/lift.hpp"
#include "xieite/types/name.hpp"

template<typename T>
void foo(T&&) {
    std::println("{}", xieite::types::name<T>);
}

template<typename F>
void bar(F&& functor) {
    std::invoke(functor, 15);
}

int main() {
    bar(XIEITE_LIFT(foo));
}
```
Output:
```
int
```

# [XIEITE](../../macros.md)\_LIFT...\(\)
Defined in header [<xieite/lift.hpp>](../../../include/xieite/lift.hpp)

&nbsp;

## Description
"Lifts" a template function, allowing it to be invoked like a lambda. See definitions for specifics. Also, I found [this blog post](https://devcodef1.com/news/1167084/lift-f-macro-behavior) about it.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_LIFT(...) XIEITE_LIFT_CAPTURE(&, __VA_ARGS__)
```
#### 2)
```cpp
#define XIEITE_LIFT_CAPTURE(captures_, ...) /* ... */
```
`captures_` may optionally be wrapped in parentheses
#### 3)
```cpp
#define XIEITE_LIFT_PREFIX(...) XIEITE_LIFT_PREFIX_CAPTURE(&, __VA_ARGS__)
```
#### 4)
```cpp
#define XIEITE_LIFT_PREFIX_CAPTURE(captures_, ...) /* ... */
```
`captures_` may optionally be wrapped in parentheses
#### 5)
```cpp
#define XIEITE_LIFT_SUFFIX(...) XIEITE_LIFT_SUFFIX_CAPTURE(&, __VA_ARGS__)
```
#### 6)
```cpp
#define XIEITE_LIFT_SUFFIX_CAPTURE(captures_, ...) /* ... */
```
`captures_` may optionally be wrapped in parentheses
#### 7)
```cpp
#define XIEITE_LIFT_INFIX(...) XIEITE_LIFT_INFIX_CAPTURE(&, __VA_ARGS__)
```
#### 8)
```cpp
#define XIEITE_LIFT_INFIX_CAPTURE(captures_, ...) /* ... */
```
`captures_` may optionally be wrapped in parentheses
#### 9)
```cpp
#define XIEITE_LIFT_CONFIX(left_, right_) XIEITE_LIFT_CONFIG_CAPTURE(&, left_, right_)
```
either of `left_` and `right_` may optionally be wrapped in parentheses
#### 10)
```cpp
#define XIEITE_LIFT_CONFIX_CAPTURE(captures_, left_, right_) /* ... */
```
any of `captures_`, `left_`, and `right_` may optionally be wrapped in parentheses

&nbsp;

## Example
```cpp
#include <xieite/lift.hpp>

import std;
import xieite;

template<typename T>
void foo(T) {
    std::println("{}", xieite::types::name<T>);
}

template<typename F>
void bar(F functor) {
    std::invoke(functor, 15);
}

int main() {
    bar(XIEITE_LIFT(foo));
}
```
Possible output:
```
int
```

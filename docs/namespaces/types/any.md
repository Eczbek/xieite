# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Any \{\}
Defined in header [<xieite/types/any.hpp>](../../../include/xieite/types/any.hpp)

&nbsp;

## Description
A placeholder type for metaprogramming purposes. The provided member functions are not actually implemented.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Any {
    explicit(false) Any(auto&&...) noexcept;

    explicit(false) operator decltype(auto)() const noexcept;
};
```
- Any\<\>()
- operator typename\<\>()

&nbsp;

## [Example](../../../include/xieite/concepts/invocable_with_arity.hpp)

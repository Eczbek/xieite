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
    Any(auto&&...) noexcept;

    template<typename Type_>
    explicit(false) operator Type_&() const & noexcept;

    template<typename Type_>
    explicit(false) operator Type_&&() const && noexcept;
};
```
- Any\<\>()
- operator typename\<\>()

&nbsp;

## [Example](../../../include/xieite/concepts/invocable_with_argument_count.hpp)

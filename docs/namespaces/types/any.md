# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Any \{\}
Defined in fragment [xieite:types.Any](../../../src/types/any.cpp)

&nbsp;

## Description
A placeholder type for metaprogramming purposes. The provided member functions are not actually implemented.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Any {
    template<typename Type>
    explicit(false) operator Type() const noexcept;
};
```
- operator typename\<\>\(\)

&nbsp;

## [Example](../../../src/concepts/invocable_with_arity.cpp)

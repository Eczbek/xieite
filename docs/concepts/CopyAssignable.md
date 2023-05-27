# [xieite](../../README.md)::[concepts](../concepts.md)::CopyAssignable
Defined in header [<xieite/concepts/CopyAssignable.hpp>](../../include/xieite/concepts/CopyAssignable.hpp)

<br/>

Specifies that a type is copy-assignable

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept CopyAssignable = std::is_copy_assignable_v<Any>;
```
### Template parameters
- `Any` - Any type

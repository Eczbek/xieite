# `xieite::concepts::CopyAssignable`
Defined in header [`<xieite/concepts/CopyAssignable.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/concepts/CopyAssignable.hpp)

<br/>

Specifies that type `Any` is copy-assignable.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept CopyAssignable = std::is_copy_assignable_v<Any>;
```
### Template parameters
- `Any` - Any type

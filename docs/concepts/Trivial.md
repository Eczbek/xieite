# `xieite::concepts::Trivial`
Defined in header [`<xieite/concepts/Trivial.hpp>`](../../include/xieite/concepts/Trivial.hpp)

<br/>

Specifies that type `Any` is trivial.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Trivial = std::is_trivial_v<Any>;
```
### Template parameters
- `Any` - Any type

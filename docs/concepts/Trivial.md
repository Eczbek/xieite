# [xieite](../xieite.md)::[concepts](../concepts.md)::Trivial
Defined in header [<xieite/concepts/Trivial.hpp>](../../include/xieite/concepts/Trivial.hpp)

<br/>

Specifies that a type is trivial

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Trivial = std::is_trivial_v<Any>;
```
### Template parameters
- `Any` - Any type

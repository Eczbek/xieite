# [xieite](../xieite.md)::[concepts](../concepts.md)::Polymorphic
Defined in header [<xieite/concepts/Polymorphic.hpp>](../../include/xieite/concepts/Polymorphic.hpp)

<br/>

Specifies that a type is polymorphic

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Polymorphic = std::is_polymorphic_v<Any>;
```
### Template parameters
- `Any` - Any type

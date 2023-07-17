# [xieite](../xieite.md)::[concepts](../concepts.md)::Derivable
Defined in header [<xieite/concepts/Derivable.hpp>](../../include/xieite/concepts/Derivable.hpp)

<br/>

Specifies that a type can be derived from

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Derivable = std::is_class_v<Any> && !std::is_final_v<Any>;
```
### Template parameters
- `Any` - Any type

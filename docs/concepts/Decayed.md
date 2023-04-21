# `xieite::concepts::Decayed`
Defined in header [`<xieite/concepts/Decayed.hpp>`](../../include/xieite/concepts/Decayed.hpp)

<br/>

Specifies that type `Any` is decayed.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Decayed = std::same_as<Any, std::decay_t<Any>>;
```
### Template parameters
- `Any` - Any type

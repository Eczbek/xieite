# `xieite::concepts::Enumerator`
Defined in header [`<xieite/concepts/Enumerator.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/concepts/Enumerator.hpp)

<br/>

Specifies that type `Any` is an enumerator.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Enumerator = std::is_enum_v<Any>;
```
### Template parameters
- `Any` - Any type

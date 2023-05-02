# [`xieite`](../../README.md)`::`[`concepts`](../../docs/concepts.md)`::Enumerator`
Defined in header [`<xieite/concepts/Enumerator.hpp>`](../../include/xieite/concepts/Enumerator.hpp)

<br/>

Specifies that type `Any` is an enumerator.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<typename Any>
concept Enumerator = std::is_enum_v<Any>;
```
### Template parameters
- `Any` - Any type

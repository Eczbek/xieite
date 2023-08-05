# [xieite](../xieite.md)::[concepts](../concepts.md)::ChronoDuration
Defined in header [<xieite/concepts/ChronoDuration.hpp>](../../include/xieite/concepts/ChronoDuration.hpp)

<br/>

Specifies that a type is a `std::chrono::duration`

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept ChronoDuration = xieite::concepts::isChronoDuration<std::remove_cv_t<Any>>;
```
### Template parameters
- `Any` - Any type

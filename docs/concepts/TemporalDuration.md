# [xieite](../../README.md)::[concepts](../concepts.md)::TemporalDuration
Defined in header [<xieite/concepts/TemporalDuration.hpp>](../../include/xieite/concepts/TemporalDuration.hpp)

<br/>

Specifies that a type is a `std::chrono::duration`

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept TemporalDuration = xieite::concepts::isTemporalDuration<std::remove_cv_t<Any>>;
```
### Template parameters
- `Any` - Any type

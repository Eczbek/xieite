# `xieite::concepts::TemporalDuration`
Defined in header [`<xieite/concepts/TemporalDuration.hpp>`](../../include/xieite/concepts/TemporalDuration.hpp)

<br/>

Specifies that type `Any` is a `std::chrono::duration`.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept TemporalDuration = xieite::concepts::isTemporalDuration<std::remove_cv_t<Any>>;
```
### Template parameters
- `Any` - Any type

<br/><br/>

## See also
- [`xieite::traits::isTemporalDuration`](../../docs/traits/isTemporalDuration.md)

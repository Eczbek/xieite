# xieite::concepts::TemporalDuration
Defined in header `<xieite/concepts/TemporalDuration.hpp>`

<br/>

Specifies that type `Any` is a valid `std::chrono::duration`.

<br/><br/>

## Declarations
```cpp
template<typename Any>
concept TemporalDuration = xieite::concepts::isTemporalDuration<std::remove_cv_t<Any>>;
```

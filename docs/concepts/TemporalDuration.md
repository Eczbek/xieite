# xieite::concepts::TemporalDuration
Declared in `<xieite/concepts/TemporalDuration.hpp>`

<br/>

Specifies that a type `T` is a valid `std::chrono::duration`.

<br/><br/>

## Declaration
```cpp
template<typename T>
concept TemporalDuration = xieite::concepts::isTemporalDuration<std::remove_cv_t<T>>;
```

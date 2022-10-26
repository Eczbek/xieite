# xieite::concepts::Duration
Declared in `<xieite/concepts/Duration.hpp>`
```cpp
template<typename T>
concept Duration = xieite::concepts::isDuration<std::remove_cv_t<T>>;
```
Specifies that a type `T` is a valid `std::chrono::duration`.
## Example
See `xieite::time::now`.

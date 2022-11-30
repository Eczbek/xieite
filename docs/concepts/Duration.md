# xieite::concepts::Duration
Declared in `<xieite/concepts/Duration.hpp>`

<br/>

Specifies that a type `T` is a valid `std::chrono::duration`.

<br/><br/>

## Declaration
```cpp
template<typename T>
concept Duration = xieite::concepts::isDuration<std::remove_cv_t<T>>;
```

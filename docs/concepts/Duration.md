# gcufl::concepts::Duration
Defined in `<gcufl/concepts/Duration.hpp>`
<br/><br/>
```cpp
template <typename T>
concept Duration = gcufl::concepts::isDuration<std::remove_cv_t<T>>;
```
Specifies that a type `T` is a valid `std::chrono::duration`.
## Example
See `gcufl::time::now`.

# `xieite::concepts::NoThrowConvertibleTo`
Defined in header [`<xieite/concepts/NoThrowConvertibleTo.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/concepts/NoThrowConvertibleTo.hpp)

<br/>

Specifies that type `From` is convertible to type `To` without throwing an exception.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename From, typename To>
concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<From, To>;
```
### Template parametets
- `From` - Any type
- `To` - Any type

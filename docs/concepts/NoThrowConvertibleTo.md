# [xieite](../../README.md)::[concepts](../concepts.md)::NoThrowConvertibleTo
Defined in header [<xieite/concepts/NoThrowConvertibleTo.hpp>](../../include/xieite/concepts/NoThrowConvertibleTo.hpp)

<br/>

Specifies that a type is convertible to another type without throwing an exception

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

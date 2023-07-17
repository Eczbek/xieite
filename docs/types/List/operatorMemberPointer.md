# [xieite](../../xieite.md)::[types](../../types.md)::[List<Types...>](../List.md)::operator->*
Defined in header [<xieite/types/List.hpp>](../../../include/xieite/types/List.hpp)

<br/>

For use in `xieite::types::Unique`

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Type>
constexpr std::conditional_t<(std::is_same_v<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>> operator->*(const xieite::types::List<Type>);
```
### Template parameters
- `Type` - Any type
### Parameters
- An unnamed copy of `xieite::types::List` of `Type`
### Return type
- If at least one of `Types...` is the same as `Type`, then a `xieite::types::List` of `Types...`, otherwise of `Types...` and `Type`

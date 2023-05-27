# [xieite](../../README.md)::[concepts](../concepts.md)::Aggregate
Defined in header [<xieite/concepts/Aggregate.hpp>](../../include/xieite/concepts/Aggregate.hpp)

<br/>

Specifies that a type is aggregate

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Aggregate = std::is_aggregate_v<Any>;
```
### Template parameters
- `Any` - Any type

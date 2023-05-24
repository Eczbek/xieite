# [`xieite`](../../../README.md)`::`[`functions`](../../../docs/functions.md)`::`[`Suffix<Result, LeftParameter>`](../../../docs/functions/Suffix.md)`::Suffix`
Defined in header [`<xieite/functions/Suffix.hpp>`](../../../include/xieite/functions/Suffix.hpp)

<br/>

Creates a `xieite::functions::Suffix` operator.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Suffix(const xieite::concepts::Functional<Result(LeftParameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `xieite::concepts::Functional` of `Result` of `LeftParameter`

<br/><br/>

## See also
- [`xieite::concepts::Functional`](../../../docs/concepts/Functional.md)

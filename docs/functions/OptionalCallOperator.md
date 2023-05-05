# [`xieite`](../../README.md)`::`[`functions`](../../docs/functions.md)`::OptionalCallOperator`
Defined in header [`<xieite/functions/OptionalCallOperator.hpp>`](../../include/xieite/functions/OptionalCallOperator.hpp)

<br/>

A wrapper for any type which defines `operator()` if it does not exist.

<br/><br/>

## Synopses

<br/><br/>

### Template parameters
- `Any` - Any type satisfying `xieite::concepts::Derivable`
### Member functions
- [`OptionalCallOperator`](../../docs/functions/OptionalCallOperator/constructor.md)
- [`operator()`](../../docs/functions/OptionalCallOperator/operatorCall.md)

<br/><br/>

### Template parameters
- `Function` - Any type satisfying `xieite::concepts::Derivable`
### Requirements
- `Function` must be invocable with a `xieite::types::Anything`
### Member functions
- [`OptionalCallOperator`](../../docs/functions/OptionalCallOperator/constructor.md)
- [`operator()`](../../docs/functions/OptionalCallOperator/operatorCall.md)

<br/><br/>

## See also
- [`xieite::concepts::Derivable`](../../docs/concepts/Derivable.md)

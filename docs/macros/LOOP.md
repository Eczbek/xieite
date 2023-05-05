# [`XIEITE`](../../docs/macros.md)`_LOOP`
Defined in header [`<xieite/macros/LOOP.hpp>`](../../include/xieite/macros/LOOP.hpp)

<br/>

Repeats the execution of an macro.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
#define XIEITE_LOOP(count, macro, initial, ...) \
	XIEITE_CONCATENATE(XIEITE_INTERNAL_LOOP_, count)(macro, initial, __VA_ARGS__)
```
### Parameters
- `count` - An integer of value between 0 and 32767, inclusive
- `macro` - The macro to execute. Must accept parameters:
	- `count` - The current iteration
	- `previous` - Result of the previous execution
	- `...` - Same arguments as those passed initially
- `initial` - Initial "result" to be passed to the macro
- `...` - Arguments to apply to every execution

<br/><br/>

## See also
- [`XIEITE_CONCATENATE`](../../docs/macros/CONCATENATE.md)

# [xieite](../../README.md)::[math](../math.md)::Interval
Defined in header [<xieite/math/Interval.hpp>](../../include/xieite/math/Interval.hpp)

<br/>

A simple class for storing an interval between two numbers

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
struct Interval {
	Number start;
	Number end;

	constexpr Interval(Number, Number);
};
```
### Public members
<pre><code>Interval/
|- start
|- end
`- <a href="./Interval/constructor.md">Interval</a>
</code></pre>

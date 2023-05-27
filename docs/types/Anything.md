# [xieite](../../README.md)::[types](../types.md)::Anything
Defined in header [<xieite/types/Anything.hpp>](../../include/xieite/types/Anything.hpp)

<br/>

A simple structure which is declared to be convertible to anything. Useful for avoiding weird template deduction

<br/><br/>

## Synopsis

<br/>

```cpp
struct Anything final {
	template<typename Any>
	constexpr operator Any&() const;

	template<typename Any>
	constexpr operator Any&&() const;
};
```
### Public members
<pre><code>Anything/
`- <a href="./Anything/operatorCast.md">operator typename</a>
</code></pre>

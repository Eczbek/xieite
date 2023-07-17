# [xieite](../xieite.md)::[types](../types.md)::Anything
Defined in header [<xieite/types/Anything.hpp>](../../include/xieite/types/Anything.hpp)

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

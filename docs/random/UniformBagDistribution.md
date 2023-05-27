# [xieite](../../README.md)::[random](../random.md)::UniformBagDistribution
Defined in header [<xieite/random/UniformBagDistribution.hpp>](../../include/xieite/random/UniformBagDistribution.hpp)

<br/>

A "bag-randomization" distribution

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral>
struct UniformBagDistribution final {
	UniformBagDistribution(Integral, Integral);

	Integral operator()(xieite::concepts::UniformRandomBitGenerator auto&) const;
};
```
### Template Parameters
- Integral - Any type satisfying std::integral
### Public members
<pre><code>UniformBagDistribution/
|- <a href="./UniformBagDistribution/constructor.md">UniformBagDistribution</a>
`- <a href="./UniformBagDistribution/operatorCall.md">operator()</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <random>
#include <xieite/random/UniformBagDistribution.hpp>

int main() {
	std::default_random_engine rng(std::random_device {}());

	xieite::random::UniformBagDistribution<int> dist(0, 3);

	for (int i = 0; i < 10; ++i) {
		std::cout << dist(rng) << '\n';
	}
}
```
Possible output:
```
2
1
0
3
0
2
3
1
3
0
```

# [`xieite`](../../README.md)`::`[`random`](../../docs/random.md)`::UniformInterruptableDistribution`
Defined in header [`<xieite/random/UniformInterruptableDistribution.hpp>`](../../include/xieite/random/UniformInterruptableDistribution.hpp)

<br/>

A uniform random number distribution which allows excluding subintervals from the main interval.

<br/><br/>

## Synopsis

<br/>

### Template Parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Member functions
- [`UniformInterruptableDistribution`](../../docs/random/UniformInterruptableDistribution/constructor.md)
- [`operator()`](../../docs/random/UniformInterruptableDistribution/operatorCall.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <random>
#include <xieite/random/UniformInterruptableDistribution.hpp>

int main() {
	std::default_random_engine rng(std::random_device {}());

	std::vector<std::pair<int, int>> interruptions {
		{ 1, 4 }
	};

	xieite::random::UniformInterruptableDistribution<int> dist(0, 5, interruptions);

	for (int i = 0; i < 10; ++i) {
		std::cout << dist(rng) << '\n';
	}
}
```
Possible output:
```
0
5
5
5
0
0
5
5
0
5
```

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)

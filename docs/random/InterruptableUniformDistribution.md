# `xieite::random::InterruptableUniformDistribution`
Defined in header [`<xieite/random/InterruptableUniformDistribution.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/random/InterruptableUniformDistribution.hpp)

<br/>

A uniform random number distribution which allows excluding subintervals from the main interval.

<br/><br/>

## Synopsis

<br/>

### Template Parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`

<br/>

### Member functions
- [`InterruptableUniformDistribution`](https://github.com/Eczbek/xieite/tree/main/docs/random/InterruptableUniformDistribution/constructor.md)
- [`operator()`](https://github.com/Eczbek/xieite/tree/main/docs/random/InterruptableUniformDistribution/operatorCall.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <random>
#include <xieite/random/InterruptableUniformDistribution.hpp>

int main() {
	std::default_random_engine rng(std::random_device {}());

	std::vector<std::pair<int, int>> interruptions {
		{ 1, 4 }
	};

	xieite::random::InterruptableUniformDistribution<int> dist(0, 5, interruptions);

	for (int i = 0; i < 10; ++i)
		std::cout << dist(rng) << '\n';
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
- [`xieite::concepts::Arithmetic`](https://github.com/Eczbek/xieite/tree/main/docs/concepts/Arithmetic.md)

# gcufl::random::InterruptableUniformDistribution<N>::operator()
Declared in `<gcufl/random/InterruptableUniformDistribution.hpp>`
```cpp
template<gcufl::concepts::UniformRandomGenerator G>
constexpr N operator()(G& generator) noexcept;
```
## Example
```cpp
#include <gcufl/random/InterruptableUniformDistribution.hpp>
#include <iostream>
#include <random>

int main() {
	std::mt19937 rng(std::random_device {}());
	gcufl::random::InterruptableUniformDistribution<int> dist(0, 3, { { 1, 2 } });

	for (int i = 0; i < 10; ++i)
		std::cout << dist(rng) << '\n';
}
```
Possible output:
```
0
3
3
3
0
0
3
3
0
3
```
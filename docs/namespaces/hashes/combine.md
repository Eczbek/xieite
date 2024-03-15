# [xieite](../../xieite.md)\:\:[hashes](../../hashes.md)\:\:combine\(\)
Defined in header [<xieite/hashes/combine.hpp>](../../../include/xieite/hashes/combine.hpp)

&nbsp;

## Description
Combines multiple hashes... somehow. See header file.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Hash = std::size_t, std::convertible_to<Hash>... Hashes>
[[nodiscard]] constexpr Hash combine(Hash firstHash, Hashes... restHashes) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstddef>
#include <functional>
#include <print>
#include <utility>
#include "xieite/hashes/combine.hpp"

template<typename First, typename Second>
struct std::hash<std::pair<First, Second>> {
    std::size_t operator()(const std::pair<First, Second>& pair) const noexcept {
        return xieite::hashes::combine(std::hash<First>()(pair.first), std::hash<Second>()(pair.second));
    }
};

int main() {
    auto foo = std::make_pair<int, double>(418, 6.28318);

    std::println("{}", std::hash<std::pair<int, double>>()(foo));
}
```
Possible output:
```
17381505957047490560
```

# [xieite](../../../xieite.md)\:\:[errors](../../../errors.md)\:\:Type \{\}
Defined in header [<xieite/errors/type.hpp>](../../../include/xieite/errors/type.hpp)

&nbsp;

## Description
An enumeration of error types.

&nbsp;

## Synopsis
```cpp
enum struct Type {
	AllResultsExcluded,
	DimensionsMismatch,
	DivisionByZero,
	IndexOutOfRange,
	InvalidNetworkAddress,
	KeyOutOfMap,
	SkillIssue,
	UnrepresentableValue
};
```

&nbsp;

## Example
```cpp
#include <expected>
#include <print>
#include "xieite/errors/stringify.hpp"
#include "xieite/errors/type.hpp"

std::expected<int, xieite::errors::Type> test() {
    return std::unexpected(xieite::errors::Type::SkillIssue);
}

int main() {
    auto result = test();
    if (result.has_value()) {
        std::println("{}", result.value());
    } else {
        std::println("{}", xieite::errors::stringify(result.error()));
    }
}
```
Output:
```
Skill issue
```

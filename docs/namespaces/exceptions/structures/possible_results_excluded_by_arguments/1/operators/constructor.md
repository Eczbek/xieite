# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[PossibleResultsExcludedByArguments](../../../../possible_results_excluded_by_arguments.md)\:\:PossibleResultsExcludedByArguments
Defined in header [<xieite/exceptions/possible_results_excluded_by_arguments.hpp>](../../../../../../../include/xieite/exceptions/possible_results_excluded_by_arguments.hpp)

&nbsp;

Constructs a `xieite::exceptions::PossibleResultsExcludedByArguments`.

## Synopsis
#### 1)
```cpp
PossibleResultsExcludedByArguments(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/possible_results_excluded_by_arguments.hpp"

int main() {
    xieite::exceptions::PossibleResultsExcludedByArguments exception;

    std::println("{}", exception.what());
}
```
Output:
```

```

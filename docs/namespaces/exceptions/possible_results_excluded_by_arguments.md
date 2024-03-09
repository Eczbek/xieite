# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:PossibleResultsExcludedByArguments
Defined in header [<xieite/exceptions/possible_results_excluded_by_arguments.hpp>](../../../include/xieite/exceptions/possible_results_excluded_by_arguments.hpp)

&nbsp;

An exception type that indicates that all possible results of a function have been excluded by the arguments passed. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct PossibleResultsExcludedByArguments
: xieite::exceptions::Unspecified {
    PossibleResultsExcludedByArguments(std::string_view = "");
};
```
##### Member functions
- [PossibleResultsExcludedByArguments](./structures/possible_results_excluded_by_arguments/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/possible_results_excluded_by_arguments.hpp"

int main() {
    throw xieite::exceptions::PossibleResultsExcludedByArguments("Something");
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::PossibleResultsExcludedByArguments'
  what():  Something
Aborted (core dumped)
```

# [xieite](../xieite.md)\:\:[logic](../logic.md)\:\:any
Defined in header [<xieite/logic/any.hpp>](../../include/xieite/logic/any.hpp)

&nbsp;

## Description
Checks whether at least one passed argument is true. Expects all arguments to be converible to a boolean value

&nbsp;

## Synopsis
```cpp
template<std::convertible_to<bool>... Values>
[[nodiscard]]
constexpr bool any(const Values&... values)
noexcept(noexcept((std::is_nothrow_convertible_v<Values, bool> && ...)));
```
#### Template parameters
- `Values...` - Types satisfying `std::convertible_to` of `bool`
#### Function parameters
- `values...` - `Values...` constant references
#### Return type
- `bool` to represent whether or not all elements are true

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/logic/any.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::logic::any(false, 0, '\0') << '\n';
}
```
Output:
```
false
```

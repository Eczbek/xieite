# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:OrdinaryCharacter
Defined in header [<xieite/concepts/ordinary_character.hpp>](../../../include/xieite/concepts/ordinary_character.hpp)

&nbsp;

## Description
Specifies that a type is a narrow character, according to [the standard draft](https://eel.is/c++draft/basic.fundamental#7).

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept OrdinaryCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, signed char, unsigned char>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/ordinary_character.hpp"

int main() {
    std::println("{}", xieite::concepts::OrdinaryCharacter<char>);
    std::println("{}", xieite::concepts::OrdinaryCharacter<char8_t>);
}
```
Output:
```
true
false
```

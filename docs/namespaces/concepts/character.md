# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Character\<\>
Defined in fragment [xieite:concepts.Character](../../../src/concepts/character.cpp)

&nbsp;

## Description
Specifies that a type is a character, according to [the standard draft](https://eel.is/c++draft/basic.fundamental#11).

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Character = xieite::concepts::WideCharacter<Type> || xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, char8_t>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Character<signed char>);
    std::println("{}", xieite::concepts::Character<double>);
}
```
Output:
```
true
false
```

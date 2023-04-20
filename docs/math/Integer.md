# `xieite::math::Integer`
Defined in header [`<xieite/math/Integer.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/math/Integer.hpp)

<br/>

Allows creation of integer types of any bit size. All mathematical operators are defined.

<br/><br/>

## Synopsis

<br/>

### Template parameters
- `bits` - A `std::size_t` copy, how many bits the type can use
- `sing` - A `bool` copy, whether or not the type is signed

<br/>

### Member functions
- [`Integer`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/constructor.md)
- [`operator=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorAssign.md)
- [`operator typename`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorCast.md)
- [`operator!`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorNot.md)
- [`operator==`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorEquals.md)
- [`operator<=>`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorSpaceship.md)
- [`operator+`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorAdd.md)
- [`operator+=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorAddAssign.md)
- [`operator++`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorIncrement.md)
- [`operator-`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorSubtract.md)
- [`operator-=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorSubtractAssign.md)
- [`operator--`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorDecrement.md)
- [`operator*`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorMultiply.md)
- [`operator*=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorMultiplyAssign.md)
- [`operator/`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorDivide.md)
- [`operator/=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorDivideAssign.md)
- [`operator%`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorModulo.md)
- [`operator%=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorModuloAssign.md)
- [`operator~`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseNot.md)
- [`operator&`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseAnd.md)
- [`operator&=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseNotAssign.md)
- [`operator|`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseOr.md)
- [`operator|=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseOrAssign.md)
- [`operator^`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseXor.md)
- [`operator^=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseXorAssign.md)
- [`operator<<`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseShiftLeft.md)
- [`operator<<=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseShiftLeftAssign.md)
- [`operator>>`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseShiftRight.md)
- [`operator>>=`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer/operatorBitwiseShiftRightAssign.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

using Int3 = xieite::math::Integer<3, true>;
using UInt17 = xieite::math::Integer<17, false>;

int main() {
	Int3 a = 5;
	UInt17 b = 5;

	std::cout << std::boolalpha << (a == b) << '\n';
}
```
Output:
```
true
```

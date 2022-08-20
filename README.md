# C++ Utility Library

<br/>

### Usage examples:

#### alg
```cpp
#include <util/alg>

std::array<int, 3> a { 1, 2, 3 };
std::array<int, 3> b { 3, 1, 2 };

util::alg::rotatedMatch(a.begin(), a.end(), b.begin(), b.end()); // true
```

#### fs
```cpp
#include <util/fs>

util::fs::write("data.txt", 4);
util::fs::append("data.txt", 'd');

util::fs::read("data.txt"); // "4d"
```

#### geom
```cpp
// todo
```

#### io
```cpp
#include <util/io>

util::io::RawLock lock1;
lock1.~RawLock();

util::io::NonBlockLock lock2;
lock2.~NonBlockLock();

util::io::waitChar(); // 

util::io::putbackString("abcd");

util::io::readChar(); // 'a'
util::io::readString(2); // "bc"

util::io::getWindowSize(); // Position { 24, 80 }

util::io::cursor::getPos(); // Position { 0, 0 }
util::io::cursor::setPos({ 0, 0 });
util::io::cursor::move(direction::Down, 3);

std::cout << util::io::style::fg::brightRed << "Hello, world!\n";
```

#### macro
```cpp
#include <util/macro>

class Singleton {
	MAKE_SINGLETON(Singleton);
public:
	int value = 4;
};
Singleton::getInstance().value; // 4
```

#### map
```cpp
#include <util/map>

util::OrderedMap<char, bool> map;
map['a'] = true;

map['a']; // true
map['b']; // false
```

#### math
```cpp
#include <util/math>

util::math::wrap(6, 5, -3); // -2

util::math::approxEqual(0.1 + 0.2, 0.3); // true

util::math::sign(-56037); // -1

util::math::degToRad(180); // 3.14159
util::math::radToDeg(3.14159); // 180

util::math::baseTo(13, 16); // "d"
util::math::baseFrom("d", 16); // 16
```

#### num
```cpp
#include <util/num>

util::num::tau; // 6.28318
```

#### os
```cpp
#include <util/os>

util::thisOS == util::os::Unix; // true
```

#### str
```cpp
#include <util/str>

util::str::split("abc", ""); // std::vector<std::string> { "a", "b", "c" }
util::str::split("a b c", ' '); // std::vector<std::string> { "a", "b", "c" }

util::str::trunc("0123456789", 8, "..."); // "01234..."

util::str::trimLeft("--l--", '-'); // "l--"
util::str::trimRight("--l--", '-'); // "--l"

util::str::trimLeft("-=l-=", "=-"); // "l-="
util::str::trimRight("-=l-=", "=-"); // "-=l"
```

#### time
```cpp
#include <util/time>

util::time::months[4]; // "May"

util::time::week_days[2]; // "Tuesday"

util::time::now<std::chrono::milliseconds>(); // 1657814519827
```

### trait
```cpp
// todo
```

#### vect
```cpp
#include <util/vect>

util::vect::group({ 1, 2, 3, 4 }, [](const int value) -> std::string {
	return (value > 2) ? "big" : "small";
}); /*
std::unordered_map<std::string, std::vector<int>> {
	{ "big", { 3, 4 } },
	{ "small", { 1, 2 } }
}
*/

std::vector<std::vector<int>> vector2D {
	{ 1, 2, 3 },
	{ 4, 5, 6 }
};

util::vect::rotateCW(vector2D); /*
std::vector<std::vector<int>> {
	{ 4, 1 },
	{ 5, 2 },
	{ 6, 3 }
}
*/
util::vect::rotateCCW(vector2D); /*
std::vector<std::vector<int>> {
	{ 3, 6 },
	{ 2, 5 },
	{ 1, 4 }
}
*/
```

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
using namespace util::fs;

write("data.txt", 4);
append("data.txt", 'd');

read("data.txt"); // "4d"
```

#### geom
```cpp
// todo
```

#### io
```cpp
#include <util/io>
using namespace util::io;

RawLock lock1;
lock1.~RawLock();

NonBlockLock lock2;
lock2.~NonBlockLock();

waitChar(); // 

putbackString("abcd");

readChar(); // 'a'
readString(2); // "bc"

getWindowSize(); // Position { 24, 80 }

cursor::getPos(); // Position { 0, 0 }
cursor::setPos({ 0, 0 });
cursor::move(direction::Down, 3);

std::cout << style::fg::brightRed << "Hello, world!\n";
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
using namespace util::math;

wrap(6, 5, -3); // -2

approxEqual(0.1 + 0.2, 0.3); // true

sign(-56037); // -1

degToRad(180); // 3.14159
radToDeg(3.14159); // 180

baseTo(13, 16); // "d"
baseFrom("d", 16); // 16
```

#### num
```cpp
#include <util/num>

util::num::tau; // 6.28318
```

#### os
```cpp
#include <util/os>

util::thisOS == util::os::unix; // true
```

#### str
```cpp
#include <util/str>
using namespace util::str;

split("abc", ""); // std::vector<std::string> { "a", "b", "c" }
split("a b c", ' '); // std::vector<std::string> { "a", "b", "c" }

trunc("0123456789", 8, "..."); // "01234..."

trimLeft("--l--", '-'); // "l--"
trimRight("--l--", '-'); // "--l"

trimLeft("-=l-=", "=-"); // "l-="
trimRight("-=l-=", "=-"); // "-=l"
```

#### time
```cpp
#include <util/time>
using namespace util::time;

months[4]; // "May"

week_days[2]; // "Tuesday"

now<std::chrono::milliseconds>(); // 1657814519827
```

#### vect
```cpp
#include <util/vect>
using namespace util::vect;

group({ 1, 2, 3, 4 }, [](const int value) -> std::string {
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

rotateCW(vector2D); /*
std::vector<std::vector<int>> {
	{ 4, 1 },
	{ 5, 2 },
	{ 6, 3 }
}
*/
rotateCCW(vector2D); /*
std::vector<std::vector<int>> {
	{ 3, 6 },
	{ 2, 5 },
	{ 1, 4 }
}
*/
```

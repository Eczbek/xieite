# GCUFL

<br/>

### Usage examples:

#### alg
```cpp
#include <gcufl/alg>

std::array<int, 3> a { 1, 2, 3 };
std::array<int, 3> b { 3, 1, 2 };

gcufl::alg::rotatedMatch(a.begin(), a.end(), b.begin(), b.end()); // true
```

#### fs
```cpp
#include <gcufl/fs>

gcufl::fs::write("data.txt", 4);
gcufl::fs::append("data.txt", 'd');

gcufl::fs::read("data.txt"); // "4d"
```

#### geom
```cpp
// todo
```

#### io
```cpp
#include <gcufl/io>

gcufl::io::RawLock lock1;
lock1.~RawLock();

gcufl::io::NonBlockLock lock2;
lock2.~NonBlockLock();

gcufl::io::waitChar(); // 

gcufl::io::putbackString("abcd");

gcufl::io::readChar(); // 'a'
gcufl::io::readString(2); // "bc"

gcufl::io::getWindowSize(); // Position { 24, 80 }

gcufl::io::cursor::getPos(); // Position { 0, 0 }
gcufl::io::cursor::setPos({ 0, 0 });
gcufl::io::cursor::move(direction::Down, 3);

std::cout << gcufl::io::style::fg::brightRed << "Hello, world!\n";
```

#### macro
```cpp
#include <gcufl/macro>

class Singleton {
	MAKE_SINGLETON(Singleton);
public:
	int value = 4;
};
Singleton::getInstance().value; // 4
```

#### map
```cpp
#include <gcufl/map>

gcufl::OrderedMap<char, bool> map;
map['a'] = true;

map['a']; // true
map['b']; // false
```

#### math
```cpp
#include <gcufl/math>

gcufl::math::wrap(6, 5, -3); // -2

gcufl::math::approxEqual(0.1 + 0.2, 0.3); // true

gcufl::math::sign(-56037); // -1

gcufl::math::degToRad(180); // 3.14159
gcufl::math::radToDeg(3.14159); // 180

gcufl::math::baseTo(13, 16); // "d"
gcufl::math::baseFrom("d", 16); // 16
```

#### num
```cpp
#include <gcufl/num>

gcufl::num::tau; // 6.28318
```

#### os
```cpp
#include <gcufl/os>

gcufl::thisOS == gcufl::os::Unix; // true
```

#### str
```cpp
#include <gcufl/str>

gcufl::str::split("abc", ""); // std::vector<std::string> { "a", "b", "c" }
gcufl::str::split("a b c", ' '); // std::vector<std::string> { "a", "b", "c" }

gcufl::str::trunc("0123456789", 8, "..."); // "01234..."

gcufl::str::trimLeft("--l--", '-'); // "l--"
gcufl::str::trimRight("--l--", '-'); // "--l"

gcufl::str::trimLeft("-=l-=", "=-"); // "l-="
gcufl::str::trimRight("-=l-=", "=-"); // "-=l"
```

#### time
```cpp
#include <gcufl/time>

gcufl::time::months[4]; // "May"

gcufl::time::week_days[2]; // "Tuesday"

gcufl::time::now<std::chrono::milliseconds>(); // 1657814519827
```

### trait
```cpp
// todo
```

#### vect
```cpp
#include <gcufl/vect>

gcufl::vect::group({ 1, 2, 3, 4 }, [](const int value) -> std::string {
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

gcufl::vect::rotateCW(vector2D); /*
std::vector<std::vector<int>> {
	{ 4, 1 },
	{ 5, 2 },
	{ 6, 3 }
}
*/
gcufl::vect::rotateCCW(vector2D); /*
std::vector<std::vector<int>> {
	{ 3, 6 },
	{ 2, 5 },
	{ 1, 4 }
}
*/
```

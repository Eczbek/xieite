# MAKE_SINGLETON
```cpp
#define MAKE_SINGLETON(Singleton)
```
Creates basic singleton code
## Example
```cpp
#include <iostream>
#include <gcufl/macro>

class Singleton {
	MAKE_SINGLETON(Singleton);

public:
	int value = 4;
};

int main() {
	std::cout << Singleton::getInstance().value << '\n';
}
```
Output:
```
4
```

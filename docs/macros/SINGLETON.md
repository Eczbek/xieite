# GCUFL_SINGLETON
Declared in `<gcufl/macros/SINGLETON.hpp>`
```cpp
#define GCUFL_SINGLETON(Class)                  \
    private:                                   \
        Class() {}                             \
    public:                                    \
        static Class& getInstance() noexcept { \
            static Class instance;             \
            return instance;                   \
        }                                      \
        Class(const Class&) = delete;          \
        Class& operator=(const Class&) = delete;
```
Inserts methods into a class, which include basic singleton constructors, `operator=`, and `getInstance`.
## Example
```cpp
#include <gcufl/macros/SINGLETON.hpp>
#include <iostream>

class Singleton {
	GCUFL_SINGLETON(Singleton);
public:
	int a = 4;
};

int main() {
	std::cout << Singleton::getInstance().a << '\n';
}
```
Output:
```
4
```

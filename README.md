# **XIEITE**
C++ utility library

This project extends the standard library without external dependencies and provides a somewhat organized collection of questionably useful tools for assisting in various shenanigans

&nbsp;

## [Documentation](https://github.com/Eczbek/xieite/tree/main/docs/xieite.md)
Written manually :)

&nbsp;

## Requirements
- C++26
- GCC 15
- Clang 18
- MSVC 19.34

&nbsp;

## Building
```
git clone https://github.com/Eczbek/xieite
cd xieite
```
good luck; nothing supports modules yet

&nbsp;

## Examples
### [xieite::math::BigInteger\<\> \{\}](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/math/big_integer.md)
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::BigInteger(99).power(99).string());
}
```

&nbsp;

### [xieite::types::name\<\>](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/types/name.md)
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::types::name<float>);
}
```

&nbsp;

### [xieite::streams::StandardHandle \{\}](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/streams/standard_handle.md)
```cpp
#include <cstdio>
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);
    char input = terminal.readCharacter();
    std::println("{}", input);
}
```

&nbsp;

### [xieite::functors::recursivelyDistributeArguments\<\>\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/functors/recursively_distribute_arguments.md)
```cpp
import std;
import xieite;

int main() {
    auto add = [](int x, int y) { return x + y; };
    int sum = xieite::functors::recursivelyDistributeArguments<2>(add, 1, 2, 3, 4, 5);
    std::println("{}", sum);
}
```

&nbsp;

### [xieite::math::roundHalfTowardZero\<\>\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/math/round_half_toward_zero.md)
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::round(0.5));
    std::println("{}", xieite::math::roundHalfTowardZero(0.5));
}
```

&nbsp;

### [XIEITE_ATTRIBUTE_...\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/macros/attribute.md)
```cpp
#include <xieite/attribute.hpp>

XIEITE_ATTRIBUTE_DEPRECATED void foo() {}

int main() {
    foo();
}
```

&nbsp;

### [xieite::bits::mash\<\>\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/bits/mash.md)
```cpp
import std;
import xieite;

int main() {
    auto bitset = xieite::bits::mash<4, 4>(0b1111, 0b1010);
    std::println("{}", bitset.to_string());
}
```

&nbsp;

### [xieite::containers::FixedMap\<\> \{\}](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/containers/fixed_map.md)
```cpp
import std;
import xieite;

constexpr xieite::containers::FixedMap<std::string_view, int, 3> map = {
    { "abc", 1 },
    { "def", 2 },
    { "xyz", 3 }
};

int main() {
    std::println("{}", map["xyz"]);
}
```

&nbsp;

### [xieite::system::execute\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/system/execute.md)
```cpp
import std;
import xieite;

int main() {
    auto result = xieite::system::execute("echo Hello, world!");
    std::print("output: {}", result.output);
    std::println("status: {}", result.status);
}
```

&nbsp;

### [xieite::time::compilation \{\}](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/time/compilation.md)
```cpp
import std;
import xieite;

int main() {
    std::println("Compiled in {}", xieite::time::compilation::year);
}
```

&nbsp;

### [XIEITE_COMPILER_...\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/macros/compiler.md)
```cpp
#include <xieite/compiler.hpp>
import std;

int main() {
    std::println("{}", XIEITE_COMPILER_VERSION_LEAST(GCC, 15, 0, 0));
}
```

&nbsp;

### [xieite::types::FunctionPointerTraits\<\> \{\}](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/types/function_pointer_traits.md)
```cpp
import std;
import xieite;

struct S {
    void f(...) & volatile {}
};

int main() {
    using Traits = xieite::types::FunctionPointerTraits<decltype(&S::f)>;

    std::println("{}", Traits::variadic);
    std::println("{}", Traits::constantQualified);
    std::println("{}", Traits::volatileQualified);
    std::println("{}", Traits::leftValueQualified);
    std::println("{}", Traits::rightValueQualified);
    std::println("{}", Traits::noThrowQualified);
}
```

&nbsp;

### [xieite::literals::exponent \{\}](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/literals/exponent.md)
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::exponent;

    std::println("{}", 4 ** 12_exponent);
}
```

&nbsp;

### [xieite::strings::quote\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/strings/quote.md)
```cpp
import std;
import xieite;

int main() {
    std::string str = "Hello, world!";

    for (int i = 0; i < 3; ++i) {
        str = xieite::strings::quote(str);
        std::println("{}", str);
    }
}
```

&nbsp;

### [xieite::types::List\<\> \{\}](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/types/list.md)
```cpp
import std;
import xieite;

using Foo = xieite::types::List<int, char, float, double>;
using Bar = xieite::types::List<double, float, char, int>;

static_assert(std::same_as<Foo, Bar::Reverse>);

int main() {}
```

&nbsp;

### [xieite::functors::Function\<\>\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/functors/function.md)
```cpp
import std;
import xieite;

constexpr xieite::functors::Function<int(int, int)> add = [](int x, int y) { return x + y; };

constexpr int sum = add(1, 2);

int main() {
    std::println("{}", sum);
}
```

&nbsp;

### [xieite::system::segmentationFault\(\)](https://github.com/Eczbek/xieite/blob/main/docs/namespaces/system/segmentation_fault.md)
```cpp
import xieite;

int main() {
    xieite::system::segmentationFault();
}
```

&nbsp;

(nonexhaustive)

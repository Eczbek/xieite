# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[SkillIssue](../../../../unrepresentable_value.md)\:\:SkillIssue
Defined in header [<xieite/exceptions/unrepresentable_value.hpp>](../../../../../../../include/xieite/exceptions/unrepresentable_value.hpp)

&nbsp;

## Description
Constructs a `xieite::exceptions::SkillIssue`.

## Synopsis
#### 1)
```cpp
SkillIssue(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/skill_issue.hpp"

int main() {
    xieite::exceptions::SkillIssue exception;

    std::println("{}", exception.what());
}
```
Output:
```
cope
```

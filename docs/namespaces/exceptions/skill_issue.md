# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:SkillIssue
Defined in header [<xieite/exceptions/skill_issue.hpp>](../../../include/xieite/exceptions/skill_issue.hpp)

&nbsp;

An exception type that indicates a skill issue. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct SkillIssue
: xieite::exceptions::Unspecified {
    constexpr SkillIssue(std::string_view = "cope") noexcept;
};
```
##### Member functions
- [SkillIssue](./structures/skill_issue/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/skill_issue.hpp"

int main() {
    throw xieite::exceptions::SkillIssue();
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::SkillIssue'
  what():  cope
Aborted (core dumped)
```

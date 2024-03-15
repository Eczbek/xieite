# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:SkillIssue \{\}
Defined in header [<xieite/exceptions/skill_issue.hpp>](../../../include/xieite/exceptions/skill_issue.hpp)

&nbsp;

## Description
An exception type that indicates a skill issue on the part of the user. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct SkillIssue
: xieite::exceptions::Unspecified {
    SkillIssue(std::string_view = "cope") noexcept;
};
```
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

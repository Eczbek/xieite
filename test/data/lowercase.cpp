#include <xte/data/lowercase.hpp>
#include <xte/data/string.hpp>

static_assert(xte::lowercase('A') == 'a');
static_assert(xte::lowercase('B') == 'b');
static_assert(xte::lowercase('C') == 'c');
static_assert(xte::lowercase('X') == 'x');
static_assert(xte::lowercase('Y') == 'y');
static_assert(xte::lowercase('Z') == 'z');
static_assert(xte::lowercase('a') == 'a');
static_assert(xte::lowercase('b') == 'b');
static_assert(xte::lowercase('c') == 'c');
static_assert(xte::lowercase('x') == 'x');
static_assert(xte::lowercase('y') == 'y');
static_assert(xte::lowercase('z') == 'z');
static_assert(xte::lowercase('!') == '!');
static_assert(xte::lowercase('%') == '%');
static_assert(xte::lowercase(' ') == ' ');
static_assert(xte::lowercase('/') == '/');
static_assert(xte::lowercase('"') == '"');
static_assert(xte::lowercase('\0') == '\0');

static_assert(xte::lowercase(xte::string("ABCXYZ abcxyz")) == xte::string("abcxyz abcxyz"));

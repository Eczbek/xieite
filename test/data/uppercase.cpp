#include <xte/data/uppercase.hpp>
#include <xte/data/string.hpp>

static_assert(xte::uppercase('a') == 'A');
static_assert(xte::uppercase('b') == 'B');
static_assert(xte::uppercase('c') == 'C');
static_assert(xte::uppercase('x') == 'X');
static_assert(xte::uppercase('y') == 'Y');
static_assert(xte::uppercase('z') == 'Z');
static_assert(xte::uppercase('A') == 'A');
static_assert(xte::uppercase('B') == 'B');
static_assert(xte::uppercase('C') == 'C');
static_assert(xte::uppercase('X') == 'X');
static_assert(xte::uppercase('Y') == 'Y');
static_assert(xte::uppercase('Z') == 'Z');
static_assert(xte::uppercase('!') == '!');
static_assert(xte::uppercase('%') == '%');
static_assert(xte::uppercase(' ') == ' ');
static_assert(xte::uppercase('/') == '/');
static_assert(xte::uppercase('"') == '"');
static_assert(xte::uppercase('\0') == '\0');

static_assert(xte::uppercase(xte::string("ABCXYZ abcxyz")) == xte::string("ABCXYZ ABCXYZ"));

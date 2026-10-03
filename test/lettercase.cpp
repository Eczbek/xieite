#include <xte/lettercase.hpp>
#include <xte/string.hpp>

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
static_assert(xte::uppercase("ABCXYZ abcxyz") == "ABCXYZ ABCXYZ");

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
static_assert(xte::lowercase("ABCXYZ abcxyz") == "abcxyz abcxyz");

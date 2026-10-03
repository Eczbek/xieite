#include <xte/fundamental_traits.hpp>
#include <xte/qual_traits.hpp>
#include <meta>

static_assert(xte::is_void<void>);
static_assert(xte::is_void<void const>);
static_assert(!xte::is_void<void*>);
static_assert(!xte::is_void<int>);



static_assert(xte::is_unsigned_int<unsigned char>);
static_assert(xte::is_unsigned_int<unsigned short>);
static_assert(xte::is_unsigned_int<unsigned int>);
static_assert(xte::is_unsigned_int<unsigned long>);
static_assert(xte::is_unsigned_int<unsigned long long>);
static_assert(!xte::is_unsigned_int<signed char>);
static_assert(!xte::is_unsigned_int<short>);
static_assert(!xte::is_unsigned_int<int>);
static_assert(!xte::is_unsigned_int<long>);
static_assert(!xte::is_unsigned_int<long long>);

static_assert(xte::is_unsigned_int<unsigned char const>);
static_assert(xte::is_unsigned_int<unsigned short const>);
static_assert(xte::is_unsigned_int<unsigned int const>);
static_assert(xte::is_unsigned_int<unsigned long const>);
static_assert(xte::is_unsigned_int<unsigned long long const>);
static_assert(!xte::is_unsigned_int<signed char const>);
static_assert(!xte::is_unsigned_int<short const>);
static_assert(!xte::is_unsigned_int<int const>);
static_assert(!xte::is_unsigned_int<long const>);
static_assert(!xte::is_unsigned_int<long long const>);

static_assert(xte::is_unsigned_int<unsigned char volatile>);
static_assert(xte::is_unsigned_int<unsigned short volatile>);
static_assert(xte::is_unsigned_int<unsigned int volatile>);
static_assert(xte::is_unsigned_int<unsigned long volatile>);
static_assert(xte::is_unsigned_int<unsigned long long volatile>);
static_assert(!xte::is_unsigned_int<signed char volatile>);
static_assert(!xte::is_unsigned_int<short volatile>);
static_assert(!xte::is_unsigned_int<int volatile>);
static_assert(!xte::is_unsigned_int<long volatile>);
static_assert(!xte::is_unsigned_int<long long volatile>);

static_assert(xte::is_unsigned_int<unsigned char const volatile>);
static_assert(xte::is_unsigned_int<unsigned short const volatile>);
static_assert(xte::is_unsigned_int<unsigned int const volatile>);
static_assert(xte::is_unsigned_int<unsigned long const volatile>);
static_assert(xte::is_unsigned_int<unsigned long long const volatile>);
static_assert(!xte::is_unsigned_int<signed char const volatile>);
static_assert(!xte::is_unsigned_int<short const volatile>);
static_assert(!xte::is_unsigned_int<int const volatile>);
static_assert(!xte::is_unsigned_int<long const volatile>);
static_assert(!xte::is_unsigned_int<long long const volatile>);

static_assert(!xte::is_unsigned_int<bool>);
static_assert(!xte::is_unsigned_int<void>);
static_assert(!xte::is_unsigned_int<int&>);
static_assert(!xte::is_unsigned_int<int&&>);
static_assert(!xte::is_unsigned_int<char***&&>);
static_assert(!xte::is_unsigned_int<int(decltype([]{})::*)(...) const volatile&& noexcept>);



static_assert(!xte::is_signed_int<unsigned char>);
static_assert(!xte::is_signed_int<unsigned short>);
static_assert(!xte::is_signed_int<unsigned int>);
static_assert(!xte::is_signed_int<unsigned long>);
static_assert(!xte::is_signed_int<unsigned long long>);
static_assert(xte::is_signed_int<signed char>);
static_assert(xte::is_signed_int<short>);
static_assert(xte::is_signed_int<int>);
static_assert(xte::is_signed_int<long>);
static_assert(xte::is_signed_int<long long>);

static_assert(!xte::is_signed_int<unsigned char const>);
static_assert(!xte::is_signed_int<unsigned short const>);
static_assert(!xte::is_signed_int<unsigned int const>);
static_assert(!xte::is_signed_int<unsigned long const>);
static_assert(!xte::is_signed_int<unsigned long long const>);
static_assert(xte::is_signed_int<signed char const>);
static_assert(xte::is_signed_int<short const>);
static_assert(xte::is_signed_int<int const>);
static_assert(xte::is_signed_int<long const>);
static_assert(xte::is_signed_int<long long const>);

static_assert(!xte::is_signed_int<unsigned char volatile>);
static_assert(!xte::is_signed_int<unsigned short volatile>);
static_assert(!xte::is_signed_int<unsigned int volatile>);
static_assert(!xte::is_signed_int<unsigned long volatile>);
static_assert(!xte::is_signed_int<unsigned long long volatile>);
static_assert(xte::is_signed_int<signed char volatile>);
static_assert(xte::is_signed_int<short volatile>);
static_assert(xte::is_signed_int<int volatile>);
static_assert(xte::is_signed_int<long volatile>);
static_assert(xte::is_signed_int<long long volatile>);

static_assert(!xte::is_signed_int<unsigned char const volatile>);
static_assert(!xte::is_signed_int<unsigned short const volatile>);
static_assert(!xte::is_signed_int<unsigned int const volatile>);
static_assert(!xte::is_signed_int<unsigned long const volatile>);
static_assert(!xte::is_signed_int<unsigned long long const volatile>);
static_assert(xte::is_signed_int<signed char const volatile>);
static_assert(xte::is_signed_int<short const volatile>);
static_assert(xte::is_signed_int<int const volatile>);
static_assert(xte::is_signed_int<long const volatile>);
static_assert(xte::is_signed_int<long long const volatile>);

static_assert(!xte::is_signed_int<bool>);
static_assert(!xte::is_signed_int<void>);
static_assert(!xte::is_signed_int<int&>);
static_assert(!xte::is_signed_int<int&&>);
static_assert(!xte::is_signed_int<char***&&>);
static_assert(!xte::is_signed_int<int(decltype([]{})::*)(...) const volatile&& noexcept>);



static_assert(xte::is_int<unsigned char>);
static_assert(xte::is_int<unsigned short>);
static_assert(xte::is_int<unsigned int>);
static_assert(xte::is_int<unsigned long>);
static_assert(xte::is_int<unsigned long long>);
static_assert(xte::is_int<signed char>);
static_assert(xte::is_int<short>);
static_assert(xte::is_int<int>);
static_assert(xte::is_int<long>);
static_assert(xte::is_int<long long>);

static_assert(xte::is_int<unsigned char const>);
static_assert(xte::is_int<unsigned short const>);
static_assert(xte::is_int<unsigned int const>);
static_assert(xte::is_int<unsigned long const>);
static_assert(xte::is_int<unsigned long long const>);
static_assert(xte::is_int<signed char const>);
static_assert(xte::is_int<short const>);
static_assert(xte::is_int<int const>);
static_assert(xte::is_int<long const>);
static_assert(xte::is_int<long long const>);

static_assert(xte::is_int<unsigned char volatile>);
static_assert(xte::is_int<unsigned short volatile>);
static_assert(xte::is_int<unsigned int volatile>);
static_assert(xte::is_int<unsigned long volatile>);
static_assert(xte::is_int<unsigned long long volatile>);
static_assert(xte::is_int<signed char volatile>);
static_assert(xte::is_int<short volatile>);
static_assert(xte::is_int<int volatile>);
static_assert(xte::is_int<long volatile>);
static_assert(xte::is_int<long long volatile>);

static_assert(xte::is_int<unsigned char const volatile>);
static_assert(xte::is_int<unsigned short const volatile>);
static_assert(xte::is_int<unsigned int const volatile>);
static_assert(xte::is_int<unsigned long const volatile>);
static_assert(xte::is_int<unsigned long long const volatile>);
static_assert(xte::is_int<signed char const volatile>);
static_assert(xte::is_int<short const volatile>);
static_assert(xte::is_int<int const volatile>);
static_assert(xte::is_int<long const volatile>);
static_assert(xte::is_int<long long const volatile>);

static_assert(xte::is_int<char>);

static_assert(!xte::is_int<bool>);
static_assert(!xte::is_int<void>);
static_assert(!xte::is_int<int&>);
static_assert(!xte::is_int<int&&>);
static_assert(!xte::is_int<char***&&>);
static_assert(!xte::is_int<int(decltype([]{})::*)(...) const volatile&& noexcept>);



// TODO: is_float, is_arithmetic



static_assert(xte::is_arithmetic_or_bool<int>);
static_assert(xte::is_arithmetic_or_bool<float>);
static_assert(xte::is_arithmetic_or_bool<bool>);
static_assert(!xte::is_arithmetic_or_bool<void*>);



static_assert(xte::is_char<char>);
static_assert(xte::is_char<wchar_t>);
static_assert(xte::is_char<char8_t>);
static_assert(xte::is_char<char16_t>);
static_assert(xte::is_char<char32_t>);

static_assert(!xte::is_char<unsigned char>);
static_assert(!xte::is_char<signed char>);



static_assert(xte::is_ptr<int*>);
static_assert(!xte::is_ptr<int>);
static_assert(xte::is_ptr<int*, 0>);
static_assert(!xte::is_ptr<int*, 1>);
static_assert(!xte::is_ptr<int*, 3>);
static_assert(xte::is_ptr<int***, 2>);



// TODO: is_order



static_assert(xte::is_same<int*, xte::add_ptr<int>>);
static_assert(xte::is_same<int, xte::add_ptr<int, 0>>);
static_assert(xte::is_same<int*, xte::add_ptr<int, 1>>);
static_assert(xte::is_same<int**, xte::add_ptr<int, 2>>);
static_assert(xte::is_same<int***, xte::add_ptr<int, 3>>);



static_assert(xte::is_same<int[1], xte::add_array<int, 1>>);
static_assert(xte::is_same<int[999], xte::add_array<int, 999>>);
static_assert(!std::meta::can_substitute(^^xte::add_array, { ^^int, std::meta::reflect_constant(0) }));



static_assert(xte::is_same<int[], xte::add_unsized_array<int>>);
static_assert(!std::meta::can_substitute(^^xte::add_unsized_array, { ^^void }));
static_assert(!std::meta::can_substitute(^^xte::add_unsized_array, { ^^int[] }));



static_assert(xte::is_same<int, xte::drop_ptr<int*>>);
static_assert(xte::is_same<int, xte::drop_ptr<int***, 3>>);
static_assert(xte::is_same<int*, xte::drop_ptr<int***, 2>>);
static_assert(xte::is_same<int***, xte::drop_ptr<int***, 0>>);


static_assert(xte::is_same<unsigned int, xte::try_unsigned<int>>);
static_assert(xte::is_same<unsigned int, xte::try_unsigned<unsigned int>>);
static_assert(xte::is_same<double, xte::try_unsigned<double>>);


static_assert(xte::is_same<int, xte::try_signed<unsigned int>>);
static_assert(xte::is_same<int, xte::try_signed<int>>);
static_assert(xte::is_same<double, xte::try_signed<double>>);



static_assert(xte::ptr_depth<int> == 0);
static_assert(xte::ptr_depth<int*> == 1);
static_assert(xte::ptr_depth<int**> == 2);
static_assert(xte::ptr_depth<int***> == 3);
static_assert(xte::ptr_depth<int* const* volatile* const volatile*&&> == 4);



static_assert(xte::as_unsigned(-1) == -1u);



static_assert(xte::as_signed(-1u) == -1);



static_assert(xte::sign_cast<unsigned>(static_cast<signed char>(-1)) == static_cast<unsigned char>(-1));
static_assert(xte::sign_cast<int>(static_cast<unsigned char>(-1)) == -1);

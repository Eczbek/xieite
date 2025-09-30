#include <type_traits>
#include <xte/meta/type_at.hpp>

struct A {};
struct B {};
struct C {};
struct D {};
struct E {};
struct F {};

static_assert(std::is_same_v<A, xte::type_at<0, A, B, C, D, E, F>>);
static_assert(std::is_same_v<B, xte::type_at<1, A, B, C, D, E, F>>);
static_assert(std::is_same_v<C, xte::type_at<2, A, B, C, D, E, F>>);
static_assert(std::is_same_v<D, xte::type_at<3, A, B, C, D, E, F>>);
static_assert(std::is_same_v<E, xte::type_at<4, A, B, C, D, E, F>>);
static_assert(std::is_same_v<F, xte::type_at<5, A, B, C, D, E, F>>);

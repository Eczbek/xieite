export module xieite:fn_ptr;

import std;

template<typename F, typename Ret, typename Args, bool is_var_, bool is_nothrow_>
struct free_fn_ptr {
	using fn = F;
	using ret = Ret;
	using args = Args;

	static constexpr bool is_var = is_var_;
	static constexpr bool nothrow = is_nothrow_;
};

template<typename Class, typename Ref, typename F, typename Ret, typename Args, bool is_var_, bool is_const_, bool is_volat_, bool is_lvalue_, bool is_rvalue_, bool is_nothrow_>
struct member_fn_ptr {
	using type = Class;
	using ref = Ref;
	using fn = F;
	using ret = Ret;
	using args = Args;

	static constexpr bool is_var = is_var_;
	static constexpr bool is_const = is_const_;
	static constexpr bool is_volat = is_volat_;
	static constexpr bool is_lvalue = is_lvalue_;
	static constexpr bool is_rvalue = is_rvalue_;
	static constexpr bool nothrow = is_nothrow_;
};

export namespace xieite {
	template<typename>
	struct fn_ptr;

	template<typename ret, typename... args>
	struct fn_ptr<ret(*)(args...)> : free_fn_ptr<ret(args...), ret, std::tuple<args...>, false, false> {};

	template<typename ret, typename... args>
	struct fn_ptr<ret(*)(args..., ...)> : free_fn_ptr<ret(args..., ...), ret, std::tuple<args...>, true, false> {};

	template<typename ret, typename... args>
	struct fn_ptr<ret(*)(args...) noexcept> : free_fn_ptr<ret(args...) noexcept, ret, std::tuple<args...>, false, true> {};

	template<typename ret, typename... args>
	struct fn_ptr<ret(*)(args..., ...) noexcept> : free_fn_ptr<ret(args..., ...) noexcept, ret, std::tuple<args...>, true, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...)> : member_fn_ptr<type, type&, ret(args...), ret, std::tuple<args...>, false, false, false, false, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...)> : member_fn_ptr<type, type&, ret(args..., ...), ret, std::tuple<args...>, true, false, false, false, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const> : member_fn_ptr<type, const type&, ret(args...) const, ret, std::tuple<args...>, false, true, false, false, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const> : member_fn_ptr<type, const type&, ret(args..., ...) const, ret, std::tuple<args...>, true, true, false, false, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) volatile> : member_fn_ptr<type, volatile type&, ret(args...) volatile, ret, std::tuple<args...>, false, false, true, false, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) volatile> : member_fn_ptr<type, volatile type&, ret(args..., ...) volatile, ret, std::tuple<args...>, true, false, true, false, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const volatile> : member_fn_ptr<type, const volatile type&, ret(args...) const volatile, ret, std::tuple<args...>, false, true, true, false, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const volatile> : member_fn_ptr<type, const volatile type&, ret(args..., ...) const volatile, ret, std::tuple<args...>, true, true, true, false, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) &> : member_fn_ptr<type, type&, ret(args...) &, ret, std::tuple<args...>, false, false, false, true, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) &> : member_fn_ptr<type, type&, ret(args..., ...) &, ret, std::tuple<args...>, true, false, false, true, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const &> : member_fn_ptr<type, const type&, ret(args...) const &, ret, std::tuple<args...>, false, true, false, true, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const &> : member_fn_ptr<type, const type&, ret(args..., ...) const &, ret, std::tuple<args...>, true, true, false, true, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) volatile &> : member_fn_ptr<type, volatile type&, ret(args...) volatile &, ret, std::tuple<args...>, false, false, true, true, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) volatile &> : member_fn_ptr<type, volatile type&, ret(args..., ...) volatile &, ret, std::tuple<args...>, true, false, true, true, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const volatile &> : member_fn_ptr<type, const volatile type&, ret(args...) const volatile &, ret, std::tuple<args...>, false, true, true, true, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const volatile &> : member_fn_ptr<type, const volatile type&, ret(args..., ...) const volatile &, ret, std::tuple<args...>, true, true, true, true, false, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) &&> : member_fn_ptr<type, type&&, ret(args...) &&, ret, std::tuple<args...>, false, false, false, false, true, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) &&> : member_fn_ptr<type, type&&, ret(args..., ...) &&, ret, std::tuple<args...>, true, false, false, false, true, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const &&> : member_fn_ptr<type, const type&&, ret(args...) const &&, ret, std::tuple<args...>, false, true, false, false, true, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const &&> : member_fn_ptr<type, const type&&, ret(args..., ...) const &&, ret, std::tuple<args...>, true, true, false, false, true, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) volatile &&> : member_fn_ptr<type, volatile type&&, ret(args...) volatile &&, ret, std::tuple<args...>, false, false, true, false, true, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) volatile &&> : member_fn_ptr<type, volatile type&&, ret(args..., ...) volatile &&, ret, std::tuple<args...>, true, false, true, false, true, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const volatile &&> : member_fn_ptr<type, const volatile type&&, ret(args...) const volatile &&, ret, std::tuple<args...>, false, true, true, false, true, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const volatile &&> : member_fn_ptr<type, const volatile type&&, ret(args..., ...) const volatile &&, ret, std::tuple<args...>, true, true, true, false, true, false> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) noexcept> : member_fn_ptr<type, type&, ret(args...) noexcept, ret, std::tuple<args...>, false, false, false, false, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) noexcept> : member_fn_ptr<type, type&, ret(args..., ...) noexcept, ret, std::tuple<args...>, true, false, false, false, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const noexcept> : member_fn_ptr<type, const type&, ret(args...) const noexcept, ret, std::tuple<args...>, false, true, false, false, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const noexcept> : member_fn_ptr<type, const type&, ret(args..., ...) const noexcept, ret, std::tuple<args...>, true, true, false, false, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) volatile noexcept> : member_fn_ptr<type, volatile type&, ret(args...) volatile noexcept, ret, std::tuple<args...>, false, false, true, false, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) volatile noexcept> : member_fn_ptr<type, volatile type&, ret(args..., ...) volatile noexcept, ret, std::tuple<args...>, true, false, true, false, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const volatile noexcept> : member_fn_ptr<type, const volatile type&, ret(args...) const volatile noexcept, ret, std::tuple<args...>, false, true, true, false, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const volatile noexcept> : member_fn_ptr<type, const volatile type&, ret(args..., ...) const volatile noexcept, ret, std::tuple<args...>, true, true, true, false, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) & noexcept> : member_fn_ptr<type, type&, ret(args...) & noexcept, ret, std::tuple<args...>, false, false, false, true, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) & noexcept> : member_fn_ptr<type, type&, ret(args..., ...) & noexcept, ret, std::tuple<args...>, true, false, false, true, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const & noexcept> : member_fn_ptr<type, const type&, ret(args...) const & noexcept, ret, std::tuple<args...>, false, true, false, true, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const & noexcept> : member_fn_ptr<type, const type&, ret(args..., ...) const & noexcept, ret, std::tuple<args...>, true, true, false, true, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) volatile & noexcept> : member_fn_ptr<type, volatile type&, ret(args...) volatile & noexcept, ret, std::tuple<args...>, false, false, true, true, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) volatile & noexcept> : member_fn_ptr<type, volatile type&, ret(args..., ...) volatile & noexcept, ret, std::tuple<args...>, true, false, true, true, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const volatile & noexcept> : member_fn_ptr<type, const volatile type&, ret(args...) const volatile & noexcept, ret, std::tuple<args...>, false, true, true, true, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const volatile & noexcept> : member_fn_ptr<type, const volatile type&, ret(args..., ...) const volatile & noexcept, ret, std::tuple<args...>, true, true, true, true, false, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) && noexcept> : member_fn_ptr<type, type&&, ret(args...) && noexcept, ret, std::tuple<args...>, false, false, false, false, true, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) && noexcept> : member_fn_ptr<type, type&&, ret(args..., ...) && noexcept, ret, std::tuple<args...>, true, false, false, false, true, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const && noexcept> : member_fn_ptr<type, const type&&, ret(args...) const && noexcept, ret, std::tuple<args...>, false, true, false, false, true, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const && noexcept> : member_fn_ptr<type, const type&&, ret(args..., ...) const && noexcept, ret, std::tuple<args...>, true, true, false, false, true, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) volatile && noexcept> : member_fn_ptr<type, volatile type&&, ret(args...) volatile && noexcept, ret, std::tuple<args...>, false, false, true, false, true, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) volatile && noexcept> : member_fn_ptr<type, volatile type&&, ret(args..., ...) volatile && noexcept, ret, std::tuple<args...>, true, false, true, false, true, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args...) const volatile && noexcept> : member_fn_ptr<type, const volatile type&&, ret(args...) const volatile && noexcept, ret, std::tuple<args...>, false, true, true, false, true, true> {};

	template<typename ret, typename type, typename... args>
	struct fn_ptr<ret(type::*)(args..., ...) const volatile && noexcept> : member_fn_ptr<type, const volatile type&&, ret(args..., ...) const volatile && noexcept, ret, std::tuple<args...>, true, true, true, false, true, true> {};
}

// Thanks to halalaluyafail3 (https://github.com/Halalaluyafail3) for original code

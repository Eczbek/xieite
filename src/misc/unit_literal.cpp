export module xieite:unit_literal;

import :unit;

export namespace xieite::unit_literal {
	[[nodiscard]] constexpr auto operator""_qm(unsigned long long int value) noexcept {
		return xieite::unit::qm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qm(long double value) noexcept {
		return xieite::unit::qm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rm(unsigned long long int value) noexcept {
		return xieite::unit::rm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rm(long double value) noexcept {
		return xieite::unit::rm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ym(unsigned long long int value) noexcept {
		return xieite::unit::ym(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ym(long double value) noexcept {
		return xieite::unit::ym(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_zm(unsigned long long int value) noexcept {
		return xieite::unit::zm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_zm(long double value) noexcept {
		return xieite::unit::zm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_am(unsigned long long int value) noexcept {
		return xieite::unit::am(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_am(long double value) noexcept {
		return xieite::unit::am(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fm(unsigned long long int value) noexcept {
		return xieite::unit::fm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fm(long double value) noexcept {
		return xieite::unit::fm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pm(unsigned long long int value) noexcept {
		return xieite::unit::pm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pm(long double value) noexcept {
		return xieite::unit::pm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nm(unsigned long long int value) noexcept {
		return xieite::unit::nm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nm(long double value) noexcept {
		return xieite::unit::nm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_um(unsigned long long int value) noexcept {
		return xieite::unit::um(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_um(long double value) noexcept {
		return xieite::unit::um(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mm(unsigned long long int value) noexcept {
		return xieite::unit::mm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mm(long double value) noexcept {
		return xieite::unit::mm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cm(unsigned long long int value) noexcept {
		return xieite::unit::cm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cm(long double value) noexcept {
		return xieite::unit::cm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dm(unsigned long long int value) noexcept {
		return xieite::unit::dm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dm(long double value) noexcept {
		return xieite::unit::dm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_m(unsigned long long int value) noexcept {
		return xieite::unit::m(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_m(long double value) noexcept {
		return xieite::unit::m(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dam(unsigned long long int value) noexcept {
		return xieite::unit::dam(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dam(long double value) noexcept {
		return xieite::unit::dam(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_hm(unsigned long long int value) noexcept {
		return xieite::unit::hm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_hm(long double value) noexcept {
		return xieite::unit::hm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_km(unsigned long long int value) noexcept {
		return xieite::unit::km(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_km(long double value) noexcept {
		return xieite::unit::km(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Mm(unsigned long long int value) noexcept {
		return xieite::unit::Mm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Mm(long double value) noexcept {
		return xieite::unit::Mm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Gm(unsigned long long int value) noexcept {
		return xieite::unit::Gm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Gm(long double value) noexcept {
		return xieite::unit::Gm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Tm(unsigned long long int value) noexcept {
		return xieite::unit::Tm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Tm(long double value) noexcept {
		return xieite::unit::Tm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Pm(unsigned long long int value) noexcept {
		return xieite::unit::Pm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Pm(long double value) noexcept {
		return xieite::unit::Pm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Em(unsigned long long int value) noexcept {
		return xieite::unit::Em(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Em(long double value) noexcept {
		return xieite::unit::Em(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Zm(unsigned long long int value) noexcept {
		return xieite::unit::Zm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Zm(long double value) noexcept {
		return xieite::unit::Zm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Ym(unsigned long long int value) noexcept {
		return xieite::unit::Ym(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Ym(long double value) noexcept {
		return xieite::unit::Ym(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Rm(unsigned long long int value) noexcept {
		return xieite::unit::Rm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Rm(long double value) noexcept {
		return xieite::unit::Rm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Qm(unsigned long long int value) noexcept {
		return xieite::unit::Qm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_Qm(long double value) noexcept {
		return xieite::unit::Qm(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_twips(unsigned long long int value) noexcept {
		return xieite::unit::twip(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_twips(long double value) noexcept {
		return xieite::unit::twip(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_thous(unsigned long long int value) noexcept {
		return xieite::unit::thou(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_thous(long double value) noexcept {
		return xieite::unit::thou(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_barleycorns(unsigned long long int value) noexcept {
		return xieite::unit::barleycorn(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_barleycorns(long double value) noexcept {
		return xieite::unit::barleycorn(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_in(unsigned long long int value) noexcept {
		return xieite::unit::in(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_in(long double value) noexcept {
		return xieite::unit::in(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ft(unsigned long long int value) noexcept {
		return xieite::unit::ft(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ft(long double value) noexcept {
		return xieite::unit::ft(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_yd(unsigned long long int value) noexcept {
		return xieite::unit::yd(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_yd(long double value) noexcept {
		return xieite::unit::yd(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_chains(unsigned long long int value) noexcept {
		return xieite::unit::chains(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_chains(long double value) noexcept {
		return xieite::unit::chains(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_furlongs(unsigned long long int value) noexcept {
		return xieite::unit::furlongs(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_furlongs(long double value) noexcept {
		return xieite::unit::furlongs(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mi(unsigned long long int value) noexcept {
		return xieite::unit::mi(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mi(long double value) noexcept {
		return xieite::unit::mi(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_leagues(unsigned long long int value) noexcept {
		return xieite::unit::leagues(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_leagues(long double value) noexcept {
		return xieite::unit::leagues(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fathoms(unsigned long long int value) noexcept {
		return xieite::unit::fathoms(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fathoms(long double value) noexcept {
		return xieite::unit::fathoms(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cables(unsigned long long int value) noexcept {
		return xieite::unit::cables(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cables(long double value) noexcept {
		return xieite::unit::cables(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nmi(unsigned long long int value) noexcept {
		return xieite::unit::nmi(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nmi(long double value) noexcept {
		return xieite::unit::nmi(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nau_leagues(unsigned long long int value) noexcept {
		return xieite::unit::nau_leagues(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nau_leagues(long double value) noexcept {
		return xieite::unit::nau_leagues(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_links(unsigned long long int value) noexcept {
		return xieite::unit::links(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_links(long double value) noexcept {
		return xieite::unit::links(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rods(unsigned long long int value) noexcept {
		return xieite::unit::rods(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rods(long double value) noexcept {
		return xieite::unit::rods(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_perches(unsigned long long int value) noexcept {
		return xieite::unit::perches(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_perches(long double value) noexcept {
		return xieite::unit::perches(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_poles(unsigned long long int value) noexcept {
		return xieite::unit::poles(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_poles(long double value) noexcept {
		return xieite::unit::poles(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_lugs(unsigned long long int value) noexcept {
		return xieite::unit::lugs(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_lugs(long double value) noexcept {
		return xieite::unit::lugs(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qA(unsigned long long int value) noexcept {
		return xieite::unit::qA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qA(long double value) noexcept {
		return xieite::unit::qA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rA(unsigned long long int value) noexcept {
		return xieite::unit::rA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rA(long double value) noexcept {
		return xieite::unit::rA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_yA(unsigned long long int value) noexcept {
		return xieite::unit::yA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_yA(long double value) noexcept {
		return xieite::unit::yA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_zA(unsigned long long int value) noexcept {
		return xieite::unit::zA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_zA(long double value) noexcept {
		return xieite::unit::zA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_aA(unsigned long long int value) noexcept {
		return xieite::unit::aA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_aA(long double value) noexcept {
		return xieite::unit::aA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fA(unsigned long long int value) noexcept {
		return xieite::unit::fA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fA(long double value) noexcept {
		return xieite::unit::fA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pA(unsigned long long int value) noexcept {
		return xieite::unit::pA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pA(long double value) noexcept {
		return xieite::unit::pA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nA(unsigned long long int value) noexcept {
		return xieite::unit::nA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nA(long double value) noexcept {
		return xieite::unit::nA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_uA(unsigned long long int value) noexcept {
		return xieite::unit::uA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_uA(long double value) noexcept {
		return xieite::unit::uA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mA(unsigned long long int value) noexcept {
		return xieite::unit::mA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mA(long double value) noexcept {
		return xieite::unit::mA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cA(unsigned long long int value) noexcept {
		return xieite::unit::cA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cA(long double value) noexcept {
		return xieite::unit::cA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dA(unsigned long long int value) noexcept {
		return xieite::unit::dA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dA(long double value) noexcept {
		return xieite::unit::dA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_A(unsigned long long int value) noexcept {
		return xieite::unit::A(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_A(long double value) noexcept {
		return xieite::unit::A(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_daA(unsigned long long int value) noexcept {
		return xieite::unit::daA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_daA(long double value) noexcept {
		return xieite::unit::daA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_hA(unsigned long long int value) noexcept {
		return xieite::unit::hA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_hA(long double value) noexcept {
		return xieite::unit::hA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_kA(unsigned long long int value) noexcept {
		return xieite::unit::kA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_kA(long double value) noexcept {
		return xieite::unit::kA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_MA(unsigned long long int value) noexcept {
		return xieite::unit::MA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_MA(long double value) noexcept {
		return xieite::unit::MA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_GA(unsigned long long int value) noexcept {
		return xieite::unit::GA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_GA(long double value) noexcept {
		return xieite::unit::GA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_TA(unsigned long long int value) noexcept {
		return xieite::unit::TA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_TA(long double value) noexcept {
		return xieite::unit::TA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_PA(unsigned long long int value) noexcept {
		return xieite::unit::PA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_PA(long double value) noexcept {
		return xieite::unit::PA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_EA(unsigned long long int value) noexcept {
		return xieite::unit::EA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_EA(long double value) noexcept {
		return xieite::unit::EA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ZA(unsigned long long int value) noexcept {
		return xieite::unit::ZA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ZA(long double value) noexcept {
		return xieite::unit::ZA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_YA(unsigned long long int value) noexcept {
		return xieite::unit::YA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_YA(long double value) noexcept {
		return xieite::unit::YA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_RA(unsigned long long int value) noexcept {
		return xieite::unit::RA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_RA(long double value) noexcept {
		return xieite::unit::RA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_QA(unsigned long long int value) noexcept {
		return xieite::unit::QA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_QA(long double value) noexcept {
		return xieite::unit::QA(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_sq_in(unsigned long long int value) noexcept {
		return xieite::unit::sq_in(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_sq_in(long double value) noexcept {
		return xieite::unit::sq_in(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_sq_ft(unsigned long long int value) noexcept {
		return xieite::unit::sq_ft(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_sq_ft(long double value) noexcept {
		return xieite::unit::sq_ft(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_sq_yd(unsigned long long int value) noexcept {
		return xieite::unit::sq_yd(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_sq_yd(long double value) noexcept {
		return xieite::unit::sq_yd(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_sq_mi(unsigned long long int value) noexcept {
		return xieite::unit::sq_mi(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_sq_mi(long double value) noexcept {
		return xieite::unit::sq_mi(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_roods(unsigned long long int value) noexcept {
		return xieite::unit::sq_roods(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_roods(long double value) noexcept {
		return xieite::unit::sq_roods(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ac(unsigned long long int value) noexcept {
		return xieite::unit::ac(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ac(long double value) noexcept {
		return xieite::unit::ac(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dma(unsigned long long int value) noexcept {
		return xieite::unit::dma(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dma(long double value) noexcept {
		return xieite::unit::dma(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ca(unsigned long long int value) noexcept {
		return xieite::unit::ca(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ca(long double value) noexcept {
		return xieite::unit::ca(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_da(unsigned long long int value) noexcept {
		return xieite::unit::da(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_da(long double value) noexcept {
		return xieite::unit::da(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_a(unsigned long long int value) noexcept {
		return xieite::unit::a(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_a(long double value) noexcept {
		return xieite::unit::a(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_da(unsigned long long int value) noexcept {
		return xieite::unit::da(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_da(long double value) noexcept {
		return xieite::unit::da(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ha(unsigned long long int value) noexcept {
		return xieite::unit::ha(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ha(long double value) noexcept {
		return xieite::unit::ha(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qV(unsigned long long int value) noexcept {
		return xieite::unit::qV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qV(long double value) noexcept {
		return xieite::unit::qV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rV(unsigned long long int value) noexcept {
		return xieite::unit::rV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rV(long double value) noexcept {
		return xieite::unit::rV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_yV(unsigned long long int value) noexcept {
		return xieite::unit::yV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_yV(long double value) noexcept {
		return xieite::unit::yV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_zV(unsigned long long int value) noexcept {
		return xieite::unit::zV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_zV(long double value) noexcept {
		return xieite::unit::zV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_aV(unsigned long long int value) noexcept {
		return xieite::unit::aV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_aV(long double value) noexcept {
		return xieite::unit::aV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fV(unsigned long long int value) noexcept {
		return xieite::unit::fV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fV(long double value) noexcept {
		return xieite::unit::fV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pV(unsigned long long int value) noexcept {
		return xieite::unit::pV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pV(long double value) noexcept {
		return xieite::unit::pV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nV(unsigned long long int value) noexcept {
		return xieite::unit::nV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nV(long double value) noexcept {
		return xieite::unit::nV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_uV(unsigned long long int value) noexcept {
		return xieite::unit::uV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_uV(long double value) noexcept {
		return xieite::unit::uV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mV(unsigned long long int value) noexcept {
		return xieite::unit::mV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mV(long double value) noexcept {
		return xieite::unit::mV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cV(unsigned long long int value) noexcept {
		return xieite::unit::cV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cV(long double value) noexcept {
		return xieite::unit::cV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dV(unsigned long long int value) noexcept {
		return xieite::unit::dV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dV(long double value) noexcept {
		return xieite::unit::dV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_V(unsigned long long int value) noexcept {
		return xieite::unit::V(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_V(long double value) noexcept {
		return xieite::unit::V(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_daV(unsigned long long int value) noexcept {
		return xieite::unit::daV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_daV(long double value) noexcept {
		return xieite::unit::daV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_hV(unsigned long long int value) noexcept {
		return xieite::unit::hV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_hV(long double value) noexcept {
		return xieite::unit::hV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_kV(unsigned long long int value) noexcept {
		return xieite::unit::kV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_kV(long double value) noexcept {
		return xieite::unit::kV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_MV(unsigned long long int value) noexcept {
		return xieite::unit::MV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_MV(long double value) noexcept {
		return xieite::unit::MV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_GV(unsigned long long int value) noexcept {
		return xieite::unit::GV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_GV(long double value) noexcept {
		return xieite::unit::GV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_TV(unsigned long long int value) noexcept {
		return xieite::unit::TV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_TV(long double value) noexcept {
		return xieite::unit::TV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_PV(unsigned long long int value) noexcept {
		return xieite::unit::PV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_PV(long double value) noexcept {
		return xieite::unit::PV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_EV(unsigned long long int value) noexcept {
		return xieite::unit::EV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_EV(long double value) noexcept {
		return xieite::unit::EV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ZV(unsigned long long int value) noexcept {
		return xieite::unit::ZV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ZV(long double value) noexcept {
		return xieite::unit::ZV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_YV(unsigned long long int value) noexcept {
		return xieite::unit::YV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_YV(long double value) noexcept {
		return xieite::unit::YV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_RV(unsigned long long int value) noexcept {
		return xieite::unit::RV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_RV(long double value) noexcept {
		return xieite::unit::RV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_QV(unsigned long long int value) noexcept {
		return xieite::unit::QV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_QV(long double value) noexcept {
		return xieite::unit::QV(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cu_in(unsigned long long int value) noexcept {
		return xieite::unit::cu_in(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cu_in(long double value) noexcept {
		return xieite::unit::cu_in(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cu_ft(unsigned long long int value) noexcept {
		return xieite::unit::cu_ft(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cu_ft(long double value) noexcept {
		return xieite::unit::cu_ft(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cu_yd(unsigned long long int value) noexcept {
		return xieite::unit::cu_yd(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cu_yd(long double value) noexcept {
		return xieite::unit::cu_yd(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cu_mi(unsigned long long int value) noexcept {
		return xieite::unit::cu_mi(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cu_mi(long double value) noexcept {
		return xieite::unit::cu_mi(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qL(unsigned long long int value) noexcept {
		return xieite::unit::qL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qL(long double value) noexcept {
		return xieite::unit::qL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rL(unsigned long long int value) noexcept {
		return xieite::unit::rL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rL(long double value) noexcept {
		return xieite::unit::rL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_yL(unsigned long long int value) noexcept {
		return xieite::unit::yL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_yL(long double value) noexcept {
		return xieite::unit::yL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_zL(unsigned long long int value) noexcept {
		return xieite::unit::zL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_zL(long double value) noexcept {
		return xieite::unit::zL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_aL(unsigned long long int value) noexcept {
		return xieite::unit::aL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_aL(long double value) noexcept {
		return xieite::unit::aL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fL(unsigned long long int value) noexcept {
		return xieite::unit::fL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fL(long double value) noexcept {
		return xieite::unit::fL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pL(unsigned long long int value) noexcept {
		return xieite::unit::pL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pL(long double value) noexcept {
		return xieite::unit::pL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nL(unsigned long long int value) noexcept {
		return xieite::unit::nL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_nL(long double value) noexcept {
		return xieite::unit::nL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_uL(unsigned long long int value) noexcept {
		return xieite::unit::uL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_uL(long double value) noexcept {
		return xieite::unit::uL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mL(unsigned long long int value) noexcept {
		return xieite::unit::mL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_mL(long double value) noexcept {
		return xieite::unit::mL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cL(unsigned long long int value) noexcept {
		return xieite::unit::cL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cL(long double value) noexcept {
		return xieite::unit::cL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dL(unsigned long long int value) noexcept {
		return xieite::unit::dL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_dL(long double value) noexcept {
		return xieite::unit::dL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_L(unsigned long long int value) noexcept {
		return xieite::unit::L(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_L(long double value) noexcept {
		return xieite::unit::L(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_daL(unsigned long long int value) noexcept {
		return xieite::unit::daL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_daL(long double value) noexcept {
		return xieite::unit::daL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_hL(unsigned long long int value) noexcept {
		return xieite::unit::hL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_hL(long double value) noexcept {
		return xieite::unit::hL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_kL(unsigned long long int value) noexcept {
		return xieite::unit::kL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_kL(long double value) noexcept {
		return xieite::unit::kL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ML(unsigned long long int value) noexcept {
		return xieite::unit::ML(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ML(long double value) noexcept {
		return xieite::unit::ML(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_GL(unsigned long long int value) noexcept {
		return xieite::unit::GL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_GL(long double value) noexcept {
		return xieite::unit::GL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_TL(unsigned long long int value) noexcept {
		return xieite::unit::TL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_TL(long double value) noexcept {
		return xieite::unit::TL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_PL(unsigned long long int value) noexcept {
		return xieite::unit::PL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_PL(long double value) noexcept {
		return xieite::unit::PL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_EL(unsigned long long int value) noexcept {
		return xieite::unit::EL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_EL(long double value) noexcept {
		return xieite::unit::EL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ZL(unsigned long long int value) noexcept {
		return xieite::unit::ZL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_ZL(long double value) noexcept {
		return xieite::unit::ZL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_YL(unsigned long long int value) noexcept {
		return xieite::unit::YL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_YL(long double value) noexcept {
		return xieite::unit::YL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_RL(unsigned long long int value) noexcept {
		return xieite::unit::RL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_RL(long double value) noexcept {
		return xieite::unit::RL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_QL(unsigned long long int value) noexcept {
		return xieite::unit::QL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_QL(long double value) noexcept {
		return xieite::unit::QL(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fl_oz(unsigned long long int value) noexcept {
		return xieite::unit::fl_oz(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_fl_oz(long double value) noexcept {
		return xieite::unit::fl_oz(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_gills(unsigned long long int value) noexcept {
		return xieite::unit::gills(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_gills(long double value) noexcept {
		return xieite::unit::gills(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cups(unsigned long long int value) noexcept {
		return xieite::unit::cups(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_cups(long double value) noexcept {
		return xieite::unit::cups(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pt(unsigned long long int value) noexcept {
		return xieite::unit::pt(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_pt(long double value) noexcept {
		return xieite::unit::pt(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qt(unsigned long long int value) noexcept {
		return xieite::unit::qt(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_qt(long double value) noexcept {
		return xieite::unit::qt(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_gal(unsigned long long int value) noexcept {
		return xieite::unit::gal(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_gal(long double value) noexcept {
		return xieite::unit::gal(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rad(unsigned long long int value) noexcept {
		return xieite::unit::rad(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_rad(long double value) noexcept {
		return xieite::unit::rad(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_deg(unsigned long long int value) noexcept {
		return xieite::unit::deg(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_deg(long double value) noexcept {
		return xieite::unit::deg(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_K(unsigned long long int value) noexcept {
		return xieite::unit::K(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_K(long double value) noexcept {
		return xieite::unit::K(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_C(unsigned long long int value) noexcept {
		return xieite::unit::C(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_C(long double value) noexcept {
		return xieite::unit::C(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_F(unsigned long long int value) noexcept {
		return xieite::unit::F(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_F(long double value) noexcept {
		return xieite::unit::F(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_R(unsigned long long int value) noexcept {
		return xieite::unit::R(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_R(long double value) noexcept {
		return xieite::unit::R(static_cast<double>(value));
	}

	[[nodiscard]] constexpr auto operator""_decades(unsigned long long int value) noexcept {
		return xieite::unit::decades(value);
	}

	[[nodiscard]] constexpr auto operator""_centuries(unsigned long long int value) noexcept {
		return xieite::unit::centuries(value);
	}

	[[nodiscard]] constexpr auto operator""_millenniums(unsigned long long int value) noexcept {
		return xieite::unit::millenniums(value);
	}

	[[nodiscard]] constexpr auto operator""_epochs(unsigned long long int value) noexcept {
		return xieite::unit::epochs(value);
	}

	[[nodiscard]] constexpr auto operator""_eons(unsigned long long int value) noexcept {
		return xieite::unit::eons(value);
	}
}

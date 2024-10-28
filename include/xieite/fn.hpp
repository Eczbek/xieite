#pragma once

#include <cstddef>
#include <tuple>
#include <xieite/diag.hpp>
#include <xieite/fwd.hpp>

#define XIEITE_FN(...) XIEITE_DETAIL_FN(&, __VA_ARGS__)
#define XIEITE_GFN(...) XIEITE_DETAIL_FN(, __VA_ARGS__)

XIEITE_DIAG_OFF_CLANG(-Wdollar-in-identifier-extension)

#define XIEITE_DETAIL_FN(capture, ...) \
	[capture][[nodiscard]](auto&&... $$) \
	noexcept(requires( \
		decltype(XIEITE_DETAIL::at<0>($$...)) $0, \
		decltype(XIEITE_DETAIL::at<1>($$...)) $1, \
		decltype(XIEITE_DETAIL::at<2>($$...)) $2, \
		decltype(XIEITE_DETAIL::at<3>($$...)) $3, \
		decltype(XIEITE_DETAIL::at<4>($$...)) $4, \
		decltype(XIEITE_DETAIL::at<5>($$...)) $5, \
		decltype(XIEITE_DETAIL::at<6>($$...)) $6, \
		decltype(XIEITE_DETAIL::at<7>($$...)) $7, \
		decltype(XIEITE_DETAIL::at<8>($$...)) $8, \
		decltype(XIEITE_DETAIL::at<9>($$...)) $9, \
		decltype(XIEITE_DETAIL::at<10>($$...)) $10, \
		decltype(XIEITE_DETAIL::at<11>($$...)) $11, \
		decltype(XIEITE_DETAIL::at<12>($$...)) $12, \
		decltype(XIEITE_DETAIL::at<13>($$...)) $13, \
		decltype(XIEITE_DETAIL::at<14>($$...)) $14, \
		decltype(XIEITE_DETAIL::at<15>($$...)) $15, \
		decltype(XIEITE_DETAIL::at<16>($$...)) $16, \
		decltype(XIEITE_DETAIL::at<17>($$...)) $17, \
		decltype(XIEITE_DETAIL::at<18>($$...)) $18, \
		decltype(XIEITE_DETAIL::at<19>($$...)) $19, \
		decltype(XIEITE_DETAIL::at<20>($$...)) $20, \
		decltype(XIEITE_DETAIL::at<21>($$...)) $21, \
		decltype(XIEITE_DETAIL::at<22>($$...)) $22, \
		decltype(XIEITE_DETAIL::at<23>($$...)) $23, \
		decltype(XIEITE_DETAIL::at<24>($$...)) $24, \
		decltype(XIEITE_DETAIL::at<25>($$...)) $25, \
		decltype(XIEITE_DETAIL::at<26>($$...)) $26, \
		decltype(XIEITE_DETAIL::at<27>($$...)) $27, \
		decltype(XIEITE_DETAIL::at<28>($$...)) $28, \
		decltype(XIEITE_DETAIL::at<29>($$...)) $29, \
		decltype(XIEITE_DETAIL::at<30>($$...)) $30, \
		decltype(XIEITE_DETAIL::at<31>($$...)) $31, \
		decltype(XIEITE_DETAIL::at<32>($$...)) $32, \
		decltype(XIEITE_DETAIL::at<33>($$...)) $33, \
		decltype(XIEITE_DETAIL::at<34>($$...)) $34, \
		decltype(XIEITE_DETAIL::at<35>($$...)) $35, \
		decltype(XIEITE_DETAIL::at<36>($$...)) $36, \
		decltype(XIEITE_DETAIL::at<37>($$...)) $37, \
		decltype(XIEITE_DETAIL::at<38>($$...)) $38, \
		decltype(XIEITE_DETAIL::at<39>($$...)) $39, \
		decltype(XIEITE_DETAIL::at<40>($$...)) $40, \
		decltype(XIEITE_DETAIL::at<41>($$...)) $41, \
		decltype(XIEITE_DETAIL::at<42>($$...)) $42, \
		decltype(XIEITE_DETAIL::at<43>($$...)) $43, \
		decltype(XIEITE_DETAIL::at<44>($$...)) $44, \
		decltype(XIEITE_DETAIL::at<45>($$...)) $45, \
		decltype(XIEITE_DETAIL::at<46>($$...)) $46, \
		decltype(XIEITE_DETAIL::at<47>($$...)) $47, \
		decltype(XIEITE_DETAIL::at<48>($$...)) $48, \
		decltype(XIEITE_DETAIL::at<49>($$...)) $49, \
		decltype(XIEITE_DETAIL::at<50>($$...)) $50, \
		decltype(XIEITE_DETAIL::at<51>($$...)) $51, \
		decltype(XIEITE_DETAIL::at<52>($$...)) $52, \
		decltype(XIEITE_DETAIL::at<53>($$...)) $53, \
		decltype(XIEITE_DETAIL::at<54>($$...)) $54, \
		decltype(XIEITE_DETAIL::at<55>($$...)) $55, \
		decltype(XIEITE_DETAIL::at<56>($$...)) $56, \
		decltype(XIEITE_DETAIL::at<57>($$...)) $57, \
		decltype(XIEITE_DETAIL::at<58>($$...)) $58, \
		decltype(XIEITE_DETAIL::at<59>($$...)) $59, \
		decltype(XIEITE_DETAIL::at<60>($$...)) $60, \
		decltype(XIEITE_DETAIL::at<61>($$...)) $61, \
		decltype(XIEITE_DETAIL::at<62>($$...)) $62, \
		decltype(XIEITE_DETAIL::at<63>($$...)) $63, \
		decltype(XIEITE_DETAIL::at<64>($$...)) $64, \
		decltype(XIEITE_DETAIL::at<65>($$...)) $65, \
		decltype(XIEITE_DETAIL::at<66>($$...)) $66, \
		decltype(XIEITE_DETAIL::at<67>($$...)) $67, \
		decltype(XIEITE_DETAIL::at<68>($$...)) $68, \
		decltype(XIEITE_DETAIL::at<69>($$...)) $69, \
		decltype(XIEITE_DETAIL::at<70>($$...)) $70, \
		decltype(XIEITE_DETAIL::at<71>($$...)) $71, \
		decltype(XIEITE_DETAIL::at<72>($$...)) $72, \
		decltype(XIEITE_DETAIL::at<73>($$...)) $73, \
		decltype(XIEITE_DETAIL::at<74>($$...)) $74, \
		decltype(XIEITE_DETAIL::at<75>($$...)) $75, \
		decltype(XIEITE_DETAIL::at<76>($$...)) $76, \
		decltype(XIEITE_DETAIL::at<77>($$...)) $77, \
		decltype(XIEITE_DETAIL::at<78>($$...)) $78, \
		decltype(XIEITE_DETAIL::at<79>($$...)) $79, \
		decltype(XIEITE_DETAIL::at<80>($$...)) $80, \
		decltype(XIEITE_DETAIL::at<81>($$...)) $81, \
		decltype(XIEITE_DETAIL::at<82>($$...)) $82, \
		decltype(XIEITE_DETAIL::at<83>($$...)) $83, \
		decltype(XIEITE_DETAIL::at<84>($$...)) $84, \
		decltype(XIEITE_DETAIL::at<85>($$...)) $85, \
		decltype(XIEITE_DETAIL::at<86>($$...)) $86, \
		decltype(XIEITE_DETAIL::at<87>($$...)) $87, \
		decltype(XIEITE_DETAIL::at<88>($$...)) $88, \
		decltype(XIEITE_DETAIL::at<89>($$...)) $89, \
		decltype(XIEITE_DETAIL::at<90>($$...)) $90, \
		decltype(XIEITE_DETAIL::at<91>($$...)) $91, \
		decltype(XIEITE_DETAIL::at<92>($$...)) $92, \
		decltype(XIEITE_DETAIL::at<93>($$...)) $93, \
		decltype(XIEITE_DETAIL::at<94>($$...)) $94, \
		decltype(XIEITE_DETAIL::at<95>($$...)) $95, \
		decltype(XIEITE_DETAIL::at<96>($$...)) $96, \
		decltype(XIEITE_DETAIL::at<97>($$...)) $97, \
		decltype(XIEITE_DETAIL::at<98>($$...)) $98, \
		decltype(XIEITE_DETAIL::at<99>($$...)) $99, \
		decltype(XIEITE_DETAIL::at<100>($$...)) $100, \
		decltype(XIEITE_DETAIL::at<101>($$...)) $101, \
		decltype(XIEITE_DETAIL::at<102>($$...)) $102, \
		decltype(XIEITE_DETAIL::at<103>($$...)) $103, \
		decltype(XIEITE_DETAIL::at<104>($$...)) $104, \
		decltype(XIEITE_DETAIL::at<105>($$...)) $105, \
		decltype(XIEITE_DETAIL::at<106>($$...)) $106, \
		decltype(XIEITE_DETAIL::at<107>($$...)) $107, \
		decltype(XIEITE_DETAIL::at<108>($$...)) $108, \
		decltype(XIEITE_DETAIL::at<109>($$...)) $109, \
		decltype(XIEITE_DETAIL::at<110>($$...)) $110, \
		decltype(XIEITE_DETAIL::at<111>($$...)) $111, \
		decltype(XIEITE_DETAIL::at<112>($$...)) $112, \
		decltype(XIEITE_DETAIL::at<113>($$...)) $113, \
		decltype(XIEITE_DETAIL::at<114>($$...)) $114, \
		decltype(XIEITE_DETAIL::at<115>($$...)) $115, \
		decltype(XIEITE_DETAIL::at<116>($$...)) $116, \
		decltype(XIEITE_DETAIL::at<117>($$...)) $117, \
		decltype(XIEITE_DETAIL::at<118>($$...)) $118, \
		decltype(XIEITE_DETAIL::at<119>($$...)) $119, \
		decltype(XIEITE_DETAIL::at<120>($$...)) $120, \
		decltype(XIEITE_DETAIL::at<121>($$...)) $121, \
		decltype(XIEITE_DETAIL::at<122>($$...)) $122, \
		decltype(XIEITE_DETAIL::at<123>($$...)) $123, \
		decltype(XIEITE_DETAIL::at<124>($$...)) $124, \
		decltype(XIEITE_DETAIL::at<125>($$...)) $125, \
		decltype(XIEITE_DETAIL::at<126>($$...)) $126, \
		decltype(XIEITE_DETAIL::at<127>($$...)) $127, \
		decltype(XIEITE_DETAIL::at<128>($$...)) $128, \
		decltype(XIEITE_DETAIL::at<129>($$...)) $129, \
		decltype(XIEITE_DETAIL::at<130>($$...)) $130, \
		decltype(XIEITE_DETAIL::at<131>($$...)) $131, \
		decltype(XIEITE_DETAIL::at<132>($$...)) $132, \
		decltype(XIEITE_DETAIL::at<133>($$...)) $133, \
		decltype(XIEITE_DETAIL::at<134>($$...)) $134, \
		decltype(XIEITE_DETAIL::at<135>($$...)) $135, \
		decltype(XIEITE_DETAIL::at<136>($$...)) $136, \
		decltype(XIEITE_DETAIL::at<137>($$...)) $137, \
		decltype(XIEITE_DETAIL::at<138>($$...)) $138, \
		decltype(XIEITE_DETAIL::at<139>($$...)) $139, \
		decltype(XIEITE_DETAIL::at<140>($$...)) $140, \
		decltype(XIEITE_DETAIL::at<141>($$...)) $141, \
		decltype(XIEITE_DETAIL::at<142>($$...)) $142, \
		decltype(XIEITE_DETAIL::at<143>($$...)) $143, \
		decltype(XIEITE_DETAIL::at<144>($$...)) $144, \
		decltype(XIEITE_DETAIL::at<145>($$...)) $145, \
		decltype(XIEITE_DETAIL::at<146>($$...)) $146, \
		decltype(XIEITE_DETAIL::at<147>($$...)) $147, \
		decltype(XIEITE_DETAIL::at<148>($$...)) $148, \
		decltype(XIEITE_DETAIL::at<149>($$...)) $149, \
		decltype(XIEITE_DETAIL::at<150>($$...)) $150, \
		decltype(XIEITE_DETAIL::at<151>($$...)) $151, \
		decltype(XIEITE_DETAIL::at<152>($$...)) $152, \
		decltype(XIEITE_DETAIL::at<153>($$...)) $153, \
		decltype(XIEITE_DETAIL::at<154>($$...)) $154, \
		decltype(XIEITE_DETAIL::at<155>($$...)) $155, \
		decltype(XIEITE_DETAIL::at<156>($$...)) $156, \
		decltype(XIEITE_DETAIL::at<157>($$...)) $157, \
		decltype(XIEITE_DETAIL::at<158>($$...)) $158, \
		decltype(XIEITE_DETAIL::at<159>($$...)) $159, \
		decltype(XIEITE_DETAIL::at<160>($$...)) $160, \
		decltype(XIEITE_DETAIL::at<161>($$...)) $161, \
		decltype(XIEITE_DETAIL::at<162>($$...)) $162, \
		decltype(XIEITE_DETAIL::at<163>($$...)) $163, \
		decltype(XIEITE_DETAIL::at<164>($$...)) $164, \
		decltype(XIEITE_DETAIL::at<165>($$...)) $165, \
		decltype(XIEITE_DETAIL::at<166>($$...)) $166, \
		decltype(XIEITE_DETAIL::at<167>($$...)) $167, \
		decltype(XIEITE_DETAIL::at<168>($$...)) $168, \
		decltype(XIEITE_DETAIL::at<169>($$...)) $169, \
		decltype(XIEITE_DETAIL::at<170>($$...)) $170, \
		decltype(XIEITE_DETAIL::at<171>($$...)) $171, \
		decltype(XIEITE_DETAIL::at<172>($$...)) $172, \
		decltype(XIEITE_DETAIL::at<173>($$...)) $173, \
		decltype(XIEITE_DETAIL::at<174>($$...)) $174, \
		decltype(XIEITE_DETAIL::at<175>($$...)) $175, \
		decltype(XIEITE_DETAIL::at<176>($$...)) $176, \
		decltype(XIEITE_DETAIL::at<177>($$...)) $177, \
		decltype(XIEITE_DETAIL::at<178>($$...)) $178, \
		decltype(XIEITE_DETAIL::at<179>($$...)) $179, \
		decltype(XIEITE_DETAIL::at<180>($$...)) $180, \
		decltype(XIEITE_DETAIL::at<181>($$...)) $181, \
		decltype(XIEITE_DETAIL::at<182>($$...)) $182, \
		decltype(XIEITE_DETAIL::at<183>($$...)) $183, \
		decltype(XIEITE_DETAIL::at<184>($$...)) $184, \
		decltype(XIEITE_DETAIL::at<185>($$...)) $185, \
		decltype(XIEITE_DETAIL::at<186>($$...)) $186, \
		decltype(XIEITE_DETAIL::at<187>($$...)) $187, \
		decltype(XIEITE_DETAIL::at<188>($$...)) $188, \
		decltype(XIEITE_DETAIL::at<189>($$...)) $189, \
		decltype(XIEITE_DETAIL::at<190>($$...)) $190, \
		decltype(XIEITE_DETAIL::at<191>($$...)) $191, \
		decltype(XIEITE_DETAIL::at<192>($$...)) $192, \
		decltype(XIEITE_DETAIL::at<193>($$...)) $193, \
		decltype(XIEITE_DETAIL::at<194>($$...)) $194, \
		decltype(XIEITE_DETAIL::at<195>($$...)) $195, \
		decltype(XIEITE_DETAIL::at<196>($$...)) $196, \
		decltype(XIEITE_DETAIL::at<197>($$...)) $197, \
		decltype(XIEITE_DETAIL::at<198>($$...)) $198, \
		decltype(XIEITE_DETAIL::at<199>($$...)) $199, \
		decltype(XIEITE_DETAIL::at<200>($$...)) $200, \
		decltype(XIEITE_DETAIL::at<201>($$...)) $201, \
		decltype(XIEITE_DETAIL::at<202>($$...)) $202, \
		decltype(XIEITE_DETAIL::at<203>($$...)) $203, \
		decltype(XIEITE_DETAIL::at<204>($$...)) $204, \
		decltype(XIEITE_DETAIL::at<205>($$...)) $205, \
		decltype(XIEITE_DETAIL::at<206>($$...)) $206, \
		decltype(XIEITE_DETAIL::at<207>($$...)) $207, \
		decltype(XIEITE_DETAIL::at<208>($$...)) $208, \
		decltype(XIEITE_DETAIL::at<209>($$...)) $209, \
		decltype(XIEITE_DETAIL::at<210>($$...)) $210, \
		decltype(XIEITE_DETAIL::at<211>($$...)) $211, \
		decltype(XIEITE_DETAIL::at<212>($$...)) $212, \
		decltype(XIEITE_DETAIL::at<213>($$...)) $213, \
		decltype(XIEITE_DETAIL::at<214>($$...)) $214, \
		decltype(XIEITE_DETAIL::at<215>($$...)) $215, \
		decltype(XIEITE_DETAIL::at<216>($$...)) $216, \
		decltype(XIEITE_DETAIL::at<217>($$...)) $217, \
		decltype(XIEITE_DETAIL::at<218>($$...)) $218, \
		decltype(XIEITE_DETAIL::at<219>($$...)) $219, \
		decltype(XIEITE_DETAIL::at<220>($$...)) $220, \
		decltype(XIEITE_DETAIL::at<221>($$...)) $221, \
		decltype(XIEITE_DETAIL::at<222>($$...)) $222, \
		decltype(XIEITE_DETAIL::at<223>($$...)) $223, \
		decltype(XIEITE_DETAIL::at<224>($$...)) $224, \
		decltype(XIEITE_DETAIL::at<225>($$...)) $225, \
		decltype(XIEITE_DETAIL::at<226>($$...)) $226, \
		decltype(XIEITE_DETAIL::at<227>($$...)) $227, \
		decltype(XIEITE_DETAIL::at<228>($$...)) $228, \
		decltype(XIEITE_DETAIL::at<229>($$...)) $229, \
		decltype(XIEITE_DETAIL::at<230>($$...)) $230, \
		decltype(XIEITE_DETAIL::at<231>($$...)) $231, \
		decltype(XIEITE_DETAIL::at<232>($$...)) $232, \
		decltype(XIEITE_DETAIL::at<233>($$...)) $233, \
		decltype(XIEITE_DETAIL::at<234>($$...)) $234, \
		decltype(XIEITE_DETAIL::at<235>($$...)) $235, \
		decltype(XIEITE_DETAIL::at<236>($$...)) $236, \
		decltype(XIEITE_DETAIL::at<237>($$...)) $237, \
		decltype(XIEITE_DETAIL::at<238>($$...)) $238, \
		decltype(XIEITE_DETAIL::at<239>($$...)) $239, \
		decltype(XIEITE_DETAIL::at<240>($$...)) $240, \
		decltype(XIEITE_DETAIL::at<241>($$...)) $241, \
		decltype(XIEITE_DETAIL::at<242>($$...)) $242, \
		decltype(XIEITE_DETAIL::at<243>($$...)) $243, \
		decltype(XIEITE_DETAIL::at<244>($$...)) $244, \
		decltype(XIEITE_DETAIL::at<245>($$...)) $245, \
		decltype(XIEITE_DETAIL::at<246>($$...)) $246, \
		decltype(XIEITE_DETAIL::at<247>($$...)) $247, \
		decltype(XIEITE_DETAIL::at<248>($$...)) $248, \
		decltype(XIEITE_DETAIL::at<249>($$...)) $249, \
		decltype(XIEITE_DETAIL::at<250>($$...)) $250, \
		decltype(XIEITE_DETAIL::at<251>($$...)) $251, \
		decltype(XIEITE_DETAIL::at<252>($$...)) $252, \
		decltype(XIEITE_DETAIL::at<253>($$...)) $253, \
		decltype(XIEITE_DETAIL::at<254>($$...)) $254, \
		decltype(XIEITE_DETAIL::at<255>($$...)) $255, \
		decltype(XIEITE_DETAIL::at<256>($$...)) $256 \
	) { requires(noexcept(__VA_ARGS__)); }) -> decltype(auto) { \
		[[maybe_unused]] auto&& $0 = XIEITE_DETAIL::at<0>($$...); \
		[[maybe_unused]] auto&& $1 = XIEITE_DETAIL::at<1>($$...); \
		[[maybe_unused]] auto&& $2 = XIEITE_DETAIL::at<2>($$...); \
		[[maybe_unused]] auto&& $3 = XIEITE_DETAIL::at<3>($$...); \
		[[maybe_unused]] auto&& $4 = XIEITE_DETAIL::at<4>($$...); \
		[[maybe_unused]] auto&& $5 = XIEITE_DETAIL::at<5>($$...); \
		[[maybe_unused]] auto&& $6 = XIEITE_DETAIL::at<6>($$...); \
		[[maybe_unused]] auto&& $7 = XIEITE_DETAIL::at<7>($$...); \
		[[maybe_unused]] auto&& $8 = XIEITE_DETAIL::at<8>($$...); \
		[[maybe_unused]] auto&& $9 = XIEITE_DETAIL::at<9>($$...); \
		[[maybe_unused]] auto&& $10 = XIEITE_DETAIL::at<10>($$...); \
		[[maybe_unused]] auto&& $11 = XIEITE_DETAIL::at<11>($$...); \
		[[maybe_unused]] auto&& $12 = XIEITE_DETAIL::at<12>($$...); \
		[[maybe_unused]] auto&& $13 = XIEITE_DETAIL::at<13>($$...); \
		[[maybe_unused]] auto&& $14 = XIEITE_DETAIL::at<14>($$...); \
		[[maybe_unused]] auto&& $15 = XIEITE_DETAIL::at<15>($$...); \
		[[maybe_unused]] auto&& $16 = XIEITE_DETAIL::at<16>($$...); \
		[[maybe_unused]] auto&& $17 = XIEITE_DETAIL::at<17>($$...); \
		[[maybe_unused]] auto&& $18 = XIEITE_DETAIL::at<18>($$...); \
		[[maybe_unused]] auto&& $19 = XIEITE_DETAIL::at<19>($$...); \
		[[maybe_unused]] auto&& $20 = XIEITE_DETAIL::at<20>($$...); \
		[[maybe_unused]] auto&& $21 = XIEITE_DETAIL::at<21>($$...); \
		[[maybe_unused]] auto&& $22 = XIEITE_DETAIL::at<22>($$...); \
		[[maybe_unused]] auto&& $23 = XIEITE_DETAIL::at<23>($$...); \
		[[maybe_unused]] auto&& $24 = XIEITE_DETAIL::at<24>($$...); \
		[[maybe_unused]] auto&& $25 = XIEITE_DETAIL::at<25>($$...); \
		[[maybe_unused]] auto&& $26 = XIEITE_DETAIL::at<26>($$...); \
		[[maybe_unused]] auto&& $27 = XIEITE_DETAIL::at<27>($$...); \
		[[maybe_unused]] auto&& $28 = XIEITE_DETAIL::at<28>($$...); \
		[[maybe_unused]] auto&& $29 = XIEITE_DETAIL::at<29>($$...); \
		[[maybe_unused]] auto&& $30 = XIEITE_DETAIL::at<30>($$...); \
		[[maybe_unused]] auto&& $31 = XIEITE_DETAIL::at<31>($$...); \
		[[maybe_unused]] auto&& $32 = XIEITE_DETAIL::at<32>($$...); \
		[[maybe_unused]] auto&& $33 = XIEITE_DETAIL::at<33>($$...); \
		[[maybe_unused]] auto&& $34 = XIEITE_DETAIL::at<34>($$...); \
		[[maybe_unused]] auto&& $35 = XIEITE_DETAIL::at<35>($$...); \
		[[maybe_unused]] auto&& $36 = XIEITE_DETAIL::at<36>($$...); \
		[[maybe_unused]] auto&& $37 = XIEITE_DETAIL::at<37>($$...); \
		[[maybe_unused]] auto&& $38 = XIEITE_DETAIL::at<38>($$...); \
		[[maybe_unused]] auto&& $39 = XIEITE_DETAIL::at<39>($$...); \
		[[maybe_unused]] auto&& $40 = XIEITE_DETAIL::at<40>($$...); \
		[[maybe_unused]] auto&& $41 = XIEITE_DETAIL::at<41>($$...); \
		[[maybe_unused]] auto&& $42 = XIEITE_DETAIL::at<42>($$...); \
		[[maybe_unused]] auto&& $43 = XIEITE_DETAIL::at<43>($$...); \
		[[maybe_unused]] auto&& $44 = XIEITE_DETAIL::at<44>($$...); \
		[[maybe_unused]] auto&& $45 = XIEITE_DETAIL::at<45>($$...); \
		[[maybe_unused]] auto&& $46 = XIEITE_DETAIL::at<46>($$...); \
		[[maybe_unused]] auto&& $47 = XIEITE_DETAIL::at<47>($$...); \
		[[maybe_unused]] auto&& $48 = XIEITE_DETAIL::at<48>($$...); \
		[[maybe_unused]] auto&& $49 = XIEITE_DETAIL::at<49>($$...); \
		[[maybe_unused]] auto&& $50 = XIEITE_DETAIL::at<50>($$...); \
		[[maybe_unused]] auto&& $51 = XIEITE_DETAIL::at<51>($$...); \
		[[maybe_unused]] auto&& $52 = XIEITE_DETAIL::at<52>($$...); \
		[[maybe_unused]] auto&& $53 = XIEITE_DETAIL::at<53>($$...); \
		[[maybe_unused]] auto&& $54 = XIEITE_DETAIL::at<54>($$...); \
		[[maybe_unused]] auto&& $55 = XIEITE_DETAIL::at<55>($$...); \
		[[maybe_unused]] auto&& $56 = XIEITE_DETAIL::at<56>($$...); \
		[[maybe_unused]] auto&& $57 = XIEITE_DETAIL::at<57>($$...); \
		[[maybe_unused]] auto&& $58 = XIEITE_DETAIL::at<58>($$...); \
		[[maybe_unused]] auto&& $59 = XIEITE_DETAIL::at<59>($$...); \
		[[maybe_unused]] auto&& $60 = XIEITE_DETAIL::at<60>($$...); \
		[[maybe_unused]] auto&& $61 = XIEITE_DETAIL::at<61>($$...); \
		[[maybe_unused]] auto&& $62 = XIEITE_DETAIL::at<62>($$...); \
		[[maybe_unused]] auto&& $63 = XIEITE_DETAIL::at<63>($$...); \
		[[maybe_unused]] auto&& $64 = XIEITE_DETAIL::at<64>($$...); \
		[[maybe_unused]] auto&& $65 = XIEITE_DETAIL::at<65>($$...); \
		[[maybe_unused]] auto&& $66 = XIEITE_DETAIL::at<66>($$...); \
		[[maybe_unused]] auto&& $67 = XIEITE_DETAIL::at<67>($$...); \
		[[maybe_unused]] auto&& $68 = XIEITE_DETAIL::at<68>($$...); \
		[[maybe_unused]] auto&& $69 = XIEITE_DETAIL::at<69>($$...); \
		[[maybe_unused]] auto&& $70 = XIEITE_DETAIL::at<70>($$...); \
		[[maybe_unused]] auto&& $71 = XIEITE_DETAIL::at<71>($$...); \
		[[maybe_unused]] auto&& $72 = XIEITE_DETAIL::at<72>($$...); \
		[[maybe_unused]] auto&& $73 = XIEITE_DETAIL::at<73>($$...); \
		[[maybe_unused]] auto&& $74 = XIEITE_DETAIL::at<74>($$...); \
		[[maybe_unused]] auto&& $75 = XIEITE_DETAIL::at<75>($$...); \
		[[maybe_unused]] auto&& $76 = XIEITE_DETAIL::at<76>($$...); \
		[[maybe_unused]] auto&& $77 = XIEITE_DETAIL::at<77>($$...); \
		[[maybe_unused]] auto&& $78 = XIEITE_DETAIL::at<78>($$...); \
		[[maybe_unused]] auto&& $79 = XIEITE_DETAIL::at<79>($$...); \
		[[maybe_unused]] auto&& $80 = XIEITE_DETAIL::at<80>($$...); \
		[[maybe_unused]] auto&& $81 = XIEITE_DETAIL::at<81>($$...); \
		[[maybe_unused]] auto&& $82 = XIEITE_DETAIL::at<82>($$...); \
		[[maybe_unused]] auto&& $83 = XIEITE_DETAIL::at<83>($$...); \
		[[maybe_unused]] auto&& $84 = XIEITE_DETAIL::at<84>($$...); \
		[[maybe_unused]] auto&& $85 = XIEITE_DETAIL::at<85>($$...); \
		[[maybe_unused]] auto&& $86 = XIEITE_DETAIL::at<86>($$...); \
		[[maybe_unused]] auto&& $87 = XIEITE_DETAIL::at<87>($$...); \
		[[maybe_unused]] auto&& $88 = XIEITE_DETAIL::at<88>($$...); \
		[[maybe_unused]] auto&& $89 = XIEITE_DETAIL::at<89>($$...); \
		[[maybe_unused]] auto&& $90 = XIEITE_DETAIL::at<90>($$...); \
		[[maybe_unused]] auto&& $91 = XIEITE_DETAIL::at<91>($$...); \
		[[maybe_unused]] auto&& $92 = XIEITE_DETAIL::at<92>($$...); \
		[[maybe_unused]] auto&& $93 = XIEITE_DETAIL::at<93>($$...); \
		[[maybe_unused]] auto&& $94 = XIEITE_DETAIL::at<94>($$...); \
		[[maybe_unused]] auto&& $95 = XIEITE_DETAIL::at<95>($$...); \
		[[maybe_unused]] auto&& $96 = XIEITE_DETAIL::at<96>($$...); \
		[[maybe_unused]] auto&& $97 = XIEITE_DETAIL::at<97>($$...); \
		[[maybe_unused]] auto&& $98 = XIEITE_DETAIL::at<98>($$...); \
		[[maybe_unused]] auto&& $99 = XIEITE_DETAIL::at<99>($$...); \
		[[maybe_unused]] auto&& $100 = XIEITE_DETAIL::at<100>($$...); \
		[[maybe_unused]] auto&& $101 = XIEITE_DETAIL::at<101>($$...); \
		[[maybe_unused]] auto&& $102 = XIEITE_DETAIL::at<102>($$...); \
		[[maybe_unused]] auto&& $103 = XIEITE_DETAIL::at<103>($$...); \
		[[maybe_unused]] auto&& $104 = XIEITE_DETAIL::at<104>($$...); \
		[[maybe_unused]] auto&& $105 = XIEITE_DETAIL::at<105>($$...); \
		[[maybe_unused]] auto&& $106 = XIEITE_DETAIL::at<106>($$...); \
		[[maybe_unused]] auto&& $107 = XIEITE_DETAIL::at<107>($$...); \
		[[maybe_unused]] auto&& $108 = XIEITE_DETAIL::at<108>($$...); \
		[[maybe_unused]] auto&& $109 = XIEITE_DETAIL::at<109>($$...); \
		[[maybe_unused]] auto&& $110 = XIEITE_DETAIL::at<110>($$...); \
		[[maybe_unused]] auto&& $111 = XIEITE_DETAIL::at<111>($$...); \
		[[maybe_unused]] auto&& $112 = XIEITE_DETAIL::at<112>($$...); \
		[[maybe_unused]] auto&& $113 = XIEITE_DETAIL::at<113>($$...); \
		[[maybe_unused]] auto&& $114 = XIEITE_DETAIL::at<114>($$...); \
		[[maybe_unused]] auto&& $115 = XIEITE_DETAIL::at<115>($$...); \
		[[maybe_unused]] auto&& $116 = XIEITE_DETAIL::at<116>($$...); \
		[[maybe_unused]] auto&& $117 = XIEITE_DETAIL::at<117>($$...); \
		[[maybe_unused]] auto&& $118 = XIEITE_DETAIL::at<118>($$...); \
		[[maybe_unused]] auto&& $119 = XIEITE_DETAIL::at<119>($$...); \
		[[maybe_unused]] auto&& $120 = XIEITE_DETAIL::at<120>($$...); \
		[[maybe_unused]] auto&& $121 = XIEITE_DETAIL::at<121>($$...); \
		[[maybe_unused]] auto&& $122 = XIEITE_DETAIL::at<122>($$...); \
		[[maybe_unused]] auto&& $123 = XIEITE_DETAIL::at<123>($$...); \
		[[maybe_unused]] auto&& $124 = XIEITE_DETAIL::at<124>($$...); \
		[[maybe_unused]] auto&& $125 = XIEITE_DETAIL::at<125>($$...); \
		[[maybe_unused]] auto&& $126 = XIEITE_DETAIL::at<126>($$...); \
		[[maybe_unused]] auto&& $127 = XIEITE_DETAIL::at<127>($$...); \
		[[maybe_unused]] auto&& $128 = XIEITE_DETAIL::at<128>($$...); \
		[[maybe_unused]] auto&& $129 = XIEITE_DETAIL::at<129>($$...); \
		[[maybe_unused]] auto&& $130 = XIEITE_DETAIL::at<130>($$...); \
		[[maybe_unused]] auto&& $131 = XIEITE_DETAIL::at<131>($$...); \
		[[maybe_unused]] auto&& $132 = XIEITE_DETAIL::at<132>($$...); \
		[[maybe_unused]] auto&& $133 = XIEITE_DETAIL::at<133>($$...); \
		[[maybe_unused]] auto&& $134 = XIEITE_DETAIL::at<134>($$...); \
		[[maybe_unused]] auto&& $135 = XIEITE_DETAIL::at<135>($$...); \
		[[maybe_unused]] auto&& $136 = XIEITE_DETAIL::at<136>($$...); \
		[[maybe_unused]] auto&& $137 = XIEITE_DETAIL::at<137>($$...); \
		[[maybe_unused]] auto&& $138 = XIEITE_DETAIL::at<138>($$...); \
		[[maybe_unused]] auto&& $139 = XIEITE_DETAIL::at<139>($$...); \
		[[maybe_unused]] auto&& $140 = XIEITE_DETAIL::at<140>($$...); \
		[[maybe_unused]] auto&& $141 = XIEITE_DETAIL::at<141>($$...); \
		[[maybe_unused]] auto&& $142 = XIEITE_DETAIL::at<142>($$...); \
		[[maybe_unused]] auto&& $143 = XIEITE_DETAIL::at<143>($$...); \
		[[maybe_unused]] auto&& $144 = XIEITE_DETAIL::at<144>($$...); \
		[[maybe_unused]] auto&& $145 = XIEITE_DETAIL::at<145>($$...); \
		[[maybe_unused]] auto&& $146 = XIEITE_DETAIL::at<146>($$...); \
		[[maybe_unused]] auto&& $147 = XIEITE_DETAIL::at<147>($$...); \
		[[maybe_unused]] auto&& $148 = XIEITE_DETAIL::at<148>($$...); \
		[[maybe_unused]] auto&& $149 = XIEITE_DETAIL::at<149>($$...); \
		[[maybe_unused]] auto&& $150 = XIEITE_DETAIL::at<150>($$...); \
		[[maybe_unused]] auto&& $151 = XIEITE_DETAIL::at<151>($$...); \
		[[maybe_unused]] auto&& $152 = XIEITE_DETAIL::at<152>($$...); \
		[[maybe_unused]] auto&& $153 = XIEITE_DETAIL::at<153>($$...); \
		[[maybe_unused]] auto&& $154 = XIEITE_DETAIL::at<154>($$...); \
		[[maybe_unused]] auto&& $155 = XIEITE_DETAIL::at<155>($$...); \
		[[maybe_unused]] auto&& $156 = XIEITE_DETAIL::at<156>($$...); \
		[[maybe_unused]] auto&& $157 = XIEITE_DETAIL::at<157>($$...); \
		[[maybe_unused]] auto&& $158 = XIEITE_DETAIL::at<158>($$...); \
		[[maybe_unused]] auto&& $159 = XIEITE_DETAIL::at<159>($$...); \
		[[maybe_unused]] auto&& $160 = XIEITE_DETAIL::at<160>($$...); \
		[[maybe_unused]] auto&& $161 = XIEITE_DETAIL::at<161>($$...); \
		[[maybe_unused]] auto&& $162 = XIEITE_DETAIL::at<162>($$...); \
		[[maybe_unused]] auto&& $163 = XIEITE_DETAIL::at<163>($$...); \
		[[maybe_unused]] auto&& $164 = XIEITE_DETAIL::at<164>($$...); \
		[[maybe_unused]] auto&& $165 = XIEITE_DETAIL::at<165>($$...); \
		[[maybe_unused]] auto&& $166 = XIEITE_DETAIL::at<166>($$...); \
		[[maybe_unused]] auto&& $167 = XIEITE_DETAIL::at<167>($$...); \
		[[maybe_unused]] auto&& $168 = XIEITE_DETAIL::at<168>($$...); \
		[[maybe_unused]] auto&& $169 = XIEITE_DETAIL::at<169>($$...); \
		[[maybe_unused]] auto&& $170 = XIEITE_DETAIL::at<170>($$...); \
		[[maybe_unused]] auto&& $171 = XIEITE_DETAIL::at<171>($$...); \
		[[maybe_unused]] auto&& $172 = XIEITE_DETAIL::at<172>($$...); \
		[[maybe_unused]] auto&& $173 = XIEITE_DETAIL::at<173>($$...); \
		[[maybe_unused]] auto&& $174 = XIEITE_DETAIL::at<174>($$...); \
		[[maybe_unused]] auto&& $175 = XIEITE_DETAIL::at<175>($$...); \
		[[maybe_unused]] auto&& $176 = XIEITE_DETAIL::at<176>($$...); \
		[[maybe_unused]] auto&& $177 = XIEITE_DETAIL::at<177>($$...); \
		[[maybe_unused]] auto&& $178 = XIEITE_DETAIL::at<178>($$...); \
		[[maybe_unused]] auto&& $179 = XIEITE_DETAIL::at<179>($$...); \
		[[maybe_unused]] auto&& $180 = XIEITE_DETAIL::at<180>($$...); \
		[[maybe_unused]] auto&& $181 = XIEITE_DETAIL::at<181>($$...); \
		[[maybe_unused]] auto&& $182 = XIEITE_DETAIL::at<182>($$...); \
		[[maybe_unused]] auto&& $183 = XIEITE_DETAIL::at<183>($$...); \
		[[maybe_unused]] auto&& $184 = XIEITE_DETAIL::at<184>($$...); \
		[[maybe_unused]] auto&& $185 = XIEITE_DETAIL::at<185>($$...); \
		[[maybe_unused]] auto&& $186 = XIEITE_DETAIL::at<186>($$...); \
		[[maybe_unused]] auto&& $187 = XIEITE_DETAIL::at<187>($$...); \
		[[maybe_unused]] auto&& $188 = XIEITE_DETAIL::at<188>($$...); \
		[[maybe_unused]] auto&& $189 = XIEITE_DETAIL::at<189>($$...); \
		[[maybe_unused]] auto&& $190 = XIEITE_DETAIL::at<190>($$...); \
		[[maybe_unused]] auto&& $191 = XIEITE_DETAIL::at<191>($$...); \
		[[maybe_unused]] auto&& $192 = XIEITE_DETAIL::at<192>($$...); \
		[[maybe_unused]] auto&& $193 = XIEITE_DETAIL::at<193>($$...); \
		[[maybe_unused]] auto&& $194 = XIEITE_DETAIL::at<194>($$...); \
		[[maybe_unused]] auto&& $195 = XIEITE_DETAIL::at<195>($$...); \
		[[maybe_unused]] auto&& $196 = XIEITE_DETAIL::at<196>($$...); \
		[[maybe_unused]] auto&& $197 = XIEITE_DETAIL::at<197>($$...); \
		[[maybe_unused]] auto&& $198 = XIEITE_DETAIL::at<198>($$...); \
		[[maybe_unused]] auto&& $199 = XIEITE_DETAIL::at<199>($$...); \
		[[maybe_unused]] auto&& $200 = XIEITE_DETAIL::at<200>($$...); \
		[[maybe_unused]] auto&& $201 = XIEITE_DETAIL::at<201>($$...); \
		[[maybe_unused]] auto&& $202 = XIEITE_DETAIL::at<202>($$...); \
		[[maybe_unused]] auto&& $203 = XIEITE_DETAIL::at<203>($$...); \
		[[maybe_unused]] auto&& $204 = XIEITE_DETAIL::at<204>($$...); \
		[[maybe_unused]] auto&& $205 = XIEITE_DETAIL::at<205>($$...); \
		[[maybe_unused]] auto&& $206 = XIEITE_DETAIL::at<206>($$...); \
		[[maybe_unused]] auto&& $207 = XIEITE_DETAIL::at<207>($$...); \
		[[maybe_unused]] auto&& $208 = XIEITE_DETAIL::at<208>($$...); \
		[[maybe_unused]] auto&& $209 = XIEITE_DETAIL::at<209>($$...); \
		[[maybe_unused]] auto&& $210 = XIEITE_DETAIL::at<210>($$...); \
		[[maybe_unused]] auto&& $211 = XIEITE_DETAIL::at<211>($$...); \
		[[maybe_unused]] auto&& $212 = XIEITE_DETAIL::at<212>($$...); \
		[[maybe_unused]] auto&& $213 = XIEITE_DETAIL::at<213>($$...); \
		[[maybe_unused]] auto&& $214 = XIEITE_DETAIL::at<214>($$...); \
		[[maybe_unused]] auto&& $215 = XIEITE_DETAIL::at<215>($$...); \
		[[maybe_unused]] auto&& $216 = XIEITE_DETAIL::at<216>($$...); \
		[[maybe_unused]] auto&& $217 = XIEITE_DETAIL::at<217>($$...); \
		[[maybe_unused]] auto&& $218 = XIEITE_DETAIL::at<218>($$...); \
		[[maybe_unused]] auto&& $219 = XIEITE_DETAIL::at<219>($$...); \
		[[maybe_unused]] auto&& $220 = XIEITE_DETAIL::at<220>($$...); \
		[[maybe_unused]] auto&& $221 = XIEITE_DETAIL::at<221>($$...); \
		[[maybe_unused]] auto&& $222 = XIEITE_DETAIL::at<222>($$...); \
		[[maybe_unused]] auto&& $223 = XIEITE_DETAIL::at<223>($$...); \
		[[maybe_unused]] auto&& $224 = XIEITE_DETAIL::at<224>($$...); \
		[[maybe_unused]] auto&& $225 = XIEITE_DETAIL::at<225>($$...); \
		[[maybe_unused]] auto&& $226 = XIEITE_DETAIL::at<226>($$...); \
		[[maybe_unused]] auto&& $227 = XIEITE_DETAIL::at<227>($$...); \
		[[maybe_unused]] auto&& $228 = XIEITE_DETAIL::at<228>($$...); \
		[[maybe_unused]] auto&& $229 = XIEITE_DETAIL::at<229>($$...); \
		[[maybe_unused]] auto&& $230 = XIEITE_DETAIL::at<230>($$...); \
		[[maybe_unused]] auto&& $231 = XIEITE_DETAIL::at<231>($$...); \
		[[maybe_unused]] auto&& $232 = XIEITE_DETAIL::at<232>($$...); \
		[[maybe_unused]] auto&& $233 = XIEITE_DETAIL::at<233>($$...); \
		[[maybe_unused]] auto&& $234 = XIEITE_DETAIL::at<234>($$...); \
		[[maybe_unused]] auto&& $235 = XIEITE_DETAIL::at<235>($$...); \
		[[maybe_unused]] auto&& $236 = XIEITE_DETAIL::at<236>($$...); \
		[[maybe_unused]] auto&& $237 = XIEITE_DETAIL::at<237>($$...); \
		[[maybe_unused]] auto&& $238 = XIEITE_DETAIL::at<238>($$...); \
		[[maybe_unused]] auto&& $239 = XIEITE_DETAIL::at<239>($$...); \
		[[maybe_unused]] auto&& $240 = XIEITE_DETAIL::at<240>($$...); \
		[[maybe_unused]] auto&& $241 = XIEITE_DETAIL::at<241>($$...); \
		[[maybe_unused]] auto&& $242 = XIEITE_DETAIL::at<242>($$...); \
		[[maybe_unused]] auto&& $243 = XIEITE_DETAIL::at<243>($$...); \
		[[maybe_unused]] auto&& $244 = XIEITE_DETAIL::at<244>($$...); \
		[[maybe_unused]] auto&& $245 = XIEITE_DETAIL::at<245>($$...); \
		[[maybe_unused]] auto&& $246 = XIEITE_DETAIL::at<246>($$...); \
		[[maybe_unused]] auto&& $247 = XIEITE_DETAIL::at<247>($$...); \
		[[maybe_unused]] auto&& $248 = XIEITE_DETAIL::at<248>($$...); \
		[[maybe_unused]] auto&& $249 = XIEITE_DETAIL::at<249>($$...); \
		[[maybe_unused]] auto&& $250 = XIEITE_DETAIL::at<250>($$...); \
		[[maybe_unused]] auto&& $251 = XIEITE_DETAIL::at<251>($$...); \
		[[maybe_unused]] auto&& $252 = XIEITE_DETAIL::at<252>($$...); \
		[[maybe_unused]] auto&& $253 = XIEITE_DETAIL::at<253>($$...); \
		[[maybe_unused]] auto&& $254 = XIEITE_DETAIL::at<254>($$...); \
		[[maybe_unused]] auto&& $255 = XIEITE_DETAIL::at<255>($$...); \
		[[maybe_unused]] auto&& $256 = XIEITE_DETAIL::at<256>($$...); \
		return (__VA_ARGS__); \
	}

namespace XIEITE_DETAIL {
	template<std::size_t idx>
	[[nodiscard]] constexpr decltype(auto) at(auto&&... args) noexcept {
		if constexpr (idx < sizeof...(args)) {
			return std::get<idx>(std::forward_as_tuple(XIEITE_FWD(args)...));
		} else {
			struct nit {
				nit() = default;
				nit(const nit&) = delete;
				nit(nit&&) = delete;
				auto operator=(const nit&) = delete;
				auto operator=(nit&&) = delete;
			};
			return nit();
		}
	}
}

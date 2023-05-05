#pragma once

#include <xieite/macros/CONCATENATE.hpp>

#define XIEITE_LOOP(count, macro, initial, ...) \
	XIEITE_CONCATENATE(XIEITE_INTERNAL_LOOP_, count)(macro, initial, ...)

#define XIEITE_INTERNAL_LOOP_0(macro, initial, ...) \
	initial

#define XIEITE_INTERNAL_LOOP_1(macro, initial, ...) \
	macro(1, XIEITE_INTERNAL_LOOP_0(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_2(macro, initial, ...) \
	macro(2, XIEITE_INTERNAL_LOOP_1(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_3(macro, initial, ...) \
	macro(3, XIEITE_INTERNAL_LOOP_2(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_4(macro, initial, ...) \
	macro(4, XIEITE_INTERNAL_LOOP_3(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_5(macro, initial, ...) \
	macro(5, XIEITE_INTERNAL_LOOP_4(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_6(macro, initial, ...) \
	macro(6, XIEITE_INTERNAL_LOOP_5(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_7(macro, initial, ...) \
	macro(7, XIEITE_INTERNAL_LOOP_6(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_8(macro, initial, ...) \
	macro(8, XIEITE_INTERNAL_LOOP_7(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_9(macro, initial, ...) \
	macro(9, XIEITE_INTERNAL_LOOP_8(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_10(macro, initial, ...) \
	macro(10, XIEITE_INTERNAL_LOOP_9(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_11(macro, initial, ...) \
	macro(11, XIEITE_INTERNAL_LOOP_10(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_12(macro, initial, ...) \
	macro(12, XIEITE_INTERNAL_LOOP_11(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_13(macro, initial, ...) \
	macro(13, XIEITE_INTERNAL_LOOP_12(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_14(macro, initial, ...) \
	macro(14, XIEITE_INTERNAL_LOOP_13(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_15(macro, initial, ...) \
	macro(15, XIEITE_INTERNAL_LOOP_14(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_16(macro, initial, ...) \
	macro(16, XIEITE_INTERNAL_LOOP_15(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_17(macro, initial, ...) \
	macro(17, XIEITE_INTERNAL_LOOP_16(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_18(macro, initial, ...) \
	macro(18, XIEITE_INTERNAL_LOOP_17(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_19(macro, initial, ...) \
	macro(19, XIEITE_INTERNAL_LOOP_18(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_20(macro, initial, ...) \
	macro(20, XIEITE_INTERNAL_LOOP_19(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_21(macro, initial, ...) \
	macro(21, XIEITE_INTERNAL_LOOP_20(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_22(macro, initial, ...) \
	macro(22, XIEITE_INTERNAL_LOOP_21(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_23(macro, initial, ...) \
	macro(23, XIEITE_INTERNAL_LOOP_22(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_24(macro, initial, ...) \
	macro(24, XIEITE_INTERNAL_LOOP_23(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_25(macro, initial, ...) \
	macro(25, XIEITE_INTERNAL_LOOP_24(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_26(macro, initial, ...) \
	macro(26, XIEITE_INTERNAL_LOOP_25(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_27(macro, initial, ...) \
	macro(27, XIEITE_INTERNAL_LOOP_26(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_28(macro, initial, ...) \
	macro(28, XIEITE_INTERNAL_LOOP_27(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_29(macro, initial, ...) \
	macro(29, XIEITE_INTERNAL_LOOP_28(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_30(macro, initial, ...) \
	macro(30, XIEITE_INTERNAL_LOOP_29(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_31(macro, initial, ...) \
	macro(31, XIEITE_INTERNAL_LOOP_30(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_32(macro, initial, ...) \
	macro(32, XIEITE_INTERNAL_LOOP_31(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_33(macro, initial, ...) \
	macro(33, XIEITE_INTERNAL_LOOP_32(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_34(macro, initial, ...) \
	macro(34, XIEITE_INTERNAL_LOOP_33(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_35(macro, initial, ...) \
	macro(35, XIEITE_INTERNAL_LOOP_34(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_36(macro, initial, ...) \
	macro(36, XIEITE_INTERNAL_LOOP_35(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_37(macro, initial, ...) \
	macro(37, XIEITE_INTERNAL_LOOP_36(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_38(macro, initial, ...) \
	macro(38, XIEITE_INTERNAL_LOOP_37(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_39(macro, initial, ...) \
	macro(39, XIEITE_INTERNAL_LOOP_38(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_40(macro, initial, ...) \
	macro(40, XIEITE_INTERNAL_LOOP_39(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_41(macro, initial, ...) \
	macro(41, XIEITE_INTERNAL_LOOP_40(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_42(macro, initial, ...) \
	macro(42, XIEITE_INTERNAL_LOOP_41(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_43(macro, initial, ...) \
	macro(43, XIEITE_INTERNAL_LOOP_42(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_44(macro, initial, ...) \
	macro(44, XIEITE_INTERNAL_LOOP_43(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_45(macro, initial, ...) \
	macro(45, XIEITE_INTERNAL_LOOP_44(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_46(macro, initial, ...) \
	macro(46, XIEITE_INTERNAL_LOOP_45(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_47(macro, initial, ...) \
	macro(47, XIEITE_INTERNAL_LOOP_46(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_48(macro, initial, ...) \
	macro(48, XIEITE_INTERNAL_LOOP_47(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_49(macro, initial, ...) \
	macro(49, XIEITE_INTERNAL_LOOP_48(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_50(macro, initial, ...) \
	macro(50, XIEITE_INTERNAL_LOOP_49(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_51(macro, initial, ...) \
	macro(51, XIEITE_INTERNAL_LOOP_50(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_52(macro, initial, ...) \
	macro(52, XIEITE_INTERNAL_LOOP_51(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_53(macro, initial, ...) \
	macro(53, XIEITE_INTERNAL_LOOP_52(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_54(macro, initial, ...) \
	macro(54, XIEITE_INTERNAL_LOOP_53(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_55(macro, initial, ...) \
	macro(55, XIEITE_INTERNAL_LOOP_54(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_56(macro, initial, ...) \
	macro(56, XIEITE_INTERNAL_LOOP_55(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_57(macro, initial, ...) \
	macro(57, XIEITE_INTERNAL_LOOP_56(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_58(macro, initial, ...) \
	macro(58, XIEITE_INTERNAL_LOOP_57(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_59(macro, initial, ...) \
	macro(59, XIEITE_INTERNAL_LOOP_58(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_60(macro, initial, ...) \
	macro(60, XIEITE_INTERNAL_LOOP_59(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_61(macro, initial, ...) \
	macro(61, XIEITE_INTERNAL_LOOP_60(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_62(macro, initial, ...) \
	macro(62, XIEITE_INTERNAL_LOOP_61(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_63(macro, initial, ...) \
	macro(63, XIEITE_INTERNAL_LOOP_62(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_64(macro, initial, ...) \
	macro(64, XIEITE_INTERNAL_LOOP_63(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_65(macro, initial, ...) \
	macro(65, XIEITE_INTERNAL_LOOP_64(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_66(macro, initial, ...) \
	macro(66, XIEITE_INTERNAL_LOOP_65(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_67(macro, initial, ...) \
	macro(67, XIEITE_INTERNAL_LOOP_66(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_68(macro, initial, ...) \
	macro(68, XIEITE_INTERNAL_LOOP_67(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_69(macro, initial, ...) \
	macro(69, XIEITE_INTERNAL_LOOP_68(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_70(macro, initial, ...) \
	macro(70, XIEITE_INTERNAL_LOOP_69(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_71(macro, initial, ...) \
	macro(71, XIEITE_INTERNAL_LOOP_70(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_72(macro, initial, ...) \
	macro(72, XIEITE_INTERNAL_LOOP_71(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_73(macro, initial, ...) \
	macro(73, XIEITE_INTERNAL_LOOP_72(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_74(macro, initial, ...) \
	macro(74, XIEITE_INTERNAL_LOOP_73(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_75(macro, initial, ...) \
	macro(75, XIEITE_INTERNAL_LOOP_74(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_76(macro, initial, ...) \
	macro(76, XIEITE_INTERNAL_LOOP_75(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_77(macro, initial, ...) \
	macro(77, XIEITE_INTERNAL_LOOP_76(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_78(macro, initial, ...) \
	macro(78, XIEITE_INTERNAL_LOOP_77(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_79(macro, initial, ...) \
	macro(79, XIEITE_INTERNAL_LOOP_78(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_80(macro, initial, ...) \
	macro(80, XIEITE_INTERNAL_LOOP_79(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_81(macro, initial, ...) \
	macro(81, XIEITE_INTERNAL_LOOP_80(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_82(macro, initial, ...) \
	macro(82, XIEITE_INTERNAL_LOOP_81(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_83(macro, initial, ...) \
	macro(83, XIEITE_INTERNAL_LOOP_82(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_84(macro, initial, ...) \
	macro(84, XIEITE_INTERNAL_LOOP_83(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_85(macro, initial, ...) \
	macro(85, XIEITE_INTERNAL_LOOP_84(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_86(macro, initial, ...) \
	macro(86, XIEITE_INTERNAL_LOOP_85(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_87(macro, initial, ...) \
	macro(87, XIEITE_INTERNAL_LOOP_86(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_88(macro, initial, ...) \
	macro(88, XIEITE_INTERNAL_LOOP_87(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_89(macro, initial, ...) \
	macro(89, XIEITE_INTERNAL_LOOP_88(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_90(macro, initial, ...) \
	macro(90, XIEITE_INTERNAL_LOOP_89(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_91(macro, initial, ...) \
	macro(91, XIEITE_INTERNAL_LOOP_90(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_92(macro, initial, ...) \
	macro(92, XIEITE_INTERNAL_LOOP_91(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_93(macro, initial, ...) \
	macro(93, XIEITE_INTERNAL_LOOP_92(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_94(macro, initial, ...) \
	macro(94, XIEITE_INTERNAL_LOOP_93(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_95(macro, initial, ...) \
	macro(95, XIEITE_INTERNAL_LOOP_94(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_96(macro, initial, ...) \
	macro(96, XIEITE_INTERNAL_LOOP_95(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_97(macro, initial, ...) \
	macro(97, XIEITE_INTERNAL_LOOP_96(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_98(macro, initial, ...) \
	macro(98, XIEITE_INTERNAL_LOOP_97(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_99(macro, initial, ...) \
	macro(99, XIEITE_INTERNAL_LOOP_98(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_100(macro, initial, ...) \
	macro(100, XIEITE_INTERNAL_LOOP_99(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_101(macro, initial, ...) \
	macro(101, XIEITE_INTERNAL_LOOP_100(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_102(macro, initial, ...) \
	macro(102, XIEITE_INTERNAL_LOOP_101(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_103(macro, initial, ...) \
	macro(103, XIEITE_INTERNAL_LOOP_102(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_104(macro, initial, ...) \
	macro(104, XIEITE_INTERNAL_LOOP_103(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_105(macro, initial, ...) \
	macro(105, XIEITE_INTERNAL_LOOP_104(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_106(macro, initial, ...) \
	macro(106, XIEITE_INTERNAL_LOOP_105(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_107(macro, initial, ...) \
	macro(107, XIEITE_INTERNAL_LOOP_106(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_108(macro, initial, ...) \
	macro(108, XIEITE_INTERNAL_LOOP_107(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_109(macro, initial, ...) \
	macro(109, XIEITE_INTERNAL_LOOP_108(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_110(macro, initial, ...) \
	macro(110, XIEITE_INTERNAL_LOOP_109(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_111(macro, initial, ...) \
	macro(111, XIEITE_INTERNAL_LOOP_110(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_112(macro, initial, ...) \
	macro(112, XIEITE_INTERNAL_LOOP_111(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_113(macro, initial, ...) \
	macro(113, XIEITE_INTERNAL_LOOP_112(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_114(macro, initial, ...) \
	macro(114, XIEITE_INTERNAL_LOOP_113(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_115(macro, initial, ...) \
	macro(115, XIEITE_INTERNAL_LOOP_114(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_116(macro, initial, ...) \
	macro(116, XIEITE_INTERNAL_LOOP_115(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_117(macro, initial, ...) \
	macro(117, XIEITE_INTERNAL_LOOP_116(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_118(macro, initial, ...) \
	macro(118, XIEITE_INTERNAL_LOOP_117(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_119(macro, initial, ...) \
	macro(119, XIEITE_INTERNAL_LOOP_118(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_120(macro, initial, ...) \
	macro(120, XIEITE_INTERNAL_LOOP_119(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_121(macro, initial, ...) \
	macro(121, XIEITE_INTERNAL_LOOP_120(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_122(macro, initial, ...) \
	macro(122, XIEITE_INTERNAL_LOOP_121(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_123(macro, initial, ...) \
	macro(123, XIEITE_INTERNAL_LOOP_122(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_124(macro, initial, ...) \
	macro(124, XIEITE_INTERNAL_LOOP_123(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_125(macro, initial, ...) \
	macro(125, XIEITE_INTERNAL_LOOP_124(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_126(macro, initial, ...) \
	macro(126, XIEITE_INTERNAL_LOOP_125(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_127(macro, initial, ...) \
	macro(127, XIEITE_INTERNAL_LOOP_126(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_128(macro, initial, ...) \
	macro(128, XIEITE_INTERNAL_LOOP_127(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_129(macro, initial, ...) \
	macro(129, XIEITE_INTERNAL_LOOP_128(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_130(macro, initial, ...) \
	macro(130, XIEITE_INTERNAL_LOOP_129(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_131(macro, initial, ...) \
	macro(131, XIEITE_INTERNAL_LOOP_130(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_132(macro, initial, ...) \
	macro(132, XIEITE_INTERNAL_LOOP_131(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_133(macro, initial, ...) \
	macro(133, XIEITE_INTERNAL_LOOP_132(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_134(macro, initial, ...) \
	macro(134, XIEITE_INTERNAL_LOOP_133(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_135(macro, initial, ...) \
	macro(135, XIEITE_INTERNAL_LOOP_134(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_136(macro, initial, ...) \
	macro(136, XIEITE_INTERNAL_LOOP_135(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_137(macro, initial, ...) \
	macro(137, XIEITE_INTERNAL_LOOP_136(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_138(macro, initial, ...) \
	macro(138, XIEITE_INTERNAL_LOOP_137(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_139(macro, initial, ...) \
	macro(139, XIEITE_INTERNAL_LOOP_138(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_140(macro, initial, ...) \
	macro(140, XIEITE_INTERNAL_LOOP_139(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_141(macro, initial, ...) \
	macro(141, XIEITE_INTERNAL_LOOP_140(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_142(macro, initial, ...) \
	macro(142, XIEITE_INTERNAL_LOOP_141(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_143(macro, initial, ...) \
	macro(143, XIEITE_INTERNAL_LOOP_142(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_144(macro, initial, ...) \
	macro(144, XIEITE_INTERNAL_LOOP_143(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_145(macro, initial, ...) \
	macro(145, XIEITE_INTERNAL_LOOP_144(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_146(macro, initial, ...) \
	macro(146, XIEITE_INTERNAL_LOOP_145(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_147(macro, initial, ...) \
	macro(147, XIEITE_INTERNAL_LOOP_146(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_148(macro, initial, ...) \
	macro(148, XIEITE_INTERNAL_LOOP_147(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_149(macro, initial, ...) \
	macro(149, XIEITE_INTERNAL_LOOP_148(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_150(macro, initial, ...) \
	macro(150, XIEITE_INTERNAL_LOOP_149(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_151(macro, initial, ...) \
	macro(151, XIEITE_INTERNAL_LOOP_150(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_152(macro, initial, ...) \
	macro(152, XIEITE_INTERNAL_LOOP_151(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_153(macro, initial, ...) \
	macro(153, XIEITE_INTERNAL_LOOP_152(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_154(macro, initial, ...) \
	macro(154, XIEITE_INTERNAL_LOOP_153(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_155(macro, initial, ...) \
	macro(155, XIEITE_INTERNAL_LOOP_154(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_156(macro, initial, ...) \
	macro(156, XIEITE_INTERNAL_LOOP_155(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_157(macro, initial, ...) \
	macro(157, XIEITE_INTERNAL_LOOP_156(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_158(macro, initial, ...) \
	macro(158, XIEITE_INTERNAL_LOOP_157(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_159(macro, initial, ...) \
	macro(159, XIEITE_INTERNAL_LOOP_158(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_160(macro, initial, ...) \
	macro(160, XIEITE_INTERNAL_LOOP_159(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_161(macro, initial, ...) \
	macro(161, XIEITE_INTERNAL_LOOP_160(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_162(macro, initial, ...) \
	macro(162, XIEITE_INTERNAL_LOOP_161(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_163(macro, initial, ...) \
	macro(163, XIEITE_INTERNAL_LOOP_162(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_164(macro, initial, ...) \
	macro(164, XIEITE_INTERNAL_LOOP_163(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_165(macro, initial, ...) \
	macro(165, XIEITE_INTERNAL_LOOP_164(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_166(macro, initial, ...) \
	macro(166, XIEITE_INTERNAL_LOOP_165(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_167(macro, initial, ...) \
	macro(167, XIEITE_INTERNAL_LOOP_166(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_168(macro, initial, ...) \
	macro(168, XIEITE_INTERNAL_LOOP_167(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_169(macro, initial, ...) \
	macro(169, XIEITE_INTERNAL_LOOP_168(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_170(macro, initial, ...) \
	macro(170, XIEITE_INTERNAL_LOOP_169(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_171(macro, initial, ...) \
	macro(171, XIEITE_INTERNAL_LOOP_170(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_172(macro, initial, ...) \
	macro(172, XIEITE_INTERNAL_LOOP_171(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_173(macro, initial, ...) \
	macro(173, XIEITE_INTERNAL_LOOP_172(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_174(macro, initial, ...) \
	macro(174, XIEITE_INTERNAL_LOOP_173(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_175(macro, initial, ...) \
	macro(175, XIEITE_INTERNAL_LOOP_174(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_176(macro, initial, ...) \
	macro(176, XIEITE_INTERNAL_LOOP_175(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_177(macro, initial, ...) \
	macro(177, XIEITE_INTERNAL_LOOP_176(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_178(macro, initial, ...) \
	macro(178, XIEITE_INTERNAL_LOOP_177(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_179(macro, initial, ...) \
	macro(179, XIEITE_INTERNAL_LOOP_178(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_180(macro, initial, ...) \
	macro(180, XIEITE_INTERNAL_LOOP_179(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_181(macro, initial, ...) \
	macro(181, XIEITE_INTERNAL_LOOP_180(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_182(macro, initial, ...) \
	macro(182, XIEITE_INTERNAL_LOOP_181(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_183(macro, initial, ...) \
	macro(183, XIEITE_INTERNAL_LOOP_182(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_184(macro, initial, ...) \
	macro(184, XIEITE_INTERNAL_LOOP_183(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_185(macro, initial, ...) \
	macro(185, XIEITE_INTERNAL_LOOP_184(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_186(macro, initial, ...) \
	macro(186, XIEITE_INTERNAL_LOOP_185(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_187(macro, initial, ...) \
	macro(187, XIEITE_INTERNAL_LOOP_186(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_188(macro, initial, ...) \
	macro(188, XIEITE_INTERNAL_LOOP_187(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_189(macro, initial, ...) \
	macro(189, XIEITE_INTERNAL_LOOP_188(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_190(macro, initial, ...) \
	macro(190, XIEITE_INTERNAL_LOOP_189(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_191(macro, initial, ...) \
	macro(191, XIEITE_INTERNAL_LOOP_190(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_192(macro, initial, ...) \
	macro(192, XIEITE_INTERNAL_LOOP_191(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_193(macro, initial, ...) \
	macro(193, XIEITE_INTERNAL_LOOP_192(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_194(macro, initial, ...) \
	macro(194, XIEITE_INTERNAL_LOOP_193(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_195(macro, initial, ...) \
	macro(195, XIEITE_INTERNAL_LOOP_194(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_196(macro, initial, ...) \
	macro(196, XIEITE_INTERNAL_LOOP_195(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_197(macro, initial, ...) \
	macro(197, XIEITE_INTERNAL_LOOP_196(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_198(macro, initial, ...) \
	macro(198, XIEITE_INTERNAL_LOOP_197(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_199(macro, initial, ...) \
	macro(199, XIEITE_INTERNAL_LOOP_198(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_200(macro, initial, ...) \
	macro(200, XIEITE_INTERNAL_LOOP_199(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_201(macro, initial, ...) \
	macro(201, XIEITE_INTERNAL_LOOP_200(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_202(macro, initial, ...) \
	macro(202, XIEITE_INTERNAL_LOOP_201(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_203(macro, initial, ...) \
	macro(203, XIEITE_INTERNAL_LOOP_202(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_204(macro, initial, ...) \
	macro(204, XIEITE_INTERNAL_LOOP_203(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_205(macro, initial, ...) \
	macro(205, XIEITE_INTERNAL_LOOP_204(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_206(macro, initial, ...) \
	macro(206, XIEITE_INTERNAL_LOOP_205(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_207(macro, initial, ...) \
	macro(207, XIEITE_INTERNAL_LOOP_206(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_208(macro, initial, ...) \
	macro(208, XIEITE_INTERNAL_LOOP_207(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_209(macro, initial, ...) \
	macro(209, XIEITE_INTERNAL_LOOP_208(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_210(macro, initial, ...) \
	macro(210, XIEITE_INTERNAL_LOOP_209(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_211(macro, initial, ...) \
	macro(211, XIEITE_INTERNAL_LOOP_210(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_212(macro, initial, ...) \
	macro(212, XIEITE_INTERNAL_LOOP_211(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_213(macro, initial, ...) \
	macro(213, XIEITE_INTERNAL_LOOP_212(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_214(macro, initial, ...) \
	macro(214, XIEITE_INTERNAL_LOOP_213(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_215(macro, initial, ...) \
	macro(215, XIEITE_INTERNAL_LOOP_214(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_216(macro, initial, ...) \
	macro(216, XIEITE_INTERNAL_LOOP_215(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_217(macro, initial, ...) \
	macro(217, XIEITE_INTERNAL_LOOP_216(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_218(macro, initial, ...) \
	macro(218, XIEITE_INTERNAL_LOOP_217(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_219(macro, initial, ...) \
	macro(219, XIEITE_INTERNAL_LOOP_218(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_220(macro, initial, ...) \
	macro(220, XIEITE_INTERNAL_LOOP_219(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_221(macro, initial, ...) \
	macro(221, XIEITE_INTERNAL_LOOP_220(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_222(macro, initial, ...) \
	macro(222, XIEITE_INTERNAL_LOOP_221(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_223(macro, initial, ...) \
	macro(223, XIEITE_INTERNAL_LOOP_222(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_224(macro, initial, ...) \
	macro(224, XIEITE_INTERNAL_LOOP_223(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_225(macro, initial, ...) \
	macro(225, XIEITE_INTERNAL_LOOP_224(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_226(macro, initial, ...) \
	macro(226, XIEITE_INTERNAL_LOOP_225(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_227(macro, initial, ...) \
	macro(227, XIEITE_INTERNAL_LOOP_226(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_228(macro, initial, ...) \
	macro(228, XIEITE_INTERNAL_LOOP_227(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_229(macro, initial, ...) \
	macro(229, XIEITE_INTERNAL_LOOP_228(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_230(macro, initial, ...) \
	macro(230, XIEITE_INTERNAL_LOOP_229(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_231(macro, initial, ...) \
	macro(231, XIEITE_INTERNAL_LOOP_230(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_232(macro, initial, ...) \
	macro(232, XIEITE_INTERNAL_LOOP_231(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_233(macro, initial, ...) \
	macro(233, XIEITE_INTERNAL_LOOP_232(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_234(macro, initial, ...) \
	macro(234, XIEITE_INTERNAL_LOOP_233(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_235(macro, initial, ...) \
	macro(235, XIEITE_INTERNAL_LOOP_234(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_236(macro, initial, ...) \
	macro(236, XIEITE_INTERNAL_LOOP_235(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_237(macro, initial, ...) \
	macro(237, XIEITE_INTERNAL_LOOP_236(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_238(macro, initial, ...) \
	macro(238, XIEITE_INTERNAL_LOOP_237(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_239(macro, initial, ...) \
	macro(239, XIEITE_INTERNAL_LOOP_238(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_240(macro, initial, ...) \
	macro(240, XIEITE_INTERNAL_LOOP_239(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_241(macro, initial, ...) \
	macro(241, XIEITE_INTERNAL_LOOP_240(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_242(macro, initial, ...) \
	macro(242, XIEITE_INTERNAL_LOOP_241(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_243(macro, initial, ...) \
	macro(243, XIEITE_INTERNAL_LOOP_242(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_244(macro, initial, ...) \
	macro(244, XIEITE_INTERNAL_LOOP_243(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_245(macro, initial, ...) \
	macro(245, XIEITE_INTERNAL_LOOP_244(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_246(macro, initial, ...) \
	macro(246, XIEITE_INTERNAL_LOOP_245(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_247(macro, initial, ...) \
	macro(247, XIEITE_INTERNAL_LOOP_246(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_248(macro, initial, ...) \
	macro(248, XIEITE_INTERNAL_LOOP_247(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_249(macro, initial, ...) \
	macro(249, XIEITE_INTERNAL_LOOP_248(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_250(macro, initial, ...) \
	macro(250, XIEITE_INTERNAL_LOOP_249(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_251(macro, initial, ...) \
	macro(251, XIEITE_INTERNAL_LOOP_250(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_252(macro, initial, ...) \
	macro(252, XIEITE_INTERNAL_LOOP_251(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_253(macro, initial, ...) \
	macro(253, XIEITE_INTERNAL_LOOP_252(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_254(macro, initial, ...) \
	macro(254, XIEITE_INTERNAL_LOOP_253(macro, initial, __VA_ARGS__), __VA_ARGS__)

#define XIEITE_INTERNAL_LOOP_255(macro, initial, ...) \
	macro(255, XIEITE_INTERNAL_LOOP_254(macro, initial, __VA_ARGS__), __VA_ARGS__)

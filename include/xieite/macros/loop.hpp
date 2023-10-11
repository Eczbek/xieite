#ifndef XIEITE_HEADER_MACROS_LOOP
#	define XIEITE_HEADER_MACROS_LOOP

#	include "../macros/concatenate.hpp"

#	define XIEITE_LOOP(iterations, callback, initial, ...) XIEITE_CONCATENATE(XIEITE_LOOP_INTERNAL_, iterations)(callback, initial, __VA_ARGS__)

#	define XIEITE_LOOP_INTERNAL_0(callback, accumulator, ...) accumulator
#	define XIEITE_LOOP_INTERNAL_1(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_0(callback, accumulator, __VA_ARGS__), 1, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_2(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_1(callback, accumulator, __VA_ARGS__), 2, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_3(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_2(callback, accumulator, __VA_ARGS__), 3, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_4(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_3(callback, accumulator, __VA_ARGS__), 4, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_5(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_4(callback, accumulator, __VA_ARGS__), 5, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_6(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_5(callback, accumulator, __VA_ARGS__), 6, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_7(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_6(callback, accumulator, __VA_ARGS__), 7, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_8(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_7(callback, accumulator, __VA_ARGS__), 8, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_9(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_8(callback, accumulator, __VA_ARGS__), 9, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_10(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_9(callback, accumulator, __VA_ARGS__), 10, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_11(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_10(callback, accumulator, __VA_ARGS__), 11, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_12(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_11(callback, accumulator, __VA_ARGS__), 12, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_13(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_12(callback, accumulator, __VA_ARGS__), 13, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_14(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_13(callback, accumulator, __VA_ARGS__), 14, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_15(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_14(callback, accumulator, __VA_ARGS__), 15, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_16(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_15(callback, accumulator, __VA_ARGS__), 16, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_17(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_16(callback, accumulator, __VA_ARGS__), 17, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_18(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_17(callback, accumulator, __VA_ARGS__), 18, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_19(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_18(callback, accumulator, __VA_ARGS__), 19, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_20(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_19(callback, accumulator, __VA_ARGS__), 20, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_21(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_20(callback, accumulator, __VA_ARGS__), 21, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_22(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_21(callback, accumulator, __VA_ARGS__), 22, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_23(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_22(callback, accumulator, __VA_ARGS__), 23, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_24(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_23(callback, accumulator, __VA_ARGS__), 24, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_25(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_24(callback, accumulator, __VA_ARGS__), 25, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_26(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_25(callback, accumulator, __VA_ARGS__), 26, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_27(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_26(callback, accumulator, __VA_ARGS__), 27, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_28(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_27(callback, accumulator, __VA_ARGS__), 28, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_29(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_28(callback, accumulator, __VA_ARGS__), 29, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_30(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_29(callback, accumulator, __VA_ARGS__), 30, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_31(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_30(callback, accumulator, __VA_ARGS__), 31, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_32(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_31(callback, accumulator, __VA_ARGS__), 32, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_33(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_32(callback, accumulator, __VA_ARGS__), 33, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_34(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_33(callback, accumulator, __VA_ARGS__), 34, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_35(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_34(callback, accumulator, __VA_ARGS__), 35, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_36(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_35(callback, accumulator, __VA_ARGS__), 36, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_37(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_36(callback, accumulator, __VA_ARGS__), 37, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_38(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_37(callback, accumulator, __VA_ARGS__), 38, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_39(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_38(callback, accumulator, __VA_ARGS__), 39, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_40(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_39(callback, accumulator, __VA_ARGS__), 40, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_41(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_40(callback, accumulator, __VA_ARGS__), 41, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_42(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_41(callback, accumulator, __VA_ARGS__), 42, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_43(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_42(callback, accumulator, __VA_ARGS__), 43, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_44(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_43(callback, accumulator, __VA_ARGS__), 44, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_45(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_44(callback, accumulator, __VA_ARGS__), 45, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_46(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_45(callback, accumulator, __VA_ARGS__), 46, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_47(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_46(callback, accumulator, __VA_ARGS__), 47, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_48(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_47(callback, accumulator, __VA_ARGS__), 48, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_49(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_48(callback, accumulator, __VA_ARGS__), 49, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_50(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_49(callback, accumulator, __VA_ARGS__), 50, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_51(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_50(callback, accumulator, __VA_ARGS__), 51, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_52(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_51(callback, accumulator, __VA_ARGS__), 52, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_53(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_52(callback, accumulator, __VA_ARGS__), 53, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_54(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_53(callback, accumulator, __VA_ARGS__), 54, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_55(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_54(callback, accumulator, __VA_ARGS__), 55, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_56(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_55(callback, accumulator, __VA_ARGS__), 56, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_57(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_56(callback, accumulator, __VA_ARGS__), 57, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_58(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_57(callback, accumulator, __VA_ARGS__), 58, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_59(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_58(callback, accumulator, __VA_ARGS__), 59, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_60(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_59(callback, accumulator, __VA_ARGS__), 60, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_61(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_60(callback, accumulator, __VA_ARGS__), 61, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_62(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_61(callback, accumulator, __VA_ARGS__), 62, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_63(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_62(callback, accumulator, __VA_ARGS__), 63, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_64(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_63(callback, accumulator, __VA_ARGS__), 64, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_65(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_64(callback, accumulator, __VA_ARGS__), 65, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_66(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_65(callback, accumulator, __VA_ARGS__), 66, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_67(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_66(callback, accumulator, __VA_ARGS__), 67, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_68(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_67(callback, accumulator, __VA_ARGS__), 68, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_69(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_68(callback, accumulator, __VA_ARGS__), 69, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_70(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_69(callback, accumulator, __VA_ARGS__), 70, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_71(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_70(callback, accumulator, __VA_ARGS__), 71, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_72(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_71(callback, accumulator, __VA_ARGS__), 72, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_73(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_72(callback, accumulator, __VA_ARGS__), 73, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_74(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_73(callback, accumulator, __VA_ARGS__), 74, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_75(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_74(callback, accumulator, __VA_ARGS__), 75, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_76(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_75(callback, accumulator, __VA_ARGS__), 76, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_77(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_76(callback, accumulator, __VA_ARGS__), 77, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_78(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_77(callback, accumulator, __VA_ARGS__), 78, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_79(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_78(callback, accumulator, __VA_ARGS__), 79, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_80(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_79(callback, accumulator, __VA_ARGS__), 80, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_81(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_80(callback, accumulator, __VA_ARGS__), 81, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_82(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_81(callback, accumulator, __VA_ARGS__), 82, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_83(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_82(callback, accumulator, __VA_ARGS__), 83, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_84(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_83(callback, accumulator, __VA_ARGS__), 84, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_85(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_84(callback, accumulator, __VA_ARGS__), 85, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_86(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_85(callback, accumulator, __VA_ARGS__), 86, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_87(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_86(callback, accumulator, __VA_ARGS__), 87, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_88(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_87(callback, accumulator, __VA_ARGS__), 88, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_89(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_88(callback, accumulator, __VA_ARGS__), 89, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_90(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_89(callback, accumulator, __VA_ARGS__), 90, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_91(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_90(callback, accumulator, __VA_ARGS__), 91, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_92(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_91(callback, accumulator, __VA_ARGS__), 92, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_93(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_92(callback, accumulator, __VA_ARGS__), 93, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_94(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_93(callback, accumulator, __VA_ARGS__), 94, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_95(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_94(callback, accumulator, __VA_ARGS__), 95, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_96(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_95(callback, accumulator, __VA_ARGS__), 96, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_97(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_96(callback, accumulator, __VA_ARGS__), 97, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_98(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_97(callback, accumulator, __VA_ARGS__), 98, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_99(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_98(callback, accumulator, __VA_ARGS__), 99, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_100(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_99(callback, accumulator, __VA_ARGS__), 100, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_101(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_100(callback, accumulator, __VA_ARGS__), 101, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_102(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_101(callback, accumulator, __VA_ARGS__), 102, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_103(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_102(callback, accumulator, __VA_ARGS__), 103, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_104(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_103(callback, accumulator, __VA_ARGS__), 104, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_105(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_104(callback, accumulator, __VA_ARGS__), 105, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_106(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_105(callback, accumulator, __VA_ARGS__), 106, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_107(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_106(callback, accumulator, __VA_ARGS__), 107, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_108(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_107(callback, accumulator, __VA_ARGS__), 108, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_109(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_108(callback, accumulator, __VA_ARGS__), 109, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_110(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_109(callback, accumulator, __VA_ARGS__), 110, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_111(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_110(callback, accumulator, __VA_ARGS__), 111, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_112(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_111(callback, accumulator, __VA_ARGS__), 112, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_113(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_112(callback, accumulator, __VA_ARGS__), 113, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_114(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_113(callback, accumulator, __VA_ARGS__), 114, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_115(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_114(callback, accumulator, __VA_ARGS__), 115, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_116(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_115(callback, accumulator, __VA_ARGS__), 116, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_117(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_116(callback, accumulator, __VA_ARGS__), 117, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_118(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_117(callback, accumulator, __VA_ARGS__), 118, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_119(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_118(callback, accumulator, __VA_ARGS__), 119, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_120(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_119(callback, accumulator, __VA_ARGS__), 120, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_121(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_120(callback, accumulator, __VA_ARGS__), 121, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_122(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_121(callback, accumulator, __VA_ARGS__), 122, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_123(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_122(callback, accumulator, __VA_ARGS__), 123, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_124(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_123(callback, accumulator, __VA_ARGS__), 124, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_125(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_124(callback, accumulator, __VA_ARGS__), 125, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_126(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_125(callback, accumulator, __VA_ARGS__), 126, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_127(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_126(callback, accumulator, __VA_ARGS__), 127, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_128(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_127(callback, accumulator, __VA_ARGS__), 128, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_129(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_128(callback, accumulator, __VA_ARGS__), 129, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_130(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_129(callback, accumulator, __VA_ARGS__), 130, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_131(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_130(callback, accumulator, __VA_ARGS__), 131, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_132(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_131(callback, accumulator, __VA_ARGS__), 132, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_133(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_132(callback, accumulator, __VA_ARGS__), 133, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_134(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_133(callback, accumulator, __VA_ARGS__), 134, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_135(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_134(callback, accumulator, __VA_ARGS__), 135, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_136(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_135(callback, accumulator, __VA_ARGS__), 136, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_137(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_136(callback, accumulator, __VA_ARGS__), 137, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_138(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_137(callback, accumulator, __VA_ARGS__), 138, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_139(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_138(callback, accumulator, __VA_ARGS__), 139, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_140(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_139(callback, accumulator, __VA_ARGS__), 140, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_141(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_140(callback, accumulator, __VA_ARGS__), 141, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_142(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_141(callback, accumulator, __VA_ARGS__), 142, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_143(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_142(callback, accumulator, __VA_ARGS__), 143, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_144(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_143(callback, accumulator, __VA_ARGS__), 144, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_145(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_144(callback, accumulator, __VA_ARGS__), 145, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_146(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_145(callback, accumulator, __VA_ARGS__), 146, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_147(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_146(callback, accumulator, __VA_ARGS__), 147, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_148(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_147(callback, accumulator, __VA_ARGS__), 148, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_149(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_148(callback, accumulator, __VA_ARGS__), 149, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_150(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_149(callback, accumulator, __VA_ARGS__), 150, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_151(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_150(callback, accumulator, __VA_ARGS__), 151, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_152(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_151(callback, accumulator, __VA_ARGS__), 152, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_153(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_152(callback, accumulator, __VA_ARGS__), 153, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_154(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_153(callback, accumulator, __VA_ARGS__), 154, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_155(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_154(callback, accumulator, __VA_ARGS__), 155, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_156(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_155(callback, accumulator, __VA_ARGS__), 156, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_157(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_156(callback, accumulator, __VA_ARGS__), 157, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_158(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_157(callback, accumulator, __VA_ARGS__), 158, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_159(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_158(callback, accumulator, __VA_ARGS__), 159, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_160(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_159(callback, accumulator, __VA_ARGS__), 160, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_161(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_160(callback, accumulator, __VA_ARGS__), 161, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_162(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_161(callback, accumulator, __VA_ARGS__), 162, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_163(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_162(callback, accumulator, __VA_ARGS__), 163, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_164(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_163(callback, accumulator, __VA_ARGS__), 164, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_165(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_164(callback, accumulator, __VA_ARGS__), 165, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_166(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_165(callback, accumulator, __VA_ARGS__), 166, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_167(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_166(callback, accumulator, __VA_ARGS__), 167, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_168(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_167(callback, accumulator, __VA_ARGS__), 168, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_169(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_168(callback, accumulator, __VA_ARGS__), 169, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_170(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_169(callback, accumulator, __VA_ARGS__), 170, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_171(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_170(callback, accumulator, __VA_ARGS__), 171, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_172(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_171(callback, accumulator, __VA_ARGS__), 172, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_173(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_172(callback, accumulator, __VA_ARGS__), 173, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_174(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_173(callback, accumulator, __VA_ARGS__), 174, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_175(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_174(callback, accumulator, __VA_ARGS__), 175, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_176(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_175(callback, accumulator, __VA_ARGS__), 176, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_177(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_176(callback, accumulator, __VA_ARGS__), 177, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_178(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_177(callback, accumulator, __VA_ARGS__), 178, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_179(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_178(callback, accumulator, __VA_ARGS__), 179, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_180(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_179(callback, accumulator, __VA_ARGS__), 180, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_181(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_180(callback, accumulator, __VA_ARGS__), 181, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_182(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_181(callback, accumulator, __VA_ARGS__), 182, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_183(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_182(callback, accumulator, __VA_ARGS__), 183, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_184(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_183(callback, accumulator, __VA_ARGS__), 184, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_185(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_184(callback, accumulator, __VA_ARGS__), 185, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_186(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_185(callback, accumulator, __VA_ARGS__), 186, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_187(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_186(callback, accumulator, __VA_ARGS__), 187, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_188(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_187(callback, accumulator, __VA_ARGS__), 188, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_189(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_188(callback, accumulator, __VA_ARGS__), 189, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_190(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_189(callback, accumulator, __VA_ARGS__), 190, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_191(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_190(callback, accumulator, __VA_ARGS__), 191, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_192(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_191(callback, accumulator, __VA_ARGS__), 192, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_193(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_192(callback, accumulator, __VA_ARGS__), 193, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_194(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_193(callback, accumulator, __VA_ARGS__), 194, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_195(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_194(callback, accumulator, __VA_ARGS__), 195, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_196(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_195(callback, accumulator, __VA_ARGS__), 196, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_197(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_196(callback, accumulator, __VA_ARGS__), 197, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_198(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_197(callback, accumulator, __VA_ARGS__), 198, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_199(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_198(callback, accumulator, __VA_ARGS__), 199, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_200(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_199(callback, accumulator, __VA_ARGS__), 200, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_201(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_200(callback, accumulator, __VA_ARGS__), 201, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_202(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_201(callback, accumulator, __VA_ARGS__), 202, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_203(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_202(callback, accumulator, __VA_ARGS__), 203, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_204(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_203(callback, accumulator, __VA_ARGS__), 204, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_205(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_204(callback, accumulator, __VA_ARGS__), 205, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_206(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_205(callback, accumulator, __VA_ARGS__), 206, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_207(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_206(callback, accumulator, __VA_ARGS__), 207, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_208(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_207(callback, accumulator, __VA_ARGS__), 208, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_209(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_208(callback, accumulator, __VA_ARGS__), 209, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_210(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_209(callback, accumulator, __VA_ARGS__), 210, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_211(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_210(callback, accumulator, __VA_ARGS__), 211, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_212(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_211(callback, accumulator, __VA_ARGS__), 212, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_213(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_212(callback, accumulator, __VA_ARGS__), 213, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_214(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_213(callback, accumulator, __VA_ARGS__), 214, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_215(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_214(callback, accumulator, __VA_ARGS__), 215, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_216(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_215(callback, accumulator, __VA_ARGS__), 216, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_217(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_216(callback, accumulator, __VA_ARGS__), 217, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_218(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_217(callback, accumulator, __VA_ARGS__), 218, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_219(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_218(callback, accumulator, __VA_ARGS__), 219, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_220(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_219(callback, accumulator, __VA_ARGS__), 220, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_221(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_220(callback, accumulator, __VA_ARGS__), 221, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_222(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_221(callback, accumulator, __VA_ARGS__), 222, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_223(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_222(callback, accumulator, __VA_ARGS__), 223, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_224(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_223(callback, accumulator, __VA_ARGS__), 224, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_225(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_224(callback, accumulator, __VA_ARGS__), 225, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_226(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_225(callback, accumulator, __VA_ARGS__), 226, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_227(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_226(callback, accumulator, __VA_ARGS__), 227, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_228(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_227(callback, accumulator, __VA_ARGS__), 228, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_229(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_228(callback, accumulator, __VA_ARGS__), 229, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_230(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_229(callback, accumulator, __VA_ARGS__), 230, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_231(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_230(callback, accumulator, __VA_ARGS__), 231, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_232(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_231(callback, accumulator, __VA_ARGS__), 232, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_233(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_232(callback, accumulator, __VA_ARGS__), 233, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_234(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_233(callback, accumulator, __VA_ARGS__), 234, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_235(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_234(callback, accumulator, __VA_ARGS__), 235, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_236(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_235(callback, accumulator, __VA_ARGS__), 236, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_237(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_236(callback, accumulator, __VA_ARGS__), 237, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_238(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_237(callback, accumulator, __VA_ARGS__), 238, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_239(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_238(callback, accumulator, __VA_ARGS__), 239, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_240(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_239(callback, accumulator, __VA_ARGS__), 240, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_241(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_240(callback, accumulator, __VA_ARGS__), 241, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_242(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_241(callback, accumulator, __VA_ARGS__), 242, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_243(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_242(callback, accumulator, __VA_ARGS__), 243, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_244(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_243(callback, accumulator, __VA_ARGS__), 244, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_245(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_244(callback, accumulator, __VA_ARGS__), 245, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_246(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_245(callback, accumulator, __VA_ARGS__), 246, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_247(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_246(callback, accumulator, __VA_ARGS__), 247, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_248(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_247(callback, accumulator, __VA_ARGS__), 248, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_249(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_248(callback, accumulator, __VA_ARGS__), 249, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_250(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_249(callback, accumulator, __VA_ARGS__), 250, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_251(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_250(callback, accumulator, __VA_ARGS__), 251, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_252(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_251(callback, accumulator, __VA_ARGS__), 252, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_253(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_252(callback, accumulator, __VA_ARGS__), 253, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_254(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_253(callback, accumulator, __VA_ARGS__), 254, __VA_ARGS__)
#	define XIEITE_LOOP_INTERNAL_255(callback, accumulator, ...) callback(XIEITE_LOOP_INTERNAL_254(callback, accumulator, __VA_ARGS__), 255, __VA_ARGS__)

#endif
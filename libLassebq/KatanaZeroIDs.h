#pragma once

// What addresses to use?
#define KZ_105_GOG

// Please please please, keep address format like this:
// #define Something_Addr (0xSOMETHINGu)

#ifdef KZ_105_STEAM /* Katana Zero v1.0.5 Windows Steam */
#define RFunctionTable_Addr    (0x01CFCB54u)
#define RFunctionTableL_Addr   (0x01CFCB58u)
#define FREE_RValue__Pre_Addr  (0x00001070u)
#define YYSetString_Addr       (0x014DB840u)
#define YYCreateString_Addr    (0x014DAE30u)
#define YYStrDup_Addr          (0x014DB8C0u)
#define YYFree_Addr            (0x0151FFA0u)
#define ARRAY_LVAL_RV_Addr     (0x014DBF50u)
#define Variable_Addr          (0x01A37CF8u)
#define GMLScript_Addr         (0x01A3C6F4u)
#define Run_Room_Addr          (0x01CF88D8u)
#define Global_YYObject_Addr   (0x01ADE1D8u)
#define Object_Hash_Addr       (0x01AE769Cu)
#define GetCtxStackTop_Addr    (0x014D5A80u)
#define DeterminePotRoot_Addr  (0x014BF440u)
#define GetEvRecursive_Addr    (0x01522300u)
#define InsertEvent_Addr       (0x015224A0u)
#define YYSTraceStart_Addr     (0x01AD8B90u)
#define BuiltinVars_Addr       (0x01ADE300u)
#define YYError_Addr           (0x014DB040u)
#define ConstNumb_Addr         (0x01D09634u)
#define ConstNames_Addr        (0x01D0962Cu)
#define ConstValues_Addr       (0x01D09630u)
#define MenuVersionString_Addr (0x01233C16u)
#endif

#ifdef KZ_105_GOG /* Katana ZERO v1.0.5 Windows GOG */
#define RFunctionTable_Addr    (0x01CFBAE4u)
#define RFunctionTableL_Addr   (0x01CFBAE8u)
#define FREE_RValue__Pre_Addr  (0x00001070u)
#define YYSetString_Addr       (0x014DA4C0u)
#define YYCreateString_Addr    (0x014D9AB0u)
#define YYStrDup_Addr          (0x014DA540u)
#define YYFree_Addr            (0x0151EC20u)
#define ARRAY_LVAL_RV_Addr     (0x014DABD0u)
#define Variable_Addr          (0x01A36CC0u)
#define GMLScript_Addr         (0x01A3B680u)
#define Run_Room_Addr          (0x01CF7868u)
#define Global_YYObject_Addr   (0x01ADD168u)
#define Object_Hash_Addr       (0x01AE662Cu)
#define GetCtxStackTop_Addr    (0x014D4700u)
#define DeterminePotRoot_Addr  (0x014BE0B0u)
#define GetEvRecursive_Addr    (0x01520F80u)
#define InsertEvent_Addr       (0x01521120u)
#define YYSTraceStart_Addr     (0x01AD7B20u)
#define BuiltinVars_Addr       (0x01ADD290u)
#define YYError_Addr           (0x014D9CC0u)
#define ConstNumb_Addr         (0x01D085C4u)
#define ConstNames_Addr        (0x01D085BCu)
#define ConstValues_Addr       (0x01D085C0u)
#define MenuVersionString_Addr (0x01232846u)
#endif

#ifdef DITTO_WIN_STM /* The Swords of Ditto Windows Steam */
/* TODO! */
#endif
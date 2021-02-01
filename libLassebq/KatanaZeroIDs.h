#pragma once

// What addresses to use?
#define KZ_105_STEAM

// Please please please, keep address format like this:
// #define Something_Addr (0xSOMETHINGu)

#ifdef KZ_105_STEAM /* Katana Zero v1.0.5 Windows Steam */
#define RFunctionTable_Addr    (0x01CFCB54u)
#define RFunctionTableL_Addr   (0x01CFCB58u)
#define FREE_RValue__Pre_Addr  (0x00001070u)
#define YYSetString_Addr       (0x014DB840u)
#define YYCreateString_Addr    (0x014DAE30u)
#define YYStrDup_Addr          (0x014DB8C0u)
#define YYAddString_Addr       (0x014DB0F0u)
#define YYFree_Addr            (0x0151FFA0u)
#define ARRAY_LVAL_RV_Addr     (0x014DBF50u)
#define Variable_Addr          (0x01A37CF8u)
#define GMLScript_Addr         (0x01A3C6F4u)
#define Run_Room_Addr          (0x01CF88D8u)
#define Global_YYObject_Addr   (0x01ADE1D8u)
#define Current_Room_Addr      (0x01CF8900u)
#define Object_Hash_Addr       (0x01AE769Cu)
#define GetCtxStackTop_Addr    (0x014D5A80u)
#define DeterminePotRoot_Addr  (0x014BF440u)
#define GetEvRecursive_Addr    (0x01522300u)
#define InsertEvent_Addr       (0x015224A0u)
#define GMMMSetLength_Addr     (0x015203B0u)
#define YYSTraceStart_Addr     (0x01AD8B90u)
#define VarGetValueDirect_Addr (0x014FAE90u)
#define VarSetValueDirect_Addr (0x014FBA20u)
#define BuiltinVars_Addr       (0x01ADE300u)
#define FindRValueSlot_Addr    (0x01525AA0u)
#define Current_Event_Addr     (0x01CF8930u)
#define Current_Subtype_Addr   (0x01CF8934u)
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
#define YYSetString_Addr       (0x014D2880u)
#define YYCreateString_Addr    (0x014D98B0u)
#define YYStrDup_Addr          (0x014DA540u)
#define YYAddString_Addr       (0x014DB0F0u) /* TODO */
#define YYFree_Addr            (0x0151EC20u)
#define ARRAY_LVAL_RV_Addr     (0x014DBF50u) /* TODO */
#define Variable_Addr          (0x01A36CC0u)
#define GMLScript_Addr         (0x01A3B680u)
#define Run_Room_Addr          (0x01CF7868u)
#define Global_YYObject_Addr   (0x01ADD168u)
#define Current_Room_Addr      (0x01CF8900u)
#define Object_Hash_Addr       (0x01AE769Cu)
#define GetCtxStackTop_Addr    (0x014D5A80u)
#define DeterminePotRoot_Addr  (0x014BF440u)
#define GetEvRecursive_Addr    (0x01522300u)
#define InsertEvent_Addr       (0x015224A0u)
#define GMMMSetLength_Addr     (0x015203B0u)
#define YYSTraceStart_Addr     (0x01AD7B20u) /* done */
#define VarGetValueDirect_Addr (0x014FAE90u)
#define VarSetValueDirect_Addr (0x014FBA20u)
#define BuiltinVars_Addr       (0x01ADE300u)
#define FindRValueSlot_Addr    (0x01525AA0u)
#define Current_Event_Addr     (0x01CF8930u)
#define Current_Subtype_Addr   (0x01CF8934u)
#define YYError_Addr           (0x014DB040u)
#define ConstNumb_Addr         (0x01D09634u)
#define ConstNames_Addr        (0x01D0962Cu)
#define ConstValues_Addr       (0x01D09630u)
#define MenuVersionString_Addr (0x01233C16u)
#endif

#ifdef DITTO_WIN_STM /* The Swords of Ditto Windows Steam */
/* TODO! */
#endif
// DO NOT MODIFY MANUALLY
// Generated on Tue 09/01/2020 at 13:20:06.34 using cj-update-iids.cmd

// XTPPropertyGridIIDs.h: GUID definitions for PropertyGrid.odl.
//
// (c)1998-2020 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __XTPPropertyGridIIDs_H__
#define __XTPPropertyGridIIDs_H__

// clang-format off

#define XTP_DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
       EXTERN_C __declspec(selectany) const IID XTP##name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}; \
       const unsigned long  XTP##name##__Data1   = (l);  \
       const unsigned short XTP##name##__Data2   = (w1); \
       const unsigned short XTP##name##__Data3   = (w2); \
       const unsigned char  XTP##name##__Data4_0 = (b1); \
       const unsigned char  XTP##name##__Data4_1 = (b2); \
       const unsigned char  XTP##name##__Data4_2 = (b3); \
       const unsigned char  XTP##name##__Data4_3 = (b4); \
       const unsigned char  XTP##name##__Data4_4 = (b5); \
       const unsigned char  XTP##name##__Data4_5 = (b6); \
       const unsigned char  XTP##name##__Data4_6 = (b7); \
       const unsigned char  XTP##name##__Data4_7 = (b8);

XTP_DEFINE_GUID(LIBID_XtremePropertyGrid,0x5B44EC52,0xB95B,0x45CF,0x98,0xFF,0xA4,0x9D,0xFE,0xED,0x5A,0x92);
XTP_DEFINE_GUID(DIID_IPropertyGridItem,0xC0DE1930,0x29DC,0x4605,0xA5,0x17,0x4B,0x43,0x7E,0xFB,0x9B,0xB8);
XTP_DEFINE_GUID(DIID_IPropertyGridInplaceButton,0xC0DE1930,0xA6D3,0x4538,0x95,0x30,0x91,0xCC,0xAD,0x9C,0xE5,0xA9);
XTP_DEFINE_GUID(CLSID_PropertyGridInplaceButton,0xC0DE1930,0xD1CB,0x46E5,0xB7,0x90,0x2E,0xBC,0xD3,0xD0,0x94,0x98);
XTP_DEFINE_GUID(DIID_IPropertyGridInplaceSliderControl,0xC0DE1930,0xD6CF,0x452D,0xA0,0x06,0x67,0x99,0x1E,0x35,0xCD,0x95);
XTP_DEFINE_GUID(CLSID_PropertyGridInplaceSliderControl,0xC0DE1930,0x5EF7,0x4DF2,0x8C,0x7C,0x1E,0x9C,0x9D,0xF7,0xF4,0x93);
XTP_DEFINE_GUID(DIID_IPropertyGridInplaceSpinButton,0xC0DE1930,0x2D3C,0x4DAF,0x99,0x25,0x83,0xCB,0x5A,0xAA,0xFC,0xF7);
XTP_DEFINE_GUID(CLSID_PropertyGridInplaceSpinButton,0xC0DE1930,0x0E30,0x4A82,0x9D,0x46,0x2C,0x57,0x67,0xB9,0x8F,0x09);
XTP_DEFINE_GUID(DIID_IPropertyGridInplaceButtons,0xC0DE1930,0xF60F,0x4729,0xB7,0x10,0x9B,0x98,0xF3,0xB0,0xB7,0x43);
XTP_DEFINE_GUID(CLSID_PropertyGridInplaceButtons,0xC0DE1930,0xA872,0x493A,0xBE,0x1B,0xDE,0x32,0x3C,0xB9,0x87,0x50);
XTP_DEFINE_GUID(DIID_IPropertyGridItemConstraint,0xC0DE1930,0xFE51,0x4e7e,0xB3,0xC0,0xA7,0x98,0xDD,0xD1,0x74,0xE9);
XTP_DEFINE_GUID(CLSID_PropertyGridItemConstraint,0xC0DE1930,0x7E83,0x4DC7,0x86,0x4F,0x53,0xD5,0xD8,0xD5,0xA4,0xFE);
XTP_DEFINE_GUID(DIID_IPropertyGridItemMetrics,0xC0DE1930,0x00A6,0x4ED5,0x92,0x61,0x8D,0x35,0x6D,0x45,0x4D,0xF6);
XTP_DEFINE_GUID(CLSID_PropertyGridItemMetrics,0xC0DE1930,0x2D10,0x412D,0x9C,0x62,0x7B,0xAD,0xC3,0x14,0x2A,0x14);
XTP_DEFINE_GUID(DIID_IPropertyGridItemConstraints,0xC0DE1930,0x30A2,0x44EC,0x80,0xAB,0x2E,0xD1,0x1D,0xD3,0xD9,0x98);
XTP_DEFINE_GUID(CLSID_PropertyGridItemConstraints,0xC0DE1930,0xDFA4,0x456B,0xAC,0x35,0xC4,0x28,0xB5,0x3B,0xFD,0x12);
XTP_DEFINE_GUID(DIID_IPropertyGridItems,0xC0DE1930,0x71D6,0x40E8,0x81,0x3D,0x81,0x28,0xA8,0xA2,0x0C,0x83);
XTP_DEFINE_GUID(DIID_IPropertyGridItemFont,0xC0DE1930,0x62A8,0x4d96,0xB1,0x65,0xEE,0x28,0x4F,0x8A,0xB1,0x88);
XTP_DEFINE_GUID(CLSID_PropertyGridItemFont,0xC0DE1930,0xCECD,0x496e,0x8B,0xEE,0x9A,0x49,0xF1,0xAB,0xB8,0xAC);
XTP_DEFINE_GUID(DIID_IPropertyGridItemPicture,0xC0DE1930,0x55AC,0x4CC5,0xB3,0x54,0xE3,0x25,0x2E,0x9A,0xEF,0x9D);
XTP_DEFINE_GUID(CLSID_PropertyGridItemPicture,0xC0DE1930,0x7F43,0x4DD0,0xBA,0x47,0xA2,0xD2,0x14,0x9D,0xF6,0x55);
XTP_DEFINE_GUID(DIID_IPropertyGridItemDate,0xC0DE1930,0x6750,0x4257,0xA8,0x0A,0xA3,0x3F,0x44,0x02,0x23,0x95);
XTP_DEFINE_GUID(CLSID_PropertyGridItemDate,0xC0DE1930,0xB638,0x4d37,0x81,0x5C,0xC1,0x32,0x88,0x9B,0x89,0x82);
XTP_DEFINE_GUID(DIID_IPropertyGridItemDouble,0xC0DE1930,0x58EE,0x4502,0x8B,0x66,0x1E,0xFA,0xE9,0x42,0x6E,0x18);
XTP_DEFINE_GUID(CLSID_PropertyGridItemDouble,0xC0DE1930,0xB960,0x47AF,0x96,0xF5,0x07,0xB6,0x57,0x3B,0x6B,0x51);
XTP_DEFINE_GUID(DIID_IPropertyGridItemColor,0xC0DE1930,0x5932,0x4F54,0xAD,0x80,0x99,0xE1,0x4E,0x09,0xE7,0xE7);
XTP_DEFINE_GUID(CLSID_PropertyGridItemColor,0xC0DE1930,0xC744,0x4A8C,0xB4,0xD8,0xBB,0x13,0xC0,0x33,0xF9,0x6B);
XTP_DEFINE_GUID(DIID_IPropertyGridItemBool,0xC0DE1930,0x2D53,0x4CAA,0xA4,0x04,0x66,0xA2,0xD8,0x7C,0xCC,0x61);
XTP_DEFINE_GUID(CLSID_PropertyGridItemBool,0xC0DE1930,0x2E7B,0x43C2,0x9E,0xFB,0xE9,0x64,0x13,0x47,0x6D,0xC1);
XTP_DEFINE_GUID(DIID_PropertyGridItemOption,0xC0DE1930,0x395C,0x4BB0,0xB7,0x70,0x2C,0x5A,0xF9,0x59,0x7C,0xF9);
XTP_DEFINE_GUID(CLSID_PropertyGridItem,0xC0DE1930,0xC660,0x4D3D,0xA8,0x48,0x16,0xCE,0x23,0x2A,0x4F,0x42);
XTP_DEFINE_GUID(CLSID_PropertyGridItems,0xC0DE1930,0xE0A7,0x479C,0x97,0xD1,0x5E,0x7F,0xA1,0x52,0xD7,0x81);
XTP_DEFINE_GUID(DIID_IPropertyGridVerb,0xC0DE1930,0x9426,0x4D53,0xA3,0x53,0x0C,0xE1,0xAA,0x1C,0x2E,0x52);
XTP_DEFINE_GUID(CLSID_PropertyGridVerb,0xC0DE1930,0x05D8,0x4A90,0x96,0xFF,0xE4,0xE2,0x66,0x88,0x09,0xFE);
XTP_DEFINE_GUID(DIID_IPropertyGridVerbs,0xC0DE1930,0xD1C6,0x42A2,0x8E,0x58,0x4F,0x53,0xA6,0x5D,0xEB,0xD8);
XTP_DEFINE_GUID(CLSID_PropertyGridVerbs,0xC0DE1930,0x0B7A,0x4B38,0x88,0x87,0x02,0x75,0xBE,0x98,0x30,0x81);
XTP_DEFINE_GUID(DIID_IPropertyGridUpdateContext,0xC0DE1930,0x42EF,0x4901,0x99,0x9B,0x1F,0xAF,0xBC,0xA1,0x26,0x53);
XTP_DEFINE_GUID(CLSID_PropertyGridUpdateContext,0xC0DE1930,0x8FBA,0x45EA,0x81,0x7A,0x3F,0xDC,0xFE,0x56,0xE3,0xCD);
XTP_DEFINE_GUID(DIID_PropertyGridPaintManager,0xC0DE1930,0xEBEA,0x4FC7,0x81,0x8F,0xD6,0x04,0x2A,0x01,0xDA,0x55);
XTP_DEFINE_GUID(DIID__DPropertyGrid,0xC0DE1930,0xF160,0x4F93,0x89,0x88,0x25,0x66,0xB2,0x9C,0x7D,0x4F);
XTP_DEFINE_GUID(DIID__DPropertyGridEvents,0xC0DE1930,0x9C8A,0x488B,0x8D,0x2D,0x3B,0x44,0x5A,0x8F,0xEA,0x60);
XTP_DEFINE_GUID(CLSID_PropertyGrid,0xC0DE1930,0x864C,0x460A,0xBF,0x43,0x31,0xC6,0x16,0xC0,0xCA,0x12);
XTP_DEFINE_GUID(DIID_IPropertyGridGlobalSettings,0xC0DE1930,0x136A,0x4923,0x91,0xA2,0x24,0x75,0x2F,0x24,0x9A,0xBC);
XTP_DEFINE_GUID(CLSID_PropertyGridGlobalSettings,0xC0DE1930,0xFA65,0x4013,0xB6,0x73,0xCF,0x33,0x31,0xEC,0x7D,0xFB);

#undef XTP_DEFINE_GUID

// clang-format on

#endif // __XTPPropertyGridIIDs_H__

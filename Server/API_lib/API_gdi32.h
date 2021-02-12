#pragma once

HBITMAP API_CreateDIBSection(
  HDC hdc,                 // handle to DC
  CONST BITMAPINFO *pbmi,  // bitmap data
  UINT iUsage,             // data type indicator
  VOID **ppvBits,          // bit values
  HANDLE hSection,         // handle to file mapping object
  DWORD dwOffset           // offset to bitmap bit values
  );

HGDIOBJ API_SelectObject(
  HDC hdc,          // handle to DC
  HGDIOBJ hgdiobj   // handle to object
);

BOOL API_BitBlt(
  HDC hdcDest, // handle to destination DC
  int nXDest,  // x-coord of destination upper-left corner
  int nYDest,  // y-coord of destination upper-left corner
  int nWidth,  // width of destination rectangle
  int nHeight, // height of destination rectangle
  HDC hdcSrc,  // handle to source DC
  int nXSrc,   // x-coordinate of source upper-left corner
  int nYSrc,   // y-coordinate of source upper-left corner
  DWORD dwRop  // raster operation code
);

HBITMAP API_CreateCompatibleBitmap(
  HDC hdc,        // handle to DC
  int nWidth,     // width of bitmap, in pixels
  int nHeight     // height of bitmap, in pixels
);

int API_GetDIBits(
  HDC hdc,           // handle to DC
  HBITMAP hbmp,      // handle to bitmap
  UINT uStartScan,   // first scan line to set
  UINT cScanLines,   // number of scan lines to copy
  LPVOID lpvBits,    // array for bitmap bits
  LPBITMAPINFO lpbi, // bitmap data buffer
  UINT uUsage        // RGB or palette index
);

BOOL API_DeleteDC(
  HDC hdc   // handle to DC
);

BOOL API_DeleteObject(
  HGDIOBJ hObject   // handle to graphic object
);

HDC API_CreateCompatibleDC(
  HDC hdc   // handle to DC
);
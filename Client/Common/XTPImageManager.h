// XTPImageManager.h : interface for the CXTPImageManager class.
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

//{{AFX_CODEJOCK_PRIVATE
#if !defined(__XTPIMAGEMANAGER_H__)
#	define __XTPIMAGEMANAGER_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER >= 1000
#		pragma once
#	endif // _MSC_VER >= 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//-----------------------------------------------------------------------
// Summary:
//     Image state enumerators.
// Example:
// <code>
// // Set Icons
// pCommandBars->GetImageManager()->SetIcons(IDR_MAINFRAME, xtpImageNormal);
// pCommandBars->GetImageManager()->SetIcons(IDR_MAINFRAME, IDR_MAINFRAME_HOT, xtpImageHot);
// </code>
// See Also: CXTPImageManager::SetIcon, CXTPImageManager::SetIcons
//
// <KEYWORDS xtpImageNormal, xtpImageDisabled, xtpImageHot, xtpImageChecked>
//-----------------------------------------------------------------------
enum XTPImageState
{
	xtpImageNormal,   // Normal image.
	xtpImageDisabled, // Disabled image.
	xtpImageHot,	  // Hot image.
	xtpImageChecked,  // Checked(selected) image.
	xtpImagePressed   // Pressed image.
};

enum XTPIconSizeMatching
{
	xtpIconSizeExact,   // Requires an icon to have size the same as requested.
	xtpIconSizeAtLeast, // Requires an icon to have size the same or larger than requested.
	xtpIconSizeAtMost,  // Requires an icon to have size no more than requested.
};

class CXTPImageManager;
class CXTPImageManagerIconSet;
class CXTPImageManagerImageList;
class CXTPImageManagerIconHandle;
class CXTPImageManagerResource;
class CXTPPropExchange;
class CXTPMarkupContext;
class CXTPMarkupUIElement;

//===========================================================================
// Summary:
//      Represents a generic interface for a vector image of any possible
//      format to be used with CXTPImageManager.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerVectorImageHandle
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Construct an empty vector image handle object.
	//-----------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle();

	//-----------------------------------------------------------------------
	// Summary:
	//     Handles object destruction, releases vector image resources.
	//-----------------------------------------------------------------------
	virtual ~CXTPImageManagerVectorImageHandle();

	//-----------------------------------------------------------------------
	// Summary:
	//     Construct a copy of the vector image handle object.
	// Parameters:
	//     rhs - a source vector image handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle(const CXTPImageManagerVectorImageHandle& rhs);

	//-----------------------------------------------------------------------
	// Summary:
	//     Make the current vector image handle identical to the provided image handle.
	// Parameters:
	//     rhs - a source vector image handle.
	// Returns:
	//     Self reference.
	//-----------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle& operator=(const CXTPImageManagerVectorImageHandle& rhs);

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the current vector image handle has a valid image associated with it.
	// Returns:
	//     TRUE if the handle is a valid image.
	//-----------------------------------------------------------------------
	operator BOOL() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if the handle is associated with Markup image.
	// Returns:
	//     TRUE if the handle is associated with Markup image.
	//-----------------------------------------------------------------------
	BOOL IsMarkupImage() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the image associated with the handle.
	// Parameters:
	//      pDC - Target device context pointer.
	//      pt - Target top-left corner location.
	//      szIcon - Target image size.
	//-----------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt, CSize szIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//      Obtains a handle to image specific serialization data that can be used
	//      storing and re-storing an image from.
	// Returns:
	//      Serialization data handle. The handle is managed by the object
	//      so the caller must not deallocate or change it.
	//-----------------------------------------------------------------------
	HGLOBAL GetSerializationData() const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Creates markup image handle.
	// Parameters:
	//      pContext - User provided markup context pointer.
	//      bSharedContext - If TRUE, the user provided markup context pointer
	//                       is assumed to be shared, i.e. used and managed by the caller.
	//                       FALSE gives the image handle exclusize rights manage and
	//                       release the context once it's no longer needed.
	//      SerializationData - Markup image serialization data handle.
	//      pStream - Markup image data stream pointer.
	//      lpszCode - Markup image code pointer.
	//      nLength - Optional markup image code length in characters.
	// Returns:
	//      Serialization data handle. The handle is managed by the object
	//      so the caller must not deallocate or change it.
	//-----------------------------------------------------------------------
	static CXTPImageManagerVectorImageHandle CreateMarkupHandle(CXTPMarkupContext* pContext,
																BOOL bSharedContext,
																HGLOBAL SerializationData);
	//-----------------------------------------------------------------------
	// <combine
	// CXTPImageManagerVectorImageHandle::CreateMarkupHandle@CXTPMarkupContext*@BOOL@HGLOBAL>
	//-----------------------------------------------------------------------
	static CXTPImageManagerVectorImageHandle CreateMarkupHandle(CXTPMarkupContext* pContext,
																BOOL bSharedContext,
																IStream* pStream);
	//-----------------------------------------------------------------------
	// <combine
	// CXTPImageManagerVectorImageHandle::CreateMarkupHandle@CXTPMarkupContext*@BOOL@HGLOBAL>
	//-----------------------------------------------------------------------
	static CXTPImageManagerVectorImageHandle CreateMarkupHandle(CXTPMarkupContext* pContext,
																BOOL bSharedContext,
																LPCSTR lpszCode,
																INT_PTR nLength = -1);
	//-----------------------------------------------------------------------
	// <combine
	// CXTPImageManagerVectorImageHandle::CreateMarkupHandle@CXTPMarkupContext*@BOOL@HGLOBAL>
	//-----------------------------------------------------------------------
	static CXTPImageManagerVectorImageHandle CreateMarkupHandle(CXTPMarkupContext* pContext,
																BOOL bSharedContext,
																LPCWSTR lpszCode,
																INT_PTR nLength = -1);

private:
	CXTPImageManagerVectorImageHandle(CXTPMarkupContext* pContext, BOOL bSharedContext,
									  CXTPMarkupUIElement* pMarkupElement,
									  HGLOBAL SerializationData);
	CXTPImageManagerVectorImageHandle(CXTPMarkupContext* pContext, BOOL bSharedContext,
									  CXTPMarkupUIElement* pMarkupElement,
									  IStream* pSerializationData);

	void Reset();

private:
	struct IMAGE_RESOURCE
	{
		ULONG cRefs;
		enum
		{
			MarkupType
		} nType;
		HGLOBAL SerializationData;
		IStream* pSerializationDataStream;
		union {
			struct
			{
				CXTPMarkupContext* pContext;
				BOOL bSharedContext;
				CXTPMarkupUIElement* pMarkupElement;
			} markup;
			// more can be added
		} u;
	};

	mutable IMAGE_RESOURCE* m_pResource;
};

//-----------------------------------------------------------------------
// Summary:
//     This structure is used to define position and style of the icon in resources
//-----------------------------------------------------------------------
struct XTP_IMAGERESOURCE_INFO
{
	BOOL bAlpha; // TRUE if icon has alpha layer, otherwise m_hbmpMask used to draw its mask.
	CRect rc;	// Position of the icon inside resource's m_hbmpImage bitmap
	CXTPImageManagerResource* pResource; // Pointer to owner resources
};

//===========================================================================
// Summary:
//     CXTPImageManagerIconHandle is HICON wrapper class.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIconHandle
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIconHandle object
	// Parameters:
	//     hIcon - Icon handle
	//     hBitmap - Bitmap handle
	//     hHandle - CXTPImageManagerIconHandle reference
	//     bSharedHandle - If FALSE, the resource will be destroyed when no longer used
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle();
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle(HICON hIcon, BOOL bUseResources = TRUE, BOOL bSharedHandle = TRUE);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle(HBITMAP hBitmap, BOOL bSharedHandle = TRUE);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle(const CXTPImageManagerIconHandle& hHandle);

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIconHandle object, handles cleanup and deallocation
	//-------------------------------------------------------------------------
	~CXTPImageManagerIconHandle();

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator returns a HICON object whose value is copied from this
	//     CXTPImageManagerIconHandle object.
	// Returns:
	//     HICON handle.
	//-----------------------------------------------------------------------
	operator HICON() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Copies data from an HBITMAP or CXTPImageManagerIconHandle object
	// Parameters:
	//     handle - CXTPImageManagerIconHandle object
	//     hBitmap - Alpha bitmap handler
	//-----------------------------------------------------------------------
	void CopyHandle(HBITMAP hBitmap);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIconHandle::CopyHandle@HBITMAP>
	//-----------------------------------------------------------------------
	void CopyHandle(const CXTPImageManagerIconHandle& handle);

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the image has alpha channel.
	// Returns:
	//     TRUE if the image has alpha channel; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL IsAlpha() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns TRUE if class has no icon.
	// Returns:
	//     TRUE if m_hIcon member is NULL.
	//-----------------------------------------------------------------------
	BOOL IsEmpty() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves bitmap handle
	// Returns:
	//     32bit alpha bitmap
	//-----------------------------------------------------------------------
	HBITMAP GetBitmap() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon handle.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	HICON GetIcon() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the size of the icon.
	// Returns:
	//     Size of the icon.
	//-----------------------------------------------------------------------
	CSize GetExtent() const;

	//---------------------------------------------------------------
	// Summary:
	//      Call this method to draw icons
	// Parameters:
	//      pDC : Pointer to device context to draw into
	//      pt : Positing of icon to draw
	//      szIcon : Size of icon to draw
	//      bDrawComposited : TRUE to draw inside Vista Composited area.
	//---------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt, CSize szIcon, BOOL bDrawComposited = FALSE);

	//---------------------------------------------------------------
	// Summary:
	//      Obtains a new icon handle with icon image scaled to the specified DPI.
	// Parameters:
	//      nDdpi - Custom DPI level or 0 for the current DPI value.
	// Returns:
	//      A new scaled icon handle. The caller is responsible for destroying the handle.
	//---------------------------------------------------------------
	HICON GetDpiScaled(int nDpi = 0) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Release bitmap and icon handlers
	//-------------------------------------------------------------------------
	void Clear();

	//-------------------------------------------------------------------------
	// Summary:
	//     Creates an icon from resource bits describing the icon.
	// Parameters:
	//     hInst - Application instance handler
	//     lpszResourceName - Resource name identifier
	//     szIcon - Specifies the desired width and height, in pixels, of the icon.
	//     bGroupResource - TRUE to check if RT_GROUP_ICON resource exists.
	//     nSizeMatching - Specifies how icon size is matched. By default exact matching
	//                     is specified. Used only if bGroupResource is TRUE.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-------------------------------------------------------------------------
	BOOL CreateIconFromResource(LPCTSTR lpszResourceName, CSize szIcon, BOOL bGroupResource = TRUE,
								XTPIconSizeMatching nSizeMatching = xtpIconSizeExact);
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIconHandle::CreateIconFromResource@LPCTSTR@CSize@BOOL>
	//-------------------------------------------------------------------------
	BOOL CreateIconFromResource(HINSTANCE hInst, LPCTSTR lpszResourceName, CSize szIcon,
								BOOL bGroupResource,
								XTPIconSizeMatching nSizeMatching = xtpIconSizeExact);

	//-----------------------------------------------------------------------
	// Summary:
	//     Attaches an object ot an existing icon handle.
	// Parameters:
	//     hIcon - source icon handler
	//     bSharedHandle - If FALSE, the resource will be destroyed when no longer used
	//-----------------------------------------------------------------------
	void Attach(HICON hIcon, BOOL bSharedHandle);

	//-----------------------------------------------------------------------
	// Summary:
	//     Attaches an object ot an existing bitmap handle.
	// Parameters:
	//     hBitmap - Alpha bitmap handler
	//     bSharedHandle - If FALSE, the resource will be destroyed when no longer used
	//-----------------------------------------------------------------------
	void Attach(HBITMAP hBitmap, BOOL bSharedHandle);

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator assigns the icon handler to a CXTPImageManagerIconHandle object.
	// Parameters:
	//     hIcon - source icon handler
	//-----------------------------------------------------------------------
	_XTP_DEPRECATE("Use CXTPImageManagerIconHandle::Attach in order to eliminate GDI leaks")
	const CXTPImageManagerIconHandle& operator=(const HICON hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator assigns the alpha bitmap handler to a CXTPImageManagerIconHandle object.
	// Parameters:
	//     hBitmap - Alpha bitmap handler
	//-----------------------------------------------------------------------
	_XTP_DEPRECATE("Use CXTPImageManagerIconHandle::Attach in order to eliminate GDI leaks")
	const CXTPImageManagerIconHandle& operator=(const HBITMAP hBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Create alpha bitmap with valid alpha layer.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	LPBYTE PreMultiply();

	//-----------------------------------------------------------------------
	// Summary:
	//     Detaches the handle from the associated icon handle without releasing the resource.
	//-----------------------------------------------------------------------
	void Detach();

protected:
	//---------------------------------------------------------------
	// Summary:
	//      Initializes icons
	//---------------------------------------------------------------
	void Init();

private:
	const CXTPImageManagerIconHandle& operator=(const CXTPImageManagerIconHandle&);
	CSize _GetExtent() const;

protected:
	HICON m_hIcon;	 // The underlying HICON handler for this CXTPImageManagerIconHandle object.
	HBITMAP m_hBitmap; // The underlying Alpha bitmap handler for this CXTPImageManagerIconHandle
					   // object.
	LPBYTE m_pBits;	// Alpha bitmap bits;
	BOOL m_bClearHandles;			   // TRUE if object must destroy handlers.
	CXTPImageManager* m_pImageManager; // Pointer to parent Image Manager
	XTP_IMAGERESOURCE_INFO* m_pRInfo;  // Pointer to resource info if icon is part of common
									   // resources
	CSize m_szIcon;					   // Size of the icon
	BOOL m_bUseResources;			   // TRUE to use common resources

private:
	friend class CXTPImageManagerIcon;
	friend class CXTPImageManagerResource;
};

//===========================================================================
// Summary:
//     Icons holder class.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIcon : public CXTPCmdTarget
{
	DECLARE_DYNAMIC(CXTPImageManagerIcon)

private:
	struct ICONDIRENTRY;
	struct ICONDIRHEADER;
	struct ICONIMAGE;
	struct GRPICONDIRENTRY;
	struct GRPICONDIR;

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIcon object.
	// Parameters:
	//     nID - Icon identifier.
	//     nWidth - Initial width for the icon.
	//     nHeight - Initial height for the icon.
	//     pIconSet - Parent icon set icon will belong.
	//     pImageList - Parent icon set icon will belong.
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon(UINT nID, int nWidth, int nHeight,
						 CXTPImageManagerIconSet* pIconSet = NULL);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::CXTPImageManagerIcon@UINT@int@int@CXTPImageManagerIconSet*>
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon(UINT nID, int nWidth, int nHeight, CXTPImageManagerImageList* pImageList);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::CXTPImageManagerIcon@UINT@int@int@CXTPImageManagerIconSet*>
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon(UINT nID, CXTPImageManagerIconSet* pIconSet = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIcon object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the image identifier.
	// Returns:
	//     Identifier of the image
	//-----------------------------------------------------------------------
	UINT GetID() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the image has alpha channel.
	// Returns:
	//     TRUE if the image has alpha channel; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL IsAlpha() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Checks if icons was scaled from another CXTPImageManagerIcon object.
	//-------------------------------------------------------------------------
	BOOL IsScaled() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Obtains a pointer to an associated image list if the icon object is an
	//     icon in an image list. If the returned pointer is not NULL then icon
	//     ID should be used as an icon index in the returned image list.
	// Returns:
	//     Pointer value to an associated image list or NULL.
	//-------------------------------------------------------------------------
	CXTPImageManagerImageList* GetImageList();
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::GetImageList>
	//-----------------------------------------------------------------------
	const CXTPImageManagerImageList* GetImageList() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon handle.
	// Parameters:
	//     imageState - Image state for icon to retrieve
	// Returns:
	//     Icon handle.
	// See Also: XTPImageState
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetIcon();
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::GetIcon>
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetIcon(XTPImageState imageState);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the faded icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetFadedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the shadow for the icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetShadowIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the shadow for the icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetCheckedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the pressed icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetPressedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves hot icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetHotIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the disabled icon.
	// Parameters:
	//     bCreateIfNotExists - Create if image not exists.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetDisabledIcon(BOOL bCreateIfNotExists = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if state specific icon exists.
	// Parameters:
	//     imageState - Image state for which to check icon existence.
	// Returns:
	//     TRUE if state specific icon exists.
	//-----------------------------------------------------------------------
	BOOL HasIcon(XTPImageState imageState) const;
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::HasIcon@XTPImageState>
	// -----------------------------------------------------------------------
	BOOL HasNormalIcon() const;
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::HasIcon@XTPImageState>
	// -----------------------------------------------------------------------
	BOOL HasDisabledIcon() const;
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::HasIcon@XTPImageState>
	// -----------------------------------------------------------------------
	BOOL HasCheckedIcon() const;
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::HasIcon@XTPImageState>
	// -----------------------------------------------------------------------
	BOOL HasPressedIcon() const;
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::HasIcon@XTPImageState>
	// -----------------------------------------------------------------------
	BOOL HasHotIcon() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Creates a disabled icon.
	// Parameters:
	//     clrDisabledLight - The lightest color of icon to generate
	//     clrDisabledDark -  The darkest color of icon to generate
	//-----------------------------------------------------------------------
	void CreateDisabledIcon(COLORREF clrDisabledLight = (COLORREF)-1,
							COLORREF clrDisabledDark  = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//     imageState - State of the icon
	//     nWidth - Width of icon.
	//     nHeight - Height of icon.
	//     nIDResourceIcon - Icon resource identifier.
	//     nSizeMatching - Specifies how icon size is matched. By default exact matching
	//                     is specified. Used only if group icon resources.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL SetIcon(const CXTPImageManagerIconHandle& hIcon);
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetIcon@CXTPImageManagerIconHandle&amp;>
	// -----------------------------------------------------------------------
	BOOL SetIcon(const CXTPImageManagerIconHandle& hIcon, XTPImageState imageState);
	// -----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetIcon@CXTPImageManagerIconHandle&amp;>
	// -----------------------------------------------------------------------
	BOOL SetIcon(UINT nIDResourceIcon, int nWidth, int nHeight,
				 XTPIconSizeMatching nSizeMatching = xtpIconSizeExact);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the disabled icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetDisabledIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the hot icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetHotIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the checked icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetCheckedIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetNormalIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the pressed icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetPressedIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the size of the icon.
	// Parameters:
	//     hIcon - Icon handle.
	// Returns:
	//     Size of the icon.
	//-----------------------------------------------------------------------
	CSize GetExtent() const;
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::GetExtent@const>
	//-----------------------------------------------------------------------
	static CSize AFX_CDECL GetExtent(HICON hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method tests if file is alpha bitmap.
	// Parameters:
	//     pszFileName - File path.
	// Returns:
	//     TRUE if file is alpha bitmap
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapFile(LPCTSTR pszFileName);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method tests if file is png image.
	// Parameters:
	//     pszFileName - File path.
	// Returns:
	//     TRUE if file is png image
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsPngBitmapFile(LPCTSTR pszFileName);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads alpha bitmap from icon file.
	// Parameters:
	//     pszFileName - File path.
	//     nWidth - Icon width to load.
	// Returns:
	//     Alpha bitmap if icon with specified width was found; otherwise returns NULL.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadAlphaIcon(LPCTSTR pszFileName, int nWidth);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads Alpha bitmap from resource file
	// Parameters:
	//     nIDResource - Resource identifier
	//     hModule - Handle to the instance of the module whose executable file contains the bitmap
	//     to be loaded. lpszResource - Long pointer to a null-terminated string that contains the
	//     name of the bitmap resource to be loaded
	// Remarks:
	//     Don't use LoadImage to load alpha bitmap, it loose alpha channel in some Windows.
	// Returns:
	//     Alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadAlphaBitmap(UINT nIDResource);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::LoadAlphaBitmap@UINT>
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadAlphaBitmap(HMODULE hModule, LPCTSTR lpszResource);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads bitmap from file on disk
	// Parameters:
	//     lpszFileName - File name of bitmap or png file
	//     lbAlphaBitmap - Determines if bitmap contained alpha layer
	// Remarks:
	//     This method loads png or bitmap from file
	// Returns:
	//     Bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadBitmapFromFile(LPCTSTR lpszFileName, BOOL* lbAlphaBitmap = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads Alpha bitmap from resource file
	// Parameters:
	//     hModule - Handle to the instance of the module whose executable file contains the bitmap
	//     to be loaded. lpszResource - Long pointer to a null-terminated string that contains the
	//     name of the bitmap resource to be loaded lbAlphaBitmap - Determines if bitmap contained
	//     alpha layer
	// Remarks:
	//     This method loads png or bitmap resource from file
	// Returns:
	//     Alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadBitmapFromResource(LPCTSTR lpszResource, BOOL* lbAlphaBitmap);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::LoadBitmapFromResource@LPCTSTR@BOOL*>
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadBitmapFromResource(HMODULE hModule, LPCTSTR lpszResource,
													BOOL* lbAlphaBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource has alpha channel.
	// Parameters:
	//     hModule - Module of the bitmap to check.
	//     lpBitmapName - Resource name of the bitmap to check.
	// Returns:
	//     TRUE if bitmap has alpha channel; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapResource(HMODULE hModule, LPCTSTR lpBitmapName);

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource is png resource.
	// Parameters:
	//     hModule - Module of the bitmap to check.
	//     lpBitmapName - Resource name of the bitmap to check.
	// Returns:
	//     TRUE if bitmap is png resource; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsPngBitmapResource(HMODULE hModule, LPCTSTR lpBitmapName);

	//-----------------------------------------------------------------------
	// Summary:
	//     The DrawAlphaBitmap function displays bitmaps that have transparent or semitransparent
	//     pixels.
	// Parameters:
	//     pDC     - Pointer to destination device context
	//     ptDest      - upper-left corner of the  destination rectangle
	//     ptSrc      - upper-left corner of the source rectangle
	//     hBitmap - Alpha bitmap handler
	//     szDest  - Destination size
	//     szSrc   - Source size
	//-----------------------------------------------------------------------
	static void AFX_CDECL DrawAlphaBitmap(CDC* pDC, HBITMAP hBitmap, CPoint ptDest, CSize szDest,
										  CPoint ptSrc = 0, CSize szSrc = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     Creates valid alpha bits to use in AlphaBlend.
	// Parameters:
	//     hBitmap - Alpha bitmap handler
	// Returns:
	//     Valid alpha bits
	// See Also: BLENDFUNCTION, AlphaBlend
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL PreMultiplyAlphaBitmap(HBITMAP hBitmap, BOOL* pbAlpha = NULL,
													LPBYTE* lpBits = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to create mirror copy of bitmap
	// Parameters:
	//     hBitmap - Bitmap handle to make copy
	// Returns: new mirror bitmap
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL InvertAlphaBitmap(HBITMAP hBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     This helper method retrieves information about alpha bitmap and its alpha bits.
	// Parameters:
	//     dcSrc   - Reference to CDC
	//     hBitmap - Alpha bitmap
	//     pbmi    - Bitmap information
	//     pBits   - Bitmap bits
	//     nSize   - Size of bits array
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL GetBitmapBits(CDC& dcSrc, HBITMAP hBitmap, PBITMAPINFO& pbmi,
										LPVOID& pBits, UINT& nSize);

	//-----------------------------------------------------------------------
	// Summary:
	//     Copies alpha bitmap.
	// Parameters:
	//     hBitmap - Bitmap handler to be copied.
	// Returns:
	//     New alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL CopyAlphaBitmap(HBITMAP hBitmap, LPBYTE* lpBits = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines whether the provide icon is translucent or not.
	// Parameters:
	//     hicon - Icon handle to check.
	// Returns:
	//     TRUE if the icon provided is translucent, or FALSE othewise.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaIconHandle(HICON hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon height.
	// Returns:
	//     Height of the icon.
	//-----------------------------------------------------------------------
	int GetHeight() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon width.
	// Returns:
	//     Width of the icon.
	//-----------------------------------------------------------------------
	int GetWidth() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     ar - A CArchive object to serialize to or from.
	//-----------------------------------------------------------------------
	void Serialize(CArchive& ar);

	//-----------------------------------------------------------------------
	// Summary:
	//     Make the current icon a copy of the provided icon.
	// Parameters:
	//     pIcon - An icon pointer to copy from.
	//-----------------------------------------------------------------------
	void Copy(CXTPImageManagerIcon* pIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     hIcon - Icon to be serialized
	//     ar - A CArchive object to serialize to or from.
	//-----------------------------------------------------------------------
	void SerializeIcon(CXTPImageManagerIconHandle& hIcon, CArchive& ar, long nSchema);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SerializeIcon@CXTPImageManagerIconHandle&@CArchive&@long>
	//-----------------------------------------------------------------------
	void SerializeIcon(CXTPImageManagerVectorImageHandle& hIcon, CArchive& ar, long nSchema);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the image in specified location.
	// Parameters:
	//     pDC    - Destination device context.
	//     pt     - Specifies the location of the image
	//     hIcon  - A handle to an icon.
	//     szIcon - Specifies the size of the image.
	//     imageState - State specific image to draw.
	//-----------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::Draw@CDC*@CPoint>
	//-----------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt, CSize szIcon);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::Draw@CDC*@CPoint>
	//-----------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt, XTPImageState imageState);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::Draw@CDC*@CPoint>
	//-----------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt, XTPImageState imageState, CSize szIcon);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::Draw@CDC*@CPoint>
	//-----------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon = 0,
			  COLORREF clrBK = CLR_NONE, COLORREF clrFG = CLR_NONE, UINT uiFlags = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the image using the brush specified by the clrBrush parameter.
	// Parameters:
	//     pDC      - Destination device context.
	//     pt       - Specifies the location of the image.
	//     hIcon    - A handle to an icon.
	//     clrBrush - color of the brush used to draw the image.
	//-----------------------------------------------------------------------
	void DrawMono(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon,
				  COLORREF clrBrush);

	//-------------------------------------------------------------------------
	// Summary:
	//     Redraw Fade and Shadow icons.
	//-------------------------------------------------------------------------
	void Refresh();

	//-------------------------------------------------------------------------
	// Summary:
	//     Creates markup context if it is necessary for the icon and hasn't been
	//     created yet.
	// Returns:
	//     A pointer to the created or existing markup context, or NULL if such context
	//     is not required for the icon type.
	//-------------------------------------------------------------------------
	CXTPMarkupContext* CreateMarkupContext();

	//-------------------------------------------------------------------------
	// Summary:
	//     Creates markup context if it is necessary for the icon and hasn't been
	//     created yet.
	// Returns:
	//     A pointer to the created or existing markup context, or NULL if such context
	//     is not required for the icon type.
	//-------------------------------------------------------------------------
	CXTPMarkupContext* GetMarkupContext();

	//-------------------------------------------------------------------------
	// Summary:
	//     Sets icon for the specified state.
	// Parameters:
	//     hIcon - Icon handle to use for the specified state.
	//     imageState - Image state identifier to set icon for.
	// Returns:
	//     TRUE if an icon was successfully set.
	//-------------------------------------------------------------------------
	BOOL SetVectorIcon(CXTPImageManagerVectorImageHandle hIcon);
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetVectorIcon@CXTPImageManagerVectorImageHandle>
	//-------------------------------------------------------------------------
	BOOL SetVectorIcon(CXTPImageManagerVectorImageHandle hIcon, XTPImageState imageState);
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetVectorIcon@CXTPImageManagerVectorImageHandle>
	//-------------------------------------------------------------------------
	BOOL SetVectorDisabledIcon(CXTPImageManagerVectorImageHandle hIcon);
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetVectorIcon@CXTPImageManagerVectorImageHandle>
	//-------------------------------------------------------------------------
	BOOL SetVectorHotIcon(CXTPImageManagerVectorImageHandle hIcon);
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetVectorIcon@CXTPImageManagerVectorImageHandle>
	//-------------------------------------------------------------------------
	BOOL SetVectorCheckedIcon(CXTPImageManagerVectorImageHandle hIcon);
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::SetVectorIcon@CXTPImageManagerVectorImageHandle>
	//-------------------------------------------------------------------------
	BOOL SetVectorPressedIcon(CXTPImageManagerVectorImageHandle hIcon);

	//-------------------------------------------------------------------------
	// Summary:
	//     Obtains vector icon handle for the specified state.
	//     imageState - Image state identifier to obtain the icon for.
	// Returns:
	//     State specific icon handle.
	//-------------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle GetVectorIcon() const;
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::GetVectorIcon>
	//-------------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle GetVectorIcon(XTPImageState imageState) const;
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::GetVectorIcon>
	//-------------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle GetVectorCheckedIcon() const;
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::GetVectorIcon>
	//-------------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle GetVectorPressedIcon() const;
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::GetVectorIcon>
	//-------------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle GetVectorHotIcon() const;
	//-------------------------------------------------------------------------
	// <combine CXTPImageManagerIcon::GetVectorIcon>
	//-------------------------------------------------------------------------
	CXTPImageManagerVectorImageHandle GetVectorDisabledIcon() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Draws the specified vector icon to the specified device context at the specific location.
	// Parameters:
	//     pDC - Target device context pointer.
	//     pt - Target output position.
	//     hIcon - vector icon handle to draw.
	//     szIcon - Target icon size to draw.
	//-------------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt, CXTPImageManagerVectorImageHandle hIcon, CSize szIcon = 0);

	//-------------------------------------------------------------------------
	// Summary:
	//     Checks if the current icon is a raster icon.
	// Returns:
	//     TRUE for a raster icon.
	//-------------------------------------------------------------------------
	BOOL IsRasterIcon() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Checks if the current icon is a vector icon.
	// Returns:
	//     TRUE for a vector icon.
	//-------------------------------------------------------------------------
	BOOL IsVectorIcon() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Checks if the current icon has an underfined type, i.e. no icon is associated with it.
	// Returns:
	//     TRUE for an undefined icon.
	//-------------------------------------------------------------------------
	BOOL IsUndefinedIcon() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Use this method to scale icon.
	// Parameters:
	//     hIcon - Icon to be scaled.
	//     szExtent - Source icon size.
	//     nWidth - With of result icon.
	//-----------------------------------------------------------------------
	static HICON AFX_CDECL ScaleToFit(HICON hIcon, CSize szExtent, int nWidth);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to draw non-alpha icon in composited Vista Glass rectangle
	// Parameters:
	//     pDC - Pointer to device context
	//     pt - Pointer to draw icon
	//     szIcon - Size of the icon
	//     hIcon - Icon handle to draw
	//-----------------------------------------------------------------------
	static void AFX_CDECL DrawIconComposited(CDC* pDC, CPoint pt, CSize szIcon, HICON hIcon);

private:
	void CreateFadedIcon();
	void CreateShadowIcon();

	void Clear(BOOL bIcon = FALSE);
	COLORREF LightenColor(COLORREF clr, double factor);

	BOOL GetDIBBitmap(HBITMAP hBitmap, PBYTE& pBits, UINT& nBitsSize, PBITMAPINFO& pBitmapInfo,
					  UINT& nBitmapInfoSize);
	HBITMAP ReadDIBBitmap(CArchive& ar, LPBYTE* pBits1);
	void WriteDIBBitmap(CArchive& ar, HBITMAP hBitmap);

	CXTPImageManager* GetImageManager() const;

private:
	CXTPImageManagerIcon(const CXTPImageManagerIcon&)
		: m_nID(0)
		, m_nType(RasterIcon)
		, m_pMarkupContext(NULL)
	{
	}

	const CXTPImageManagerIcon& operator=(const CXTPImageManagerIcon&)
	{
		return *this;
	}

public:
	BOOL m_bDrawComposited; // Draw on Vista composited rects.

private:
	const UINT m_nID;
	enum IconType
	{
		UndefinedIcon,
		RasterIcon,
		VectorIcon
	} m_nType;

	int m_nWidth;
	int m_nHeight;
	CXTPImageManagerIconHandle m_hIcon;
	CXTPImageManagerIconHandle m_hFaded;
	CXTPImageManagerIconHandle m_hShadow;
	CXTPImageManagerIconHandle m_hHot;
	CXTPImageManagerIconHandle m_hChecked;
	CXTPImageManagerIconHandle m_hPressed;
	CXTPImageManagerIconHandle m_hDisabled;
	CXTPImageManagerIconHandle m_hDisabledAuto;
	CXTPImageManagerIconSet* m_pIconSet;
	CXTPImageManagerImageList* m_pImageList;

	CXTPMarkupContext* m_pMarkupContext;

	CXTPImageManagerVectorImageHandle m_VectorImageNormal;
	CXTPImageManagerVectorImageHandle m_VectorImageHot;
	CXTPImageManagerVectorImageHandle m_VectorImageChecked;
	CXTPImageManagerVectorImageHandle m_VectorImagePressed;
	CXTPImageManagerVectorImageHandle m_VectorImageDisabled;

private:
	friend class CXTPImageManager;
	friend class CXTPImageManagerIconSet;
	friend class CXTPImageManagerIconHandle;

#	ifdef _XTP_ACTIVEX
	//{{AFX_CODEJOCK_PRIVATE
public:
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	DECLARE_OLETYPELIB_EX(CXTPImageManagerIcon);
	afx_msg long OleGetHandle();
	afx_msg void OleDraw(long hDC, int x, int y, int cx, int cy, int nState);
	afx_msg LPDISPATCH OleCreatePicture(int nState);
	afx_msg LPDISPATCH OleScale(long nWidth);
//}}AFX_CODEJOCK_PRIVATE
#	endif
};

//===========================================================================
// Summary:
//     CXTPImageManagerIconSet represents the collection of icons for specified identifier.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIconSet : public CXTPCmdTarget
{
public:
	typedef CMap<UINT, UINT, CXTPImageManagerIcon*, CXTPImageManagerIcon*>
		CIconSetMap; // Icons collection.

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIconSet object.
	// Parameters:
	//     nID - Icon set identifier.
	//     pImageManager - Parent image manager CXTPImageManagerIconSet belongs.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconSet(UINT nID, CXTPImageManager* pImageManager);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIconSet object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerIconSet();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icon with the specified width
	// Parameters:
	//     nWidth - Width of the icon to retrieve.
	//     bScaled - TRUE to scale icon.
	// Returns:
	//     A pointer to a CXTPImageManagerIcon object
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon* GetIcon(UINT nWidth, BOOL bScaled = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the collection of icons
	// Returns:
	//     A pointer to a CIconSetMap object
	//-----------------------------------------------------------------------
	CIconSetMap* GetIcons();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the identifier of the collection set.
	// Returns:
	//     Identifier of icons.
	//-----------------------------------------------------------------------
	UINT GetID() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Removes all icons
	//-------------------------------------------------------------------------
	void RemoveAll();

	//-------------------------------------------------------------------------
	// Summary:
	//     Redraws all icons.
	//-------------------------------------------------------------------------
	void RefreshAll();

private:
	CXTPImageManagerIcon* CreateIcon(UINT nWidth);
	void SetIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);
	void SetDisabledIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);
	void SetHotIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);
	void SetCheckedIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);
	void SetPressedIcon(const CXTPImageManagerIconHandle& hIcon, UINT nWidth);

	CXTPImageManagerIcon* CreateVectorIcon(UINT nWidth);
	BOOL SetVectorIcon(IStream* pStream, UINT nWidth);
	BOOL SetVectorDisabledIcon(IStream* pStream, UINT nWidth);
	BOOL SetVectorHotIcon(IStream* pStream, UINT nWidth);
	BOOL SetVectorCheckedIcon(IStream* pStream, UINT nWidth);
	BOOL SetVectorPressedIcon(IStream* pStream, UINT nWidth);

	BOOL SetVectorIcon(CXTPImageManagerVectorImageHandle hIcon, UINT nWidth);
	BOOL SetVectorDisabledIcon(CXTPImageManagerVectorImageHandle hIcon, UINT nWidth);
	BOOL SetVectorHotIcon(CXTPImageManagerVectorImageHandle hIcon, UINT nWidth);
	BOOL SetVectorCheckedIcon(CXTPImageManagerVectorImageHandle hIcon, UINT nWidth);
	BOOL SetVectorPressedIcon(CXTPImageManagerVectorImageHandle hIcon, UINT nWidth);

#	ifdef _XTP_ACTIVEX
	//{{AFX_CODEJOCK_PRIVATE
public:
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPImageManagerIconSet);
	DECLARE_ENUM_VARIANTLIST(CXTPImageManagerIconSet)

	afx_msg long OleGetCount();
	afx_msg long OleGetID();
	LPDISPATCH OleGetImage(long Width);

	//}}AFX_CODEJOCK_PRIVATE
#	endif

private:
	CXTPImageManagerIconSet(const CXTPImageManagerIconSet&)
		: m_nID(0)
	{
	}

	const CXTPImageManagerIconSet& operator=(const CXTPImageManagerIconSet&)
	{
		return *this;
	}

private:
	CIconSetMap m_mapIcons;
	const UINT m_nID;
	CXTPImageManager* m_pImageManager;

private:
	friend class CXTPImageManager;
	friend class CXTPImageManagerIcon;
};

//===========================================================================
// Summary:
//     This class is used to connect ImageManager with specified HIMAGELIST
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerImageList
{
public:
	//---------------------------------------
	// Summary:
	//      Constructs  CXTPImageManagerImageList class
	//---------------------------------------
	CXTPImageManagerImageList();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerImageList object, handles cleanup and de-
	//     allocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerImageList();

public:
	//---------------------------------------
	// Summary:
	//      Call this method to determine of ImageList handles nCommand Id
	// Parameters:
	//      nCommand : Command to check
	// Returns:
	//      TRUE if imagelist contais nCommand.
	//---------------------------------------
	BOOL Lookup(UINT nCommand);

	//---------------------------------------
	// Summary:
	//      Creates temporary CXTPImageManagerIcon for command nCommand to draw using HIMAGELIST
	// Parameters:
	//      nCommand : Command to create icon for
	// Returns:
	//      Returns CXTPImageManagerIcon tat can be used to draw specified nCommand icon
	//---------------------------------------
	CXTPImageManagerIcon* GetIcon(UINT nCommand);

	//---------------------------------------
	// Summary:
	//      Call this method to draw specified pIcon
	// Parameters:
	//      pDC : Device context to draw into
	//      pt : Position of icon to draw
	//      pIcon : Pointer to icon to draw
	//      szIcon : Size of the icon
	//      clrBK : Background color of the image.
	//      clrFG : Foreground color of the image
	//      uiFlags : Drawing style and, optionally, the overlay image
	//---------------------------------------
	void Draw(CDC* pDC, CPoint pt, CXTPImageManagerIcon* pIcon, CSize szIcon,
			  COLORREF clrBK = CLR_NONE, COLORREF clrFG = CLR_NONE, UINT uiFlags = 0);

	//---------------------------------------
	// Summary:
	//     Cleans all temporary icons
	//---------------------------------------
	void RemoveAll();

	//---------------------------------------
	// Summary:
	//     Returns size of images inside HIMAGELIST
	// Returns:
	//     Size of images inside connected m_hImageList;
	//---------------------------------------
	CSize GetIconSize() const;

	//---------------------------------------
	// Summary:
	//     Returns icon handle for the image specified by command ID.
	// Returns:
	//     Icon handle or NULL.
	//---------------------------------------
	HICON GetIconHandle(UINT nCommand) const;

	//---------------------------------------
	// Summary:
	//     Returns bitmap handle for the image specified by command ID.
	// Returns:
	//     Bitmap handle or NULL.
	//---------------------------------------
	HBITMAP GetBitmapHandle(UINT nCommand) const;

private:
	HIMAGELIST m_hImageList;
	BOOL m_bDestroyImageList;
	UINT m_nBaseCommand;
	CXTPImageManager* m_pImageManager;
	CMap<UINT, UINT, CXTPImageManagerIcon*, CXTPImageManagerIcon*> m_mapIcons;

	friend class CXTPImageManager;
};

//===========================================================================
// Summary:
//     CXTPImageManager is a stand alone class. It is used to manipulate icons.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManager : public CXTPCmdTarget
{
	friend class CXTPSingleton<CXTPImageManager>;

	DECLARE_DYNAMIC(CXTPImageManager);

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManager object.
	//-----------------------------------------------------------------------
	CXTPImageManager();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManager object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManager();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icons.
	// Parameters:
	//     nIDResourceBitmap  - Bitmap resource identifier
	//     lpszResourceBitmap - Bitmap resource identifier
	//     nIDResourceToolBar - Toolbar resource identifier
	//     bmpIcons           - Bitmap containing icons to be added.
	//     imlIcons           - Image list containing the icons to be added.
	//     pCommands          - Pointer to an array of IDs.
	//     nCount             - Number of elements in the array pointed to by lpIDArray.
	//     szIcon             - Size of the icons.
	//     imageState         - Images state.
	//     bAlpha             - TRUE if bitmap has alpha channel.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// Example:
	// <code>
	//
	// static UINT buttons[] =
	// {
	//     ID_BACK,
	//     ID_FORWARD,
	//     ID_STOP,
	//     ID_REFRESH,
	//     ID_HOME
	// }
	//
	// XTPImageManager()->SetMaskColor(RGB(0, 0xFF, 0));
	//
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_NORMAL_SMALL, buttons, _countof(buttons), CSize(16,
	// 16), xtpImageNormal); XTPImageManager()->SetIcons(IDR_TOOLBAR_HOT_SMALL, buttons,
	// _countof(buttons), CSize(16, 16), xtpImageHot);
	//
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_NORMAL_LARGE, buttons, _countof(buttons), CSize(24,
	// 24), xtpImageNormal); XTPImageManager()->SetIcons(IDR_TOOLBAR_HOT_LARGE, buttons,
	// _countof(buttons), CSize(24, 24), xtpImageHot);
	// </code>
	// See Also: XTPImageState, SetIcon
	//-----------------------------------------------------------------------
	BOOL SetIcons(UINT nIDResourceToolBar, XTPImageState imageState = xtpImageNormal);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcons@UINT@XTPImageState>
	//-----------------------------------------------------------------------
	BOOL SetIcons(UINT nIDResourceToolBar, UINT nIDResourceBitmap,
				  XTPImageState imageState = xtpImageNormal);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcons@UINT@XTPImageState>
	//-----------------------------------------------------------------------
	BOOL SetIcons(CBitmap& bmpIcons, UINT* pCommands, int nCount, CSize szIcon,
				  XTPImageState imageState = xtpImageNormal, BOOL bAlpha = FALSE);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcons@UINT@XTPImageState>
	//-----------------------------------------------------------------------
	BOOL SetIcons(UINT nIDResourceToolBar, CBitmap& bmpIcons,
				  XTPImageState imageState = xtpImageNormal);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcons@UINT@XTPImageState>
	//-----------------------------------------------------------------------
	BOOL SetIcons(UINT nIDResourceBitmap, UINT* pCommands, int nCount, CSize szIcon,
				  XTPImageState imageState = xtpImageNormal);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcons@UINT@XTPImageState>
	//-----------------------------------------------------------------------
	BOOL SetIcons(LPCTSTR lpszResourceBitmap, UINT* pCommands, int nCount, CSize szIcon,
				  XTPImageState imageState = xtpImageNormal);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcons@UINT@XTPImageState>
	//-----------------------------------------------------------------------
	BOOL SetIcons(CImageList& imlIcons, UINT* pCommands, int nCount, CSize szIcon,
				  XTPImageState imageState = xtpImageNormal);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcons@UINT@XTPImageState>
	//-----------------------------------------------------------------------
	BOOL SetIcons(UINT nIDResourceToolBar, CImageList& imlIcons,
				  XTPImageState imageState = xtpImageNormal);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads icon from ico file
	// Parameters:
	//     lpszFileName - Path to ico file
	//     nIDCommand   - Icon command
	//     szIcon       - Size of the icons.
	//     imageState   - Images state.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL SetIconFromIcoFile(LPCTSTR lpszFileName, UINT nIDCommand, CSize szIcon,
							XTPImageState imageState);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this to attach images from a HIMAGELIST control to the image manager
	// Parameters:
	//     hImageList - Pointer to an imagelist that holds icons
	//     nBaseCommand - ID to start numbering icons from the imagelist
	//     bDestoryImageList - Destroy imagelist control after the icons are copied to the
	//     imagemanager
	//-----------------------------------------------------------------------
	BOOL SetImageList(HIMAGELIST hImageList, int nBaseCommand, BOOL bDestoryImageList = FALSE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this to create system HIMAGELIST from bitmap and add it to image manager
	// Parameters:
	//     nIDResourceBitmap - Bitmap resource identifier
	//     cx - Width of the icons
	//     nBaseCommand - ID to start numbering icons from the imagelist
	//     clrMask - Mask color for bitmap
	// Remarks:
	//     SetIcons method loads bitmaps and creates HICON for each icon in bitmap, SetImageList
	//     creates only one HIMAGELIST. use SetImageList to create only one GDI object for all
	//     icons.
	// See Also: SetIcons
	//-----------------------------------------------------------------------
	BOOL SetImageList(UINT nIDResourceBitmap, int cx, int nBaseCommand = 0,
					  COLORREF clrMask = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icons from another image manager.
	// Parameters:
	//     pImageManager - A pointer to another image manager. The icons in pImageManager will be
	//     added to this image manager.
	//-----------------------------------------------------------------------
	void AddIcons(CXTPImageManager* pImageManager);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::AddIcons@CXTPImageManager*>
	//-----------------------------------------------------------------------
	void AddIcons(CXTPImageManagerIconSet* pIconSet);

	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icon.
	// Parameters:
	//     hIcon           - Icon handle to add
	//     nIDResourceIcon - Icon resource identifier
	//     lpszResourceIcon - Icon resource identifier
	//     nIDCommand      - Icon identifier.
	//     szIcon          - Size of the icons.
	//     imageState      - Images state.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// See Also: XTPImageState, SetIcons
	//-----------------------------------------------------------------------
	BOOL SetIcon(const CXTPImageManagerIconHandle& hIcon, UINT nIDCommand, CSize szIcon = 0,
				 XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcon@CXTPImageManagerIconHandle&amp;@UINT@CSize@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetIcon(UINT nIDResourceIcon, UINT nIDCommand, CSize szIcon = 0,
				 XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetIcon@CXTPImageManagerIconHandle&amp;@UINT@CSize@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetIcon(LPCTSTR lpszResourceIcon, UINT nIDCommand, CSize szIcon = 0,
				 XTPImageState imageState = xtpImageNormal);

	// --------------------------------------------------------------------------------------------
	// Summary:
	//      Sets a vector icon for the specific image state and and command identifier.
	//  Parameters:
	//      hModule - Modules instance handle where to look for icon resource.
	//      lpRsourceType - Vector icon resource type name.
	//      nIDResource - Vector icon resource identified.
	//      lpIDResource - Vector icon resource identified.
	//      nIDCommand - Associated command identifier.
	//      imageState - Associated image state.
	//      hImage - Pre-loaded vector image handle.
	//      nWidth - Preferred width of the icon.
	//      nIDResourceNormal - Normal state vector icon resource identified.
	//      nIDResourceDisabled - Disabled state vector icon resource identified.
	//      nIDResourceHot - Hot state vector icon resource identified.
	//      nIDResourceChecked - Checked state vector icon resource identified.
	//      nIDResourcePressed - Pressed state vector icon resource identified.
	//      lpIDResourceNormal - Normal state vector icon resource identified.
	//      lpIDResourceDisabled - Disabled state vector icon resource identified.
	//      lpIDResourceHot - Hot state vector icon resource identified.
	//      lpIDResourceChecked - Checked state vector icon resource identified.
	//      lpIDResourcePressed - Pressed state vector icon resource identified.
	//      hImageNormal - Pre-loaded normal state vector image handle.
	//      hImageDisabled - Pre-loaded disabled state vector image handle.
	//      hImageHot - Pre-loaded hot state vector image handle.
	//      hImageChecked - Pre-loaded checked state vector image handle.
	//      hImagePressed - Pre-loaded pressed state vector image handle.
	// Returns:
	//      TRUE if the vector icon image has been successfully added.
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(LPCTSTR lpResourceType, UINT nIDResource, UINT nIDCommand, UINT nWidth,
					   XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(LPCTSTR lpResourceType, LPCTSTR lpResource, UINT nIDCommand, UINT nWidth,
					   XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(HMODULE hModule, LPCTSTR lpResourceType, UINT nIDResource, UINT nIDCommand,
					   UINT nWidth, XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(HMODULE hModule, LPCTSTR lpResourceType, LPCTSTR lpResource, UINT nIDCommand,
					   UINT nWidth, XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(CXTPImageManagerVectorImageHandle hImage, UINT nIDCommand, UINT nWidth,
					   XTPImageState imageState = xtpImageNormal);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(LPCTSTR lpResourceType, UINT nIDResourceNormal, UINT nIDResourceDisabled,
					   UINT nIDResourceHot, UINT nIDResourceChecked, UINT nIDResourcePressed,
					   UINT nIDCommand, UINT nWidth);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(LPCTSTR lpResourceType, LPCTSTR lpIDResourceNormal,
					   LPCTSTR lpIDResourceDisabled, LPCTSTR lpIDResourceHot,
					   LPCTSTR lpIDResourceChecked, LPCTSTR lpIDResourcePressed, UINT nIDCommand,
					   UINT nWidth);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(HMODULE hModule, LPCTSTR lpResourceType, UINT nIDResourceNormal,
					   UINT nIDResourceDisabled, UINT nIDResourceHot, UINT nIDResourceChecked,
					   UINT nIDResourcePressed, UINT nIDCommand, UINT nWidth);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(HMODULE hModule, LPCTSTR lpResourceType, LPCTSTR lpIDResourceNormal,
					   LPCTSTR lpIDResourceDisabled, LPCTSTR lpIDResourceHot,
					   LPCTSTR lpIDResourceChecked, LPCTSTR lpIDResourcePressed, UINT nIDCommand,
					   UINT nWidth);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::SetVectorIcon@LPCTSTR@UINT@UINT@XTPImageState>
	// --------------------------------------------------------------------------------------------
	BOOL SetVectorIcon(CXTPImageManagerVectorImageHandle hImageNormal,
					   CXTPImageManagerVectorImageHandle hImageDisabled,
					   CXTPImageManagerVectorImageHandle hImageHot,
					   CXTPImageManagerVectorImageHandle hImageChecked,
					   CXTPImageManagerVectorImageHandle hImagePressed, UINT nIDCommand,
					   UINT nWidth);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to set the color mask of the bitmaps that will be added.
	// Parameters:
	//     clrMask - Mask color to be set.
	// Returns:
	//     Previous color mask.
	//-----------------------------------------------------------------------
	COLORREF SetMaskColor(COLORREF clrMask);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves color mask.
	// Returns:
	//     Current color mask.
	//-----------------------------------------------------------------------
	COLORREF GetMaskColor() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Mirrors images around the y-axis, useful in RTL (Right-To-Left) Languages.
	// Parameters:
	//     bDrawReverted - If TRUE, images are "flipped" or Mirrored.
	//                     This should be used when displaying images in an
	//                     application that uses RTL (Right-To-Left) Languages.
	//-----------------------------------------------------------------------
	void DrawReverted(BOOL bDrawReverted);

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes all icons.
	//-----------------------------------------------------------------------
	void RemoveAll();

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes the specified icon.
	// Parameters:
	//     nIDCommand - Id of icon to be removed
	//-----------------------------------------------------------------------
	void RemoveIcon(UINT nIDCommand);

	//-----------------------------------------------------------------------
	// Summary:
	//     Redraws all icons.
	//-----------------------------------------------------------------------
	void RefreshAll();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method used by CommandBars to add custom icons
	// Parameters:
	//     hIcon - Icon Handler to be added
	// Returns:
	//     Identifier of new added icon.
	//-----------------------------------------------------------------------
	UINT AddCustomIcon(const CXTPImageManagerIconHandle& hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons with the specified Id and width.
	// Parameters:
	//     nCommand - ID of the icon to be retrieved
	//     nWidth - Width of the icon to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerIcon
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon* GetImage(UINT nCommand, int nWidth = 16) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to determine if non scaled image exists in image manager
	// Parameters:
	//     nCommand - Image identifier to check
	//     nWidth - Image width to check
	// Returns:
	//     TRUE if image non scaled image exists.
	// See Also: GetImage
	//-----------------------------------------------------------------------
	BOOL IsPrimaryImageExists(UINT nCommand, int nWidth) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons set with the specified Id.
	// Parameters:
	//     nCommand - ID of the icon set to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerIconSet object
	//-----------------------------------------------------------------------
	CXTPImageManagerIconSet* GetIconSet(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons set with the specified Id from an image list.
	// Parameters:
	//     nCommand - ID of the icon set to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerImageList object
	//-----------------------------------------------------------------------
	CXTPImageManagerImageList* GetImageList(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves a collection of images.
	// Returns:
	//     A CMap object
	//-----------------------------------------------------------------------
	CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*>* GetImages();

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if icons set exists with the specified ID.
	// Parameters:
	//     nCommand - Identifier needed to check.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL Lookup(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the icons are drawn mirrored\reverted.
	// Returns:
	//     TRUE if icons are drawn reverted; FALSE if drawn normal.
	//-----------------------------------------------------------------------
	BOOL IsDrawReverted() const;
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::IsDrawReverted>
	// --------------------------------------------------------------------------------------------
	BOOL IsDrawReverted(CDC* pDC) const;

	//-----------------------------------------------------------------------
	// Summary:
	//      Returns resources for specified size
	// Parameters:
	//     szIcon - Size for resources to retrieve
	// Returns:
	//     Returns pointer to CXTPImageManagerResource contained all icons of specified size
	//-----------------------------------------------------------------------
	CXTPImageManagerResource* GetResource(CSize szIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes icons from or to an archive.
	// Parameters:
	//     nCommand - Specified command to serialize.
	//     ar - A CArchive object to serialize to or from.
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//-----------------------------------------------------------------------
	void Serialize(CArchive& ar);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::Serialize@CArchive&amp;>
	// --------------------------------------------------------------------------------------------
	void Serialize(UINT nCommand, CArchive& ar);

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes icons from or to an archive.
	// Parameters:
	//     nCommand - Specified command to serialize.
	//     ar - A CArchive object to serialize to or from.
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//-----------------------------------------------------------------------
	void DoPropExchange(CXTPPropExchange* pPX);
	// --------------------------------------------------------------------------------------------
	// <combine CXTPImageManager::DoPropExchange@CXTPPropExchange*>
	// --------------------------------------------------------------------------------------------
	void DoPropExchange(UINT nCommand, CXTPPropExchange* pPX);

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource has alpha channel.
	// Parameters:
	//     nIDResourceBitmap - Resource identifier of the bitmap to check.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapResource(UINT nIDResourceBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if nIDResourceBitmap resource contains PNG image
	// Parameters:
	//     nIDResourceBitmap - Id of resources to check
	// Returns:
	//     TRUE if resources contains PNG image
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsPngBitmapResource(UINT nIDResourceBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if the OS supports alpha icons.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	// See Also: IsAlphaIconsImageListSupported
	//-----------------------------------------------------------------------
	BOOL IsAlphaIconsSupported() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if the OS supports alpha image list.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// See Also: IsAlphaIconsSupported
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaIconsImageListSupported();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves color of top-left pixel.
	// Parameters:
	//     bmp       - CBitmap reference.
	//     nIDBitmap - Bitmap identifier.
	//     pt        - location of pixel to retrieve.
	// Returns:
	//     COLORREF that will be used as transparent color.
	//-----------------------------------------------------------------------
	static COLORREF AFX_CDECL GetBitmapMaskColor(CBitmap& bmp, CPoint pt = 0);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::GetBitmapMaskColor@CBitmap&amp;@CPoint>
	//-----------------------------------------------------------------------
	static COLORREF AFX_CDECL GetBitmapMaskColor(UINT nIDBitmap, CPoint pt = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method creates 24bit bitmap from 32bit alpha bitmaps to draw it in old OSes
	// Parameters:
	//     bmpAlpha - Resource bitmap identifier.
	//     clrMask  - Mask color to be used
	//     nIDBitmap - Resource bitmap identifier.
	// Returns:
	//     Reduced bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL ResampleAlphaLayer(HBITMAP bmpAlpha, COLORREF clrMask);
	//-----------------------------------------------------------------------
	// <combine CXTPImageManager::ResampleAlphaLayer@HBITMAP@COLORREF>
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL ResampleAlphaLayer(UINT nIDBitmap, COLORREF clrMask);

	//-----------------------------------------------------------------------
	// Summary:
	//     The TransparentBlt function performs a bit-block transfer of the color data corresponding
	//     to a rectangle of pixels from the specified source device context into a destination
	//     device context.
	// Parameters:
	//     hdcDest - handle to destination DC
	//     rcDest - destination rectangle
	//     hdcSrc - handle to source DC
	//     rcSrc - source rectangle
	//     crTransparent - color to make transparent
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: AlphaBlend
	//-----------------------------------------------------------------------
	BOOL TransparentBlt(HDC hdcDest, const CRect& rcDest, HDC hdcSrc, const CRect& rcSrc,
						UINT crTransparent) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.
	// Parameters:
	//     hdcDest - handle to destination DC
	//     rcDest - destination rectangle
	//     hdcSrc - handle to source DC
	//     rcSrc - source rectangle
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: TransparentBlt
	//-----------------------------------------------------------------------
	BOOL AlphaBlend(HDC hdcDest, const CRect& rcDest, HDC hdcSrc, const CRect& rcSrc) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.
	// Parameters:
	//     hdcDest - handle to destination DC
	//     rcDest - destination rectangle
	//     hdcSrc - handle to source DC
	//     rcSrc - source rectangle
	//     Transparency - Transparency for whole image to draw
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: TransparentBlt
	//-----------------------------------------------------------------------
	BOOL AlphaBlend2(HDC hdcDest, const CRect& rcDest, HDC hdcSrc, const CRect& rcSrc,
					 BYTE Transparency) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This function make a rectangle on device context as disabled.
	// Parameters:
	//     hDC              - A handle to DC
	//     rcRect           - A rectangle to be disabled
	//     clrDisabledLight - The lightest color of icon to generate
	//     clrDisabledDark  - The darkest color of icon to generate
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: BlackWhiteBitmap
	//-----------------------------------------------------------------------
	BOOL DisableBitmap(HDC hDC, const CRect& rcRect, COLORREF clrDisabledLight = (COLORREF)-1,
					   COLORREF clrDisabledDark = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     This function make a rectangle on device context as gray scale.
	// Parameters:
	//     hDC                    - A handle to DC
	//     rcRect                 - A rectangle to be disabled
	//     nBlackAndWhiteContrast - Black-white contrast as integer from 0 to 255
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: DisableBitmap
	//-----------------------------------------------------------------------
	BOOL BlackWhiteBitmap(HDC hDC, const CRect& rcRect, int nBlackAndWhiteContrast = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     This helper method creates 32bit bitmap
	// Parameters:
	//     hDC - Pointer to valid context (can be NULL)
	//     iWidth - Width of bitmap
	//     iHeight - Height of bitmap
	//     lpBits - Pointer to bits to return
	// Returns:
	//     Bitmap handle was created.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL Create32BPPDIBSection(HDC hDC, int iWidth, int iHeight,
												   LPBYTE* lpBits = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method adds all icons from resources with specified size
	// Parameters:
	//     hInst - Module instance to load icons from
	//     lpszResourceName - Icon resource identifier
	//     nIDCommand - Command to assign for the icon
	//     szIcon - Size of icon to load (0 to load all formats)
	//     imageState - Image state to assign for the icon
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	//-----------------------------------------------------------------------
	BOOL SetIconFromResource(HINSTANCE hInst, LPCTSTR lpszResourceName, UINT nIDCommand,
							 CSize szIcon, XTPImageState imageState);

	//-----------------------------------------------------------------------
	// Summary:
	//     Fall back for systems without MSIMG32.DLL
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL McTransparentBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest,
										   int nWidthDest, int nHeightDest, HDC hdcSrc,
										   int nXOriginSrc, int nYOriginSrc, int nWidthSrc,
										   int nHeightSrc, UINT crTransparent);

private:
	BOOL LoadToolbar(UINT nIDResourceToolBar, UINT*& pItems, int& nCount, CSize& szIcon) const;

	UINT PasteCustomImage(COleDataObject& data);
	void CopyImage(UINT nCommand);
	BOOL SplitBitmap(HBITMAP hbmSource, int nCount, HBITMAP* pDest) const;
	BOOL IsWindow2000() const;
	BOOL BitmapsCompatible(LPBITMAP lpbm1, LPBITMAP lpbm2) const;

	BOOL BlendImages(HBITMAP hbmSrc1, BOOL bRTL1, HBITMAP hbmSrc2, BOOL bRTL2,
					 HBITMAP hbmDst) const;
	BOOL DoAlphaBlend(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest,
					  int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc,
					  int nHeightSrc) const;
	BOOL DoDisableBitmap(HBITMAP hBmp, COLORREF clrDisabledLight = (COLORREF)-1,
						 COLORREF clrDisabledDark = (COLORREF)-1, int nBlackAndWhiteContrast = -1);

	BOOL ResourceToStream(HMODULE hModule, LPCTSTR lpResource, LPCTSTR lpResourceType,
						  IStream** ppStream);
	BOOL FileToStream(LPCTSTR path, IStream** ppStream);
	BOOL SetVectorIcon(IStream* pStream, UINT nIDCommand, UINT nWidth, XTPImageState imageState);

public:
	static double m_dDisabledBrightnessFactor; // Brightness factor of disabled icons.
	static double m_dDisabledAlphaFactor;	  // Alpha factor of disabled icons.
	static BOOL m_bAutoResample; // TRUE to automatically re-sample alpha bitmaps if msimg32 not
								 // found.
	static CLIPFORMAT m_nImageClipFormat; // Clipboard format of icons.
	static CLIPFORMAT m_nAlphaClipFormat; // Clipboard format of icons.
	BOOL m_bUseResources;				  // TRUE to create single bitmap for all icons

private:
	COLORREF m_clrMask;
	CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*> m_mapImages;
	CArray<CXTPImageManagerImageList*, CXTPImageManagerImageList*> m_arrImageList;
	CMap<DWORD, DWORD, CXTPImageManagerResource*, CXTPImageManagerResource*> m_mapResources;

	UINT m_nCustomID;
	BOOL m_bDrawReverted;

private:
	friend _XTP_EXT_CLASS CXTPImageManager* AFX_CDECL XTPImageManager();
	friend class CXTPCustomizeSheet;
	friend class CXTPImageManagerIcon;
	friend class CXTPImageManagerIconHandle;

	//{{AFX_CODEJOCK_PRIVATE
public:
	static CXTPImageManager* AFX_CDECL FromDispatch(LPDISPATCH pDisp);

#	ifdef _XTP_ACTIVEX
	/*  x64 #ifdef below is a fix for OLE_HANDLE. While HBITMAP/HICON are still 32-bit on 64-bit
	   Windows, OLE_HANDLE (long) can still be used. But OLE_HANDLE cannot be used as HMODULE which
	   is always 64-bit
	*/

#		ifndef _WIN64
#			define MODULE_HANDLE OLE_HANDLE
#			define MODULE_HANDLE_TYPE VTS_I4
#			define GDI_HANDLE long
#			define GDI_HANDLE_TYPE VTS_I4
#		else
#			define MODULE_HANDLE LONG64
#			define MODULE_HANDLE_TYPE VTS_I8
#			define GDI_HANDLE LONG64
#			define GDI_HANDLE_TYPE VTS_I8
#		endif

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	DECLARE_OLETYPELIB_EX(CXTPImageManager);
	DECLARE_ENUM_VARIANTLIST(CXTPImageManager)

	afx_msg long OleGetCount();
	afx_msg void OleAddIcon(GDI_HANDLE Handle, long Command, long imageState);
	afx_msg void OleLoadIcon(LPCTSTR Path, long Command, long imageState);
	afx_msg void OleLoadBitmap(LPCTSTR Path, const VARIANT& Commands, long imageState);
	afx_msg void OleAddBitmap(GDI_HANDLE Handle, const VARIANT& Commands, long imageState,
							  BOOL bAlphaBitmap);
	afx_msg void OleAddIcons(LPDISPATCH lpImageManagerIcons);
	afx_msg LPDISPATCH OleGetImage(long Command, long Width);
	afx_msg void OleLoadBitmapFromResource(MODULE_HANDLE Module, long Resource,
										   const VARIANT& Commands, long imageState);
	afx_msg void OleLoadIconFromResource(MODULE_HANDLE Module, long Resource, long Command,
										 long imageState);
	afx_msg void OleDoPropExchange(LPDISPATCH lpPropExchage);

	afx_msg BOOL OleLoadVectorIcon(LPCTSTR Path, long nIDCommand, long nWidth,
								   XTPImageState imageState);
	afx_msg BOOL OleLoadVectorIconCode(LPCTSTR Code, long nIDCommand, long nWidth,
									   XTPImageState imageState);
	afx_msg BOOL OleLoadVectorIconFromResource(MODULE_HANDLE Module, LPCTSTR ResourceType,
											   long Resource, long nIDCommand, long nWidth,
											   XTPImageState imageState);

//}}AFX_CODEJOCK_PRIVATE
#	endif
};

//===========================================================================
// Summary:
//    CXTPTempColorMask class can be used to temporarily set the color mask
//    used by XTPImageManager when using images with different color masks.
//    When the destructor is called the default mask is reset for
//    XTPImageManager.
// Example:
//    The following example demonstrates using CXTPTempColorMask.
// <code>
//    // temporarily change the mask color.
//    CXTPTempColorMask mask(RGB(0,255,0));
//    XTPImageManager()->SetIcons(IDB_FAVORITES,
//        icons, _countof(icons) CSize(16,16));
//
//    // set another mask color, CXTPTempColorMask will handle resetting
//    // the default color mask when it is destroyed.
//    XTPImageManager()->SetMaskColor(RGB(255,0,255));
//    XTPImageManager()->SetIcons(IDR_TOOLBAR_MASKED,
//        buttons, _countof(buttons), CSize(16,16), xtpImageNormal);
// </code>
// See Also:
//    CXTPImageManager::GetMaskColor, CXTPImageManager::SetMaskColor,
//    CXTPPaintManagerColor::GetStandardColor
//========================================================================
class _XTP_EXT_CLASS CXTPTempColorMask
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPTempColorMask object and initializes the
	//     application defined mask color and saves the default mask color
	//     used by XTPImageManager.
	// Parameters:
	//     crNewMask - An RGB value that represents the new color mask value used
	//                 by XTPImageManager.
	//-----------------------------------------------------------------------
	CXTPTempColorMask(COLORREF crNewMask);
	//-----------------------------------------------------------------------
	// <combine CXTPTempColorMask::CXTPTempColorMask@COLORREF>
	//-----------------------------------------------------------------------
	CXTPTempColorMask(CXTPImageManager* pImageManager, COLORREF crNewMask);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destructor for CXTPTempColorMask. Resets the default mask color
	//     used by XTPImageManager back to its original color value.
	//-----------------------------------------------------------------------
	~CXTPTempColorMask();

private:
	COLORREF m_crMask;
	CXTPImageManager* m_pImageManager;
};

//===========================================================================
// Summary:
//     XTPImageManager returns pointer to common CXTPImageManager class
// Returns:
//     Returns pointer to common CXTPImageManager class
// See Also:
//    CXTPImageManager
//===========================================================================
_XTP_EXT_CLASS CXTPImageManager* AFX_CDECL XTPImageManager();

//////////////////////////////////////////////////////////////////////////

AFX_INLINE CXTPImageManagerIconHandle::operator HICON() const
{
	return m_hIcon;
}

AFX_INLINE CXTPImageManagerImageList* CXTPImageManagerIcon::GetImageList()
{
	return m_pImageList;
}

AFX_INLINE const CXTPImageManagerImageList* CXTPImageManagerIcon::GetImageList() const
{
	return m_pImageList;
}

AFX_INLINE UINT CXTPImageManagerIconSet::GetID() const
{
	return m_nID;
}

AFX_INLINE BOOL CXTPImageManagerIcon::IsScaled() const
{
	return FALSE;
}

AFX_INLINE CXTPImageManagerVectorImageHandle CXTPImageManagerIcon::GetVectorCheckedIcon() const
{
	return GetVectorIcon(xtpImageChecked);
}

AFX_INLINE CXTPImageManagerVectorImageHandle CXTPImageManagerIcon::GetVectorPressedIcon() const
{
	return GetVectorIcon(xtpImagePressed);
}

AFX_INLINE CXTPImageManagerVectorImageHandle CXTPImageManagerIcon::GetVectorHotIcon() const
{
	return GetVectorIcon(xtpImageHot);
}

AFX_INLINE CXTPImageManagerVectorImageHandle CXTPImageManagerIcon::GetVectorDisabledIcon() const
{
	return GetVectorIcon(xtpImageDisabled);
}

AFX_INLINE BOOL CXTPImageManagerIcon::SetVectorDisabledIcon(CXTPImageManagerVectorImageHandle hIcon)
{
	return SetVectorIcon(hIcon, xtpImageDisabled);
}

AFX_INLINE BOOL CXTPImageManagerIcon::SetVectorHotIcon(CXTPImageManagerVectorImageHandle hIcon)
{
	return SetVectorIcon(hIcon, xtpImageHot);
}

AFX_INLINE BOOL CXTPImageManagerIcon::SetVectorCheckedIcon(CXTPImageManagerVectorImageHandle hIcon)
{
	return SetVectorIcon(hIcon, xtpImageChecked);
}

AFX_INLINE BOOL CXTPImageManagerIcon::SetVectorPressedIcon(CXTPImageManagerVectorImageHandle hIcon)
{
	return SetVectorIcon(hIcon, xtpImagePressed);
}

AFX_INLINE BOOL CXTPImageManagerIcon::IsRasterIcon() const
{
	return RasterIcon == m_nType;
}

AFX_INLINE BOOL CXTPImageManagerIcon::IsVectorIcon() const
{
	return VectorIcon == m_nType;
}

AFX_INLINE BOOL CXTPImageManagerIcon::IsUndefinedIcon() const
{
	return UndefinedIcon == m_nType;
}

AFX_INLINE CXTPImageManagerIconSet::CIconSetMap* CXTPImageManagerIconSet::GetIcons()
{
	return &m_mapIcons;
}

AFX_INLINE CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*>*
	CXTPImageManager::GetImages()
{
	return &m_mapImages;
}

AFX_INLINE void CXTPImageManager::DrawReverted(BOOL bDrawReverted)
{
	m_bDrawReverted = bDrawReverted;
}

AFX_INLINE BOOL CXTPImageManager::IsDrawReverted() const
{
	return m_bDrawReverted;
}

AFX_INLINE CXTPTempColorMask::CXTPTempColorMask(COLORREF crNewMask)
{
	m_pImageManager = XTPImageManager();
	m_crMask		= m_pImageManager->SetMaskColor(crNewMask);
}

AFX_INLINE CXTPTempColorMask::CXTPTempColorMask(CXTPImageManager* pImageManager, COLORREF crNewMask)
{
	m_pImageManager = pImageManager;
	m_crMask		= m_pImageManager->SetMaskColor(crNewMask);
}

AFX_INLINE CXTPTempColorMask::~CXTPTempColorMask()
{
	m_pImageManager->SetMaskColor(m_crMask);
}

//-----------------------------------------------------------------------
// Summary:
//      Scales bitmap image to the current DPI level.
// Parameters:
//      src - Source bitmap pointer.
//      dst - Destination bitmap pointer.
// Returns:
//      TRUE if the source bitmap is successfully scaled to the destination bitmap object.
//-----------------------------------------------------------------------
BOOL AFX_CDECL ScaleBitmap(CBitmap* src, CBitmap* dst);

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif //#if !defined(__XTPIMAGEMANAGER_H__)

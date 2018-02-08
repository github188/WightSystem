// SkinHeaderCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Weight.h"
#include "SkinHeaderCtrl.h"
#include <atlbase.h>
#include <atlimage.h>

// CSkinHeaderCtrl

IMPLEMENT_DYNAMIC(CSkinHeaderCtrl, CHeaderCtrl)

CSkinHeaderCtrl::CSkinHeaderCtrl()
{

}

CSkinHeaderCtrl::~CSkinHeaderCtrl()
{
}


BEGIN_MESSAGE_MAP(CSkinHeaderCtrl, CHeaderCtrl)
	ON_MESSAGE(HDM_LAYOUT,OnLayout)
	ON_WM_PAINT()
	//ON_NOTIFY(HDN_ITEMCHANGEDA, 0, &CSkinHeaderCtrl::OnHdnItemchanged)
	//ON_NOTIFY(HDN_ITEMCHANGEDW, 0, &CSkinHeaderCtrl::OnHdnItemchanged)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CSkinHeaderCtrl message handlers
void CSkinHeaderCtrl::SetItemSortState(int iItem, UINT sortState)
{
	ASSERT(sortState == _nSortUp || sortState == _nSortUp || sortState == _nSortDown);
	ASSERT(m_hWnd != NULL && IsWindow(m_hWnd));

	int nItemCount = GetItemCount();
	ASSERT(iItem >= 0 && iItem < nItemCount);

	HDITEM hditem;
	hditem.mask = HDI_FORMAT;
	GetItem(iItem, &hditem);

	if (sortState == _nSortUp)
	{
		hditem.fmt &= ~HDF_SORTDOWN;
		hditem.fmt |= HDF_SORTUP;
	}
	else
	{
		hditem.fmt &= ~HDF_SORTUP;
		hditem.fmt |= HDF_SORTDOWN;
	}
	SetItem(iItem, &hditem);

	CRect rect;
	GetItemRect(iItem, &rect);
	InvalidateRect(&rect);
}

UINT CSkinHeaderCtrl::GetItemSortState(int iItem)
{
	ASSERT(m_hWnd != NULL && IsWindow(m_hWnd));
	int nItemCount = GetItemCount();
	ASSERT(iItem >= 0 && iItem < nItemCount);

	HDITEM hditem;
	hditem.mask = HDI_FORMAT;
	GetItem(iItem, &hditem);

	if (hditem.fmt & HDF_SORTUP)
	{
		return _nSortUp;
	}
	else if (hditem.fmt & HDF_SORTDOWN)
	{
		return _nSortDown;
	}
	else
	{
		return _nSortNone;
	}
}

LRESULT CSkinHeaderCtrl::OnLayout(WPARAM wParam,LPARAM lParam)
{
	LRESULT lResult = CHeaderCtrl::DefWindowProc(HDM_LAYOUT, 0, lParam); 
	HD_LAYOUT &hdl = *(HD_LAYOUT *) lParam; 
	RECT *prc = hdl.prc; 
	WINDOWPOS *pwpos = hdl.pwpos; 
	pwpos->cy = 22; 
	prc->top = 22;
	return lResult;
}

void CSkinHeaderCtrl::Init()
{
	ModifyStyle(0, HDS_FLAT);
}

void CSkinHeaderCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	DoPaint(&dc);
}

void CSkinHeaderCtrl::DoPaint(CDC *pDC)
{
	CRect rect, rcItem;
	GetClientRect(&rect);
	
	CDC memDC;
	CBitmap bmp;
	memDC.CreateCompatibleDC(pDC);
	bmp.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
	memDC.SelectObject(&bmp);

	memDC.SetBkMode(TRANSPARENT);
	memDC.SetTextColor(RGB(0, 0, 0));
	memDC.SetStretchBltMode(HALFTONE);

	LOGFONT logfont;
	memset(&logfont, 0x0, sizeof(logfont));
	logfont.lfHeight = 12;
	logfont.lfWeight = FW_NORMAL;
	logfont.lfCharSet = GB2312_CHARSET;
	_tcscpy_s(logfont.lfFaceName, LF_FACESIZE, _T("ËÎÌå"));

	CFont font;
	font.CreateFontIndirect(&logfont);
	memDC.SelectObject(&font);

	// Ìî³ä±³¾°
	CImage image;
	image.LoadFromResource(AfxGetResourceHandle(), IDB_HEADERCTRL_SPAN_NORMAL);
	image.Draw(memDC, rect);
	image.Destroy();

	int nItems = GetItemCount();
	for (int i = 0; i < nItems; ++i)
	{
		TCHAR buf[256];
		HDITEM hditem;

		hditem.mask = HDI_TEXT | HDI_FORMAT | HDI_ORDER;
		hditem.pszText = buf;
		hditem.cchTextMax = 255;
		GetItem(i, &hditem);
		GetItemRect(i, &rcItem);

		if (rcItem.IsRectEmpty())
		{
			continue;
		}

		// »­·Ö¸îÏß
		image.LoadFromResource(AfxGetResourceHandle(), IDB_HEADERCTRL_END_NORMAL);
		image.Draw(memDC, rcItem.right - 1, rcItem.top);
		image.Destroy();

		// »­ÎÄ×ÖºÍÅÅÐò¼ýÍ·
		UINT uFormat = DT_SINGLELINE | DT_VCENTER | DT_NOPREFIX;
		if (hditem.fmt & HDF_RIGHT)
		{
			uFormat |= DT_RIGHT;
		}
		else if (hditem.fmt & HDF_CENTER)
		{
			uFormat |= DT_CENTER;
		}

		CRect rcText = rcItem;
		if ((hditem.fmt & HDF_SORTUP) | (hditem.fmt & HDF_SORTDOWN))
		{
			rcText.DeflateRect(5, 1, 13, 1);
			memDC.DrawText(buf, static_cast<int> (_tcslen(buf)), &rcText, uFormat);
		}
		else
		{
			rcText.DeflateRect(5, 1, 5, 1);
			memDC.DrawText(buf, static_cast<int>(_tcslen(buf)), &rcText, uFormat);
		}
	}

	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
}

void CSkinHeaderCtrl::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
    Init();
	CHeaderCtrl::PreSubclassWindow();
}

void CSkinHeaderCtrl::OnHdnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	//Invalidate();
	*pResult = 0;
}

BOOL CSkinHeaderCtrl::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
    return TRUE;
	return CHeaderCtrl::OnEraseBkgnd(pDC);
}

void CSkinHeaderCtrl::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{
     Invalidate();
	// TODO:  Add your code to draw the specified item
}

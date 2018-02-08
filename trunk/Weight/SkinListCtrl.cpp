// SkinListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SkinListCtrl.h"


// CSkinListCtrl

IMPLEMENT_DYNAMIC(CSkinListCtrl, CListCtrl)

CSkinListCtrl::CSkinListCtrl()
{
   LIST_ITEM_HEIGHT = 15;
   nLockColume = 0;
   nLockRow = 0;
}

CSkinListCtrl::~CSkinListCtrl()
{
}


BEGIN_MESSAGE_MAP(CSkinListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CSkinListCtrl::OnNMCustomdraw)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CSkinListCtrl::OnLvnItemchanged)
	ON_NOTIFY(HDN_ITEMCHANGEDA, 0, &CSkinListCtrl::OnHdnItemchanged)
	ON_NOTIFY(HDN_ITEMCHANGEDW, 0, &CSkinListCtrl::OnHdnItemchanged)
	ON_NOTIFY_REFLECT(LVN_ENDSCROLL, &CSkinListCtrl::OnLvnEndScroll)
END_MESSAGE_MAP()



// CSkinListCtrl message handlers

void CSkinListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMLVCUSTOMDRAW lpnmcd = (LPNMLVCUSTOMDRAW) pNMHDR;
	if (lpnmcd ->nmcd.dwDrawStage == CDDS_PREPAINT)
	{
		*pResult =  CDRF_NOTIFYITEMDRAW | CDRF_NOTIFYPOSTPAINT;
		return;
	}
	else if (lpnmcd->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)
	{
		CRect rSubItem, rectClient;
		int nColumnCount = GetHeaderCtrl()->GetItemCount();
		if (nColumnCount>0)
		{
			GetSubItemRect(lpnmcd->nmcd.dwItemSpec,nColumnCount-1, LVIR_LABEL,rSubItem);
			GetClientRect(&rectClient);	
			rSubItem.left = rSubItem.right;
			rSubItem.right = rectClient.right;
			rSubItem.NormalizeRect();
			bool bSelected = false;
			if (GetItemState(lpnmcd->nmcd.dwItemSpec, LVIS_SELECTED))
			{
				bSelected = true;
			}

			bool bFocus = false;
			HWND hWndFocus = ::GetFocus();
			if (::IsChild(m_hWnd,hWndFocus) || m_hWnd == hWndFocus)
			{
				bFocus = true;
			}
			CDC dc;
			dc.Attach(lpnmcd->nmcd.hdc);
			draw_row_bg(&dc, rSubItem, bSelected, bFocus, (int)lpnmcd->nmcd.dwItemSpec, (int)lpnmcd->iSubItem);
			dc.Detach();
		}

		*pResult =  CDRF_NOTIFYSUBITEMDRAW;
		return;
	}
	else if (lpnmcd ->nmcd.dwDrawStage == (CDDS_SUBITEM | CDDS_ITEMPREPAINT))
	{
		int iItem = lpnmcd->nmcd.dwItemSpec;
		int iSubItem = lpnmcd->iSubItem;
		if (iItem >= 0 && iSubItem >= 0)
		{
			CRect rSubItem;
			HDC hDC = lpnmcd->nmcd.hdc;
			GetSubItemRect(iItem, iSubItem, LVIR_LABEL,rSubItem);
			if (iSubItem == 0)
			{
				rSubItem.left = 0;
			}
			
			bool bSelected = false;
			if (GetItemState(iItem, LVIS_SELECTED))
			{
				bSelected = true;
			}

			bool bFocus = false;
			CWnd *pWndFocus = GetFocus();
			if (IsChild(pWndFocus) || pWndFocus == this)
			{
				bFocus = true;
			}

			rSubItem.NormalizeRect();
			CDC dc;
			dc.Attach(lpnmcd->nmcd.hdc);
			DrawSubItem(&dc,iItem,iSubItem,rSubItem,bSelected,bFocus);
			dc.Detach();
			*pResult =  CDRF_SKIPDEFAULT;
			return;
		}
	}
	else if (lpnmcd ->nmcd.dwDrawStage == CDDS_POSTPAINT)
	{
		DrawRemainSpace(lpnmcd);
		*pResult =  CDRF_SKIPDEFAULT;
		return;
	}
	 
	*pResult = 0;

}

// overwrite:
void CSkinListCtrl::DrawSubItem(CDC *pDC, int nItem, int nSubItem, CRect &rSubItem, bool bSelected, bool bFocus)
{


	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0, 0, 0));

	CFont font;
	font.CreateFont(12,   // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("宋体"));
	pDC->SelectObject(&font);

	CString strText;
	strText = GetItemText(nItem, nSubItem);
	draw_row_bg(pDC, rSubItem, bSelected, bFocus, nItem, nSubItem);
	pDC->DrawText(strText, strText.GetLength(), &rSubItem, DT_SINGLELINE | DT_RIGHT | DT_VCENTER | DT_END_ELLIPSIS);
  
}

// 画剩余部分
void CSkinListCtrl::DrawRemainSpace(LPNMLVCUSTOMDRAW lpnmcd)
{
	int nTop = lpnmcd->nmcd.rc.top;
	int nCount = GetItemCount();
	int i, j;
	if (nCount > 0)
	{
		CRect rcItem;
		GetItemRect(nCount - 1, &rcItem, LVIR_LABEL);
		nTop = rcItem.bottom;
	}

	CRect rectClient;
	GetClientRect(&rectClient);
	if (nTop < lpnmcd->nmcd.rc.bottom) // 有剩余
	{
		CRect rcRemain = lpnmcd->nmcd.rc;
		rcRemain.top = nTop;
		rcRemain.right = rectClient.right;
		int nRemainItem = rcRemain.Height() / LIST_ITEM_HEIGHT;
		if (rcRemain.Height() % LIST_ITEM_HEIGHT)
		{
			nRemainItem++;
		}

		int pos = GetScrollPos(SB_HORZ);
		CDC dc;
		dc.Attach(lpnmcd->nmcd.hdc);
		int nColumnCount = GetHeaderCtrl()->GetItemCount();
		CRect  rcSubItem;
		CRect rcItem;
		for (i = 0; i < nRemainItem; ++i)
		{
			
			rcItem.top = rcRemain.top + i * LIST_ITEM_HEIGHT;
			rcItem.left = rcRemain.left;
			rcItem.right = rcRemain.right;
			rcItem.bottom = rcItem.top + LIST_ITEM_HEIGHT;
			for (j = 0; j < nColumnCount; ++j)
			{
				GetHeaderCtrl()->GetItemRect(j, &rcSubItem);
				rcSubItem.top = rcItem.top;
				rcSubItem.bottom = rcItem.bottom;
				rcSubItem.OffsetRect(-pos, 0);
				if(rcSubItem.right < rcRemain.left || rcSubItem.left > rcRemain.right)
					continue;
				draw_row_bg(&dc, rcSubItem, false, false, i + nCount, j);
			}
			if (rcSubItem.right<rectClient.right)
			{
				rcSubItem.left=rcSubItem.right;
				rcSubItem.right=rectClient.right;
				draw_row_bg(&dc, rcSubItem, false, false, i + nCount, j);
			}

		}

		dc.Detach();
	}
}

void CSkinListCtrl::draw_row_bg(CDC *pDC, RECT rc, bool bSelected, bool bFocus, int nRow, int nColumn)
{ 

	bool bOdd = (nRow % 2 == 0 ? true : false);

	CRect rect = rc;
	if (rect.Width() == 0)
	{
		return;
	}
     
	draw_row_bg(pDC, rc, bSelected, bFocus, nRow, nColumn, bOdd);
}

void CSkinListCtrl::draw_row_bg(CDC *pDC, RECT rc, bool bSelected, bool bFocus, int nRow, int nColumn, bool bOdd)
{
	CRect rect = rc;
	if (rect.Width() == 0)
	{
		return;
	}

	int nSave = pDC->SaveDC();
	if (nColumn < nLockColume || nRow < nLockRow)
	{
			CBrush selectBrush;
			selectBrush.CreateSolidBrush(RGB(127, 127, 127));
			pDC->FillRect(&rc, &selectBrush);

			// 画竖线
			CPen pen;
			pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

			pDC->SelectObject(&pen);
			pDC->MoveTo(rc.right - 1, rc.top);
			pDC->LineTo(rc.right - 1, rc.bottom);

			CPen bottomPen;
			bottomPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

			pDC->SelectObject(&bottomPen);
			pDC->MoveTo(rc.left, rc.bottom - 1);
			pDC->LineTo(rc.right, rc.bottom - 1);

			return;
	}
	else if (bSelected)
	{
		if (bFocus)
		{
			CBrush selectBrush;
			selectBrush.CreateSolidBrush(RGB(203, 223, 239));
			pDC->FillRect(&rc, &selectBrush);

		}
		else
		{
			CBrush selectNoFocusBrush;
			selectNoFocusBrush.CreateSolidBrush(RGB(206, 206, 206));
			pDC->FillRect(&rc, &selectNoFocusBrush);
		}
	}
	else if (bOdd)
	{
		CBrush oddBrush;
		oddBrush.CreateSolidBrush(RGB(255, 255, 255));
		pDC->FillRect(&rc, &oddBrush);

	}
	else
	{
		CBrush normalBrush;
		normalBrush.CreateSolidBrush(RGB(243, 243, 243));
		pDC->FillRect(&rc, &normalBrush);
	}

	// 重绘第一列的背景色
// 	CBrush normalBrush;
// 	normalBrush.CreateSolidBrush(RGB(0, 0, 0));
// 	pDC->FillSolidRect(rc.right)
// 	pDC->FillRect(&rc, &normalBrush);


	// 画竖线
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(218, 218, 218));

	pDC->SelectObject(&pen);
	pDC->MoveTo(rc.right - 1, rc.top);
	pDC->LineTo(rc.right - 1, rc.bottom);

	// 画选中的底部分割线
	//if (bSelected)
	{
		CPen bottomPen;
		bottomPen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));

		pDC->SelectObject(&bottomPen);
		pDC->MoveTo(rc.left, rc.bottom - 1);
		pDC->LineTo(rc.right, rc.bottom - 1);
	}

	pDC->RestoreDC(nSave);
}

void CSkinListCtrl::Init()
{
	CHeaderCtrl *pHeaderCtrl = GetHeaderCtrl();
	if (pHeaderCtrl!=NULL)
	{
		m_header.SubclassWindow(pHeaderCtrl->GetSafeHwnd());
	}
	LOGFONT logfont;
	memset(&logfont, 0, sizeof(logfont));
	logfont.lfWeight = FW_NORMAL;
	logfont.lfCharSet = GB2312_CHARSET;
	_tcscpy_s(logfont.lfFaceName, LF_FACESIZE, _T("宋体"));
	logfont.lfHeight = (LIST_ITEM_HEIGHT-1);   /*  */
	CFont font;
	font.CreateFontIndirect(&logfont);
	SetFont(&font);
	font.Detach();
}

void CSkinListCtrl::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	Invalidate();
	*pResult = 0;
}

void CSkinListCtrl::InvalidateItem(int nItem)
{
	CRect rcClient;
	GetClientRect(&rcClient);

	CRect rcItem;
	GetItemRect(nItem, &rcItem, LVIR_BOUNDS);

	rcItem.left = rcClient.left;
	rcItem.right = rcClient.right;
	InvalidateRect(&rcItem,FALSE);
}

void CSkinListCtrl::PreSubclassWindow()
{
    Init();
	CListCtrl::PreSubclassWindow();
}

void CSkinListCtrl::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{

}

void CSkinListCtrl::OnHdnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	Default();
	Invalidate();
	*pResult = 0;
}

void CSkinListCtrl::OnLvnEndScroll(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 此功能要求 Internet Explorer 5.5 或更高版本。
	// 符号 _WIN32_IE 必须是 >= 0x0560。
	LPNMLVSCROLL pStateChanged = reinterpret_cast<LPNMLVSCROLL>(pNMHDR);
	Invalidate();
	*pResult = 0;
}

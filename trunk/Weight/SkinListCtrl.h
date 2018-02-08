#pragma once
#include "SkinHeaderCtrl.h"

// CSkinListCtrl

class CSkinListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CSkinListCtrl)
public:
	unsigned int LIST_ITEM_HEIGHT;
	unsigned int nLockColume;
	unsigned int nLockRow;
public:
	CSkinListCtrl();
	virtual ~CSkinListCtrl();

protected:
	DECLARE_MESSAGE_MAP()
protected:
	void Init();
	virtual void DrawSubItem(CDC *pDC, int nItem, int nSubItem, CRect &rSubItem, bool bSelected, bool bFocus);
	virtual void DrawRemainSpace(LPNMLVCUSTOMDRAW lpnmcd);
	virtual void draw_row_bg(CDC *pDC, RECT rc, bool bSelected, bool bFocus, int nRow, int nColumn);
	virtual void draw_row_bg(CDC *pDC, RECT rc, bool bSelected, bool bFocus, int nRow, int nColumn, bool bOdd);
	void InvalidateItem(int nItem);
public:
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnEndScroll(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
private:
    CSkinHeaderCtrl m_header;
};



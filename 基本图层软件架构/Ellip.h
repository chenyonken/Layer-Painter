// Ellip.h: interface for the CEllip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLIP_H__3887A0CC_8B2E_483E_9D27_2985DD5173D7__INCLUDED_)
#define AFX_ELLIP_H__3887A0CC_8B2E_483E_9D27_2985DD5173D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CEllip : public CLayer  
{
public:
	CRect m_rect;
public:
	CEllip();
	virtual ~CEllip();
public:
	virtual void OnLButtonDblClk(UINT nFlags,CPoint point );
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnDraw(CDC* pDC);

	//ͼ���϶����̣�ѡ��ƽ�ƺ͸���
	virtual void Select(CPoint point);
	virtual void Offset(int x,int y);
	virtual BOOL Track(CPoint point);

};

#endif // !defined(AFX_ELLIP_H__3887A0CC_8B2E_483E_9D27_2985DD5173D7__INCLUDED_)

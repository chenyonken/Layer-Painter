// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__3783A3FA_9AC6_4B32_B4C8_7A68FA108342__INCLUDED_)
#define AFX_LINE_H__3783A3FA_9AC6_4B32_B4C8_7A68FA108342__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CLine : public CLayer  
{
public:
	CPoint m_pts,m_ptn;	//��¼�߶ε������յ�
	CPoint m_last;		//���ڼ�¼���ƹ���
public:
	CLine();
	virtual ~CLine();
public:
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnDraw(CDC* pDC);

	//ͼ���϶����̣�ѡ��ƽ�ƺ͸���
	virtual void Select(CPoint point);
	virtual void Offset(int x,int y);
	virtual BOOL Track(CPoint point);


};

#endif // !defined(AFX_LINE_H__3783A3FA_9AC6_4B32_B4C8_7A68FA108342__INCLUDED_)

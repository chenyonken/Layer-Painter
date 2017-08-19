// PolyLine.h: interface for the CPolyLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYLINE_H__1DD92421_6C7D_4EA6_A845_70D68A165F7F__INCLUDED_)
#define AFX_POLYLINE_H__1DD92421_6C7D_4EA6_A845_70D68A165F7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CPolyLine : public CLayer  
{
public:
	CArray<CPoint,CPoint> m_arr;

	CPoint m_LastPoint;
public:
	CPolyLine();
	virtual ~CPolyLine();
public:
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnDraw(CDC* pDC);

	//ͼ���϶����̣�ѡ��ƽ�ƺ͸���
	virtual void Select(CPoint point);//����ĳ��ͼ�㣬��ʾѡ��״̬
	virtual void Offset(int x,int y);//�϶�ͼ��
	virtual BOOL Track(CPoint point);//����ӹ�ͼ��ʱ�ı�����״

	virtual void OnLButtonDblClk(UINT nFlags,CPoint point );

};

#endif // !defined(AFX_POLYLINE_H__1DD92421_6C7D_4EA6_A845_70D68A165F7F__INCLUDED_)

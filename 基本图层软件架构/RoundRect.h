// RoundRect.h: interface for the CRoundRect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROUNDRECT_H__CAF3BC1C_5F67_452C_88CA_EF65964F8C27__INCLUDED_)
#define AFX_ROUNDRECT_H__CAF3BC1C_5F67_452C_88CA_EF65964F8C27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CRoundRect : public CLayer  
{
public:
	int m_degree;//Բ�ǵ�������
	CRect m_rtRoundRect;
public:
	CRoundRect();
	virtual ~CRoundRect();
public:
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnDraw(CDC* pDC);

	//ͼ���϶����̣�ѡ��ƽ�ƺ͸���
	virtual void Select(CPoint point);//����ĳ��ͼ�㣬��ʾѡ��״̬
	virtual void Offset(int x,int y);//�϶�ͼ��
	virtual BOOL Track(CPoint point);//����ӹ�ͼ��ʱ�ı�����״


};

#endif // !defined(AFX_ROUNDRECT_H__CAF3BC1C_5F67_452C_88CA_EF65964F8C27__INCLUDED_)

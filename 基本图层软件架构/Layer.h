// Layer.h: interface for the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAYER_H__8F836D74_4F9B_4B3D_A82C_4476A4FEA21E__INCLUDED_)
#define AFX_LAYER_H__8F836D74_4F9B_4B3D_A82C_4476A4FEA21E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum{
	STU_DRAWING,	//����״̬
	STU_NORMAL,		//��ͨ״̬
	STU_SELECT
	};	//ͼ�㱻ѡ��״̬
class CLayer  
{
public:
	int m_nStatus;		//ͼ��״̬
	COLORREF m_clText;	//ǰ��ɫ
	COLORREF m_clBack;	//����ɫ
public:
	CLayer();
	virtual ~CLayer();
public:
	static CLayer* Create(int nType);	//����ͼ��
	//��꼰��ʾ�¼�����
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL)=0;
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL)=0;
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL)=0;
	virtual void OnDraw(CDC* pDC)=0;

	//ͼ���϶����̣�ѡ��ƽ�ƺ͸���
	virtual void Select(CPoint point)=0;//����ĳ��ͼ�㣬��ʾѡ��״̬
	virtual void Offset(int x,int y)=0;//�϶�ͼ��
	virtual BOOL Track(CPoint point)=0;//����ӹ�ͼ��ʱ�ı�����״

	virtual void OnLButtonDblClk(UINT nFlags,CPoint point )=0;

};

#endif // !defined(AFX_LAYER_H__8F836D74_4F9B_4B3D_A82C_4476A4FEA21E__INCLUDED_)

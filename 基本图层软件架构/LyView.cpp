// LyView.cpp : implementation of the CLyView class
//

#include "stdafx.h"
#include "Ly.h"

#include "LyDoc.h"
#include "LyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLyView

IMPLEMENT_DYNCREATE(CLyView, CView)

BEGIN_MESSAGE_MAP(CLyView, CView)
	//{{AFX_MSG_MAP(CLyView)
	ON_COMMAND(ID_DRAW_DRAG, OnDrawDrag)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DRAG, OnUpdateDrawDrag)
	ON_COMMAND(ID_DRAW_ELLIP, OnDrawEllip)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIP, OnUpdateDrawEllip)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)
	ON_COMMAND(ID_DRAW_PEN, OnDrawPen)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PEN, OnUpdateDrawPen)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_COLOR, OnDrawColor)
	ON_COMMAND(ID_DRAW_RECTANGLE, OnDrawRectangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECTANGLE, OnUpdateDrawRectangle)
	ON_COMMAND(ID_DRAW_ROUNDRECT, OnDrawRoundrect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ROUNDRECT, OnUpdateDrawRoundrect)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_DRAW_POLYLINE, OnDrawPolyline)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POLYLINE, OnUpdateDrawPolyline)
	ON_COMMAND(ID_DRAW_POLYGON, OnDrawPolygon)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POLYGON, OnUpdateDrawPolygon)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLyView construction/destruction

CLyView::CLyView()
{
	// TODO: add construction code here
	m_nType=ID_DRAW_DRAG;//��ʼ��ͼ�������
	m_clText=0;//Ĭ�ϻ��ʳ�ʼ��ɫ���ɸĽ����ڴ����ʱ��ȡ�ϴ�����
	m_endPolyLine=TRUE;
	m_startPolyLine=FALSE;

}

CLyView::~CLyView()
{
}

BOOL CLyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLyView drawing

void CLyView::OnDraw(CDC* pDC)
{
	
	//����ͼ����OnDraw������WM_PAIT��Ϣ�Ļص�����
	CLyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//�����洢����ͼ���m_ls��ȡ�������ͼ����󲢵�����Ӧ���OnDraw����������Ӧͼ��
	int i=0,nSize=m_ls.GetSize();
	CLayer *pLayer=NULL;
	while(i<nSize)
	{
		pLayer=m_ls[i++];
		pLayer->OnDraw(pDC);
	}
/*
	//����˫���弼��
	CLyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	//�����洢����ͼ���m_ls��ȡ�������ͼ����󲢵�����Ӧ���OnDraw����������Ӧͼ��
	int i=0,nSize=m_ls.GetSize();
	CLayer *pLayer=NULL;
	while(i<nSize)
	{
		pLayer=m_ls[i++];
		pLayer->OnDraw(&mdc);
	}
	CRect rtClient;
	GetClientRect(&rtClient);
	pDC->BitBlt(0,0,rtClient.Width(),rtClient.Height(),&mdc,0,0,SRCCOPY);
*/	
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLyView printing

BOOL CLyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLyView diagnostics

#ifdef _DEBUG
void CLyView::AssertValid() const
{
	CView::AssertValid();
}

void CLyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLyDoc* CLyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLyDoc)));
	return (CLyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLyView message handlers

void CLyView::OnDrawDrag() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_DRAG;//ѡ�й�������ť���ĸ��ͼ�¼�ĸ�

	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawDrag(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(ID_DRAW_DRAG==m_nType);//���ù�������ť���ݣ�����if,else�������

}

void CLyView::OnDrawEllip() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_ELLIP;
	
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawEllip(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(ID_DRAW_ELLIP==m_nType);
		
}

void CLyView::OnDrawLine() 
{
	// TODO: Add your command handler code here
		m_nType=ID_DRAW_LINE;
		
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(ID_DRAW_LINE==m_nType);
}

void CLyView::OnDrawPen() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_PEN;
	
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawPen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(ID_DRAW_PEN==m_nType);
}


void CLyView::OnDrawRectangle() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_RECTANGLE;
	
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawRectangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(ID_DRAW_RECTANGLE==m_nType);
}


void CLyView::OnDrawRoundrect() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_ROUNDRECT;
	
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawRoundrect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nType==ID_DRAW_ROUNDRECT);
	
}

void CLyView::OnDrawPolyline() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_POLYLINE;
	
	m_startPolyLine=TRUE;
	
}

void CLyView::OnUpdateDrawPolyline(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(ID_DRAW_POLYLINE==m_nType);
}


void CLyView::OnDrawPolygon() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_POLYGON;

	m_endPolyLine=TRUE;
}

void CLyView::OnUpdateDrawPolygon(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(ID_DRAW_POLYGON==m_nType);
}


void CLyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CLayer* pLayer=NULL;
	CClientDC dc(this);
	if(ID_DRAW_DRAG!=m_nType)
	{
		//���ݵ�ǰ���ʹ���һ����ͼ��,���������ͼ�㣬��Ҫ���⴦����Ϊÿ����갴�¶����½�һ��ͼ�㣬������ͼ�㵥����ζ���������ͬһ������ͼ��
		if(ID_DRAW_POLYLINE!=m_nType&&ID_DRAW_POLYGON!=m_nType)//�Ȳ������������ֲ�������ͼ��
		{
			m_endPolyLine=TRUE;
			pLayer=CLayer::Create(m_nType);
			pLayer->m_clText=m_clText;//��LyView���е�ǰ����ɫ��ֵ��������ͼ�����ǰ����ɫ
			pLayer->OnLButtonDown(nFlags,point,&dc);
			m_ls.Add(pLayer);//	����µ�ͼ��
			return ;
		}
		else
		{
			if(m_endPolyLine)//������ͼ�㲢����������������˫������
			{
				m_endPolyLine=FALSE;
				pLayer=CLayer::Create(m_nType);
				pLayer->m_clText=m_clText;//��LyView���е�ǰ����ɫ��ֵ��������ͼ�����ǰ����ɫ
				pLayer->OnLButtonDown(nFlags,point,&dc);
				m_ls.Add(pLayer);//	����µ�ͼ��
				return ;
			}
			else
			{
				int nSize=m_ls.GetSize();
				pLayer=m_ls[nSize-1];
				pLayer->m_clText=m_clText;//��LyView���е�ǰ����ɫ��ֵ��������ͼ�����ǰ����ɫ
				pLayer->OnLButtonDown(nFlags,point,&dc);
				return;
			}
		}

	}
	//���ѡ���������ߣ�������갴��
	int i=0;
	while(i<m_ls.GetSize())
	{
		//�����е�ͼ����Ϊѡ��״̬
		pLayer=(CLayer*)m_ls[i];
		pLayer->Select(point);
		i++;
	}
	Invalidate();
	m_point=point;//���Ҫ�϶��������������϶������

//	CView::OnLButtonDown(nFlags, point);
}

//����ڿͻ��������ʱ�򣬼�¼�����Ϣ��������ͼ���յ�
void CLyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int nSize=m_ls.GetSize();//��ȡͼ������
	if(!nSize)//���û��ͼ�㣬�򷵻�
		return;
	CLayer* pLayer=NULL;
	CClientDC dc(this);
	if(ID_DRAW_DRAG!=m_nType)
	{
		//�����ͼ�����
		pLayer=m_ls[nSize-1];
		pLayer->OnLButtonUp(nFlags,point,&dc);
		if(STU_DRAWING==pLayer->m_nStatus)
			pLayer->m_nStatus=STU_NORMAL;
	}
	//�����ѡ���Ϸ�С���ߣ���ʵ���ϷŹ���
	else
	{
		//���ͼ���Ϸ�
		int i=0;
		while(i<nSize)
		{
			pLayer=m_ls[i];
			if(STU_SELECT==pLayer->m_nStatus)//m_nStatus�ڻ���CLayer�ж��壬�ڸ����������Select()�����б���ֵ
				pLayer->Offset(point.x-m_point.x,point.y-m_point.y);//m_point��¼��һ����갴�µĵ㣬����갴��ʱ����ֵ
			++i;
		}
	}
	Invalidate();//Invalideate�����OnPaint()������OnPaint()�����OnDraw�������л滭��OnDrawȡ������ͼ��������»滭
//	CView::OnLButtonUp(nFlags, point);
}

/*���ڻ�PolyLine��PolyGon�ƻ���ԭ����ͼ��ܹ���ʹ����˫������������Ȼ�����˻����ߣ����������ʱ��ֱ����굥������ͼ�㹤��
Ȼ����������ƶ����ͻ�������ʱ�����ڻ�û�е����ͻ�����ʼΪm_ls����һ��ѡ���Ҫ���Ƶ�ͼ������
������m_ls[nSize-1]����Ȼ����һ�ε�����ͼ�㣬��ʱ������ƶ����ͻ�������Ȼ������껬��ʱ��ʾһ�������
��һ��˫���������,�����������˫����Ӧ������Ϊm_ls���һ���հ�ͼ��*/
void CLyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int nSize=m_ls.GetSize();
	if(!nSize)
		return;
	CLayer* pLayer=NULL;
	if(ID_DRAW_DRAG!=m_nType)
	{
		if(ID_DRAW_POLYLINE!=m_nType&&ID_DRAW_POLYGON)
		{
			//�»���ͼ��������ƶ�����ʹ����ʱDC���⻭��Ƶ������
			CClientDC dc(this);//��ʾ��ͼ����
			////�ڻ滭֮ǰ�������Ѿ���ѡ�����ͼ���ಢ���Ѿ�������ڿͻ������µ�
			//ʱ����Ѿ������ͼ����������m_ls�����m_ls������һ��ͼ�����ǵ�ǰҪ���Ƶ�ͼ��
			pLayer=(CLayer*)m_ls[nSize-1];
			pLayer->OnMouseMove(nFlags,point,&dc);
			return;
		}
		else
		{
			if(!m_endPolyLine)
			{
				CClientDC dc(this);
				pLayer=(CLayer*)m_ls[nSize-1];
				pLayer->OnMouseMove(nFlags,point,&dc);
				return;
			}
			else
			{
				return;
			}
		}
	}
	//����ӹ�ĳ��ͼ�������ʾΪ������ʼ�϶���״̬
	while(nSize--)
	{
		if(m_ls[nSize]->Track(point))
		{
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEALL));
			break;
		}
	}
	CView::OnMouseMove(nFlags, point);
}

/*��ɫ���ߵ���Ӧ����*/
void CLyView::OnDrawColor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(IDCANCEL==dlg.DoModal())
		return;

	CLayer* pLayer=NULL;
	int i=0,nSize=m_ls.GetSize();
	COLORREF cl=dlg.GetColor();
	while(i<nSize)
	{
		pLayer=m_ls[i++];
		if(STU_SELECT==pLayer->m_nStatus)
			pLayer->m_clText=cl;
	}
	m_clText=cl;//ȱʡ��ɫ,ʵ����ѡ��ĳ����ɫ��֮���ͼ��Ҳ��Ĭ��ʹ��������ɫ
	Invalidate();
}



void CLyView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_endPolyLine=TRUE;
	
	//�������൱��Ϊm_ls[]����һ���հ׵�ͼ�㣬ʲô�����ɣ�ֻ��Ϊ���ֲ�
	//�������ƻ���ͼ��ṹ��������Bug,bug��OnMouseMove����ע�ʹ�����
	CLayer *pLayer=CLayer::Create(ID_DRAW_POLYLINE);
	m_ls.Add(pLayer);

	CView::OnLButtonDblClk(nFlags, point);
}




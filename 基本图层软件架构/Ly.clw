; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLyView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ly.h"
LastPage=0

ClassCount=5
Class1=CLyApp
Class2=CAboutDlg
Class3=CLyDoc
Class4=CLyView
Class5=CMainFrame

ResourceCount=2
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME

[CLS:CLyApp]
Type=0
BaseClass=CWinApp
HeaderFile=Ly.h
ImplementationFile=Ly.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Ly.cpp
ImplementationFile=Ly.cpp
LastObject=ID_DRAW_POLYLINE

[CLS:CLyDoc]
Type=0
BaseClass=CDocument
HeaderFile=LyDoc.h
ImplementationFile=LyDoc.cpp

[CLS:CLyView]
Type=0
BaseClass=CView
HeaderFile=LyView.h
ImplementationFile=LyView.cpp
Filter=C
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_DRAW_DRAG
Command10=ID_DRAW_LINE
Command11=ID_DRAW_ELLIP
Command12=ID_DRAW_PEN
Command13=ID_DRAW_COLOR
Command14=ID_DRAW_RECTANGLE
Command15=ID_DRAW_ROUNDRECT
Command16=ID_DRAW_POLYLINE
Command17=ID_DRAW_POLYGON
CommandCount=17

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14


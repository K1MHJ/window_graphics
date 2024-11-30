
// MFCApplication2Doc.cpp : implementation of the CMFCApplication2Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"

#include <propkey.h>
#include <chrono>
#include <random>
#include <ctime>
#include <functional>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication2Doc

IMPLEMENT_DYNCREATE(CMFCApplication2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication2Doc, CDocument)
END_MESSAGE_MAP()


// CMFCApplication2Doc construction/destruction

CMFCApplication2Doc::CMFCApplication2Doc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCApplication2Doc::~CMFCApplication2Doc()
{
}

BOOL CMFCApplication2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	TRACE("NEW\n");
	th1 = std::thread(ThreadNewFunc, this);

	return TRUE;
}




// CMFCApplication2Doc serialization

void CMFCApplication2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCApplication2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCApplication2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplication2Doc diagnostics

#ifdef _DEBUG
void CMFCApplication2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplication2Doc commands
void CMFCApplication2Doc::ThreadNewFunc(CMFCApplication2Doc* doc)
{
	std::mt19937 mt(0);
	std::time_t a;
	int fps = 10; // 100 msec

	std::function<long long(void)> currentTimeMicro = []() {
		std::chrono::system_clock::duration d = std::chrono::system_clock::now().time_since_epoch();
		return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
		};
	long long end = currentTimeMicro();
	long long next = end + (1000 * 1000 / fps); //100000
	long long last_end = end;
	for (int i = 0; i < 100000; i++) {
		int x = mt() % 200;
		int y = mt() % 200;
		doc->m_points.push_back({ x,y });

		std::this_thread::sleep_for(
			std::chrono::microseconds(1));

		if(next < currentTimeMicro()) {
			end = currentTimeMicro();
			//更新時間を過ぎた場合は現在時刻から次の更新時間を計算
			next = end + (1000 * 1000 / fps);
			TRACE("1[FPS]%.3f: I: %d, Cnt: %d\n",1000000.0 / (end - last_end), i, doc->m_points.size());
			last_end = end;
			CView* pView = NULL;
			POSITION pos = doc->GetFirstViewPosition();
			if (pos != NULL) {
				pView = (CView*)doc->GetNextView(pos);
				if (pView != NULL) {
					//pView->SendMessage(UM_UPDATE);
				}
			}
		}
	}

	TRACE("0[FPS]%.3f: Cnt: %d\n",1000000.0 / (end - last_end), doc->m_points.size());
	CView* pView = NULL;
	POSITION pos = doc->GetFirstViewPosition();
	if (pos != NULL) {
		pView = (CView*)doc->GetNextView(pos);
		if (pView != NULL) {
			pView->SendMessage(UM_UPDATE);
		}
	}
}

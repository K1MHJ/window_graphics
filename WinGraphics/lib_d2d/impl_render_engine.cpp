#include "pch.h"

#include "RenderEngine.h"
#include "impl_render_engine.h"

CRenderEngine::impl_render_engine::impl_render_engine()
{
}

void CRenderEngine::impl_render_engine::SetTransform(
	float x_n, // left x-range on cartesian coordinate
	float x_r, // right x-range
	float y_d, // down y-range
	float y_u, // upper y-range
	float x_s, // x-axis scale on 
	float y_s // y-axis scale on
)
{
	this->m_Range.x_n = x_n;
	this->m_Range.x_r = x_r;
	this->m_Range.y_d = y_d;
	this->m_Range.y_u = y_u;
	this->m_Range.x_s = x_s;
	this->m_Range.y_s = y_s;


	CHwndRenderTarget* pRenderTarget
		= this->m_pView->GetRenderTarget();

	CD2DSizeF size = pRenderTarget->GetSize();

	float w = size.width;
	float h = size.height;

	D2D1_MATRIX_3X2_F M;

	M._11 = w / (x_r - x_n);
	M._12 = 0.0f;
	M._21 = 0.0f;
	M._22 = h / (y_d - y_u);
	M._31 = w / (x_n - x_r) * x_n;
	M._32 = h / (y_u - y_d) * y_u;

	pRenderTarget->SetTransform(M);
}
void CRenderEngine::impl_render_engine::Initialize(CView* pView)
{
	this->m_pView = pView;
	ClearScreen();
	
	SetTransform(-300, 300, -200, 200);

	CHwndRenderTarget* pRenderTarget =
		this->m_pView->GetRenderTarget();
	
	// rectangle in cartesian coodinates
	CD2DRectF rect(-100.0f, 100.0f, 100.0f, -100.0f);

	pRenderTarget->DrawRectangle(rect,
		&CD2DSolidColorBrush(pRenderTarget, D2D1::ColorF(D2D1::ColorF::Black)));
}

void CRenderEngine::impl_render_engine::ClearScreen()
{
	if (this->m_pView && this->m_pView->GetSafeHwnd())
	{
		CHwndRenderTarget* pRenderTarget =
			this->m_pView->GetRenderTarget();

		// reset's translation to default
		pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

		// clear screen
		pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
	}
}

CRenderEngine::impl_render_engine::~impl_render_engine()
{
}



#include "pch.h"
#include "RenderEngine.h"

#include "impl_render_engine.h"

CRenderEngine::CRenderEngine() 	:
	m_p_render_engine(new impl_render_engine())
{

}
CRenderEngine::~CRenderEngine()
{

}
void CRenderEngine::Initialize(CView* pView)
{
	this->m_p_render_engine->Initialize(pView);
}
void CRenderEngine::SetTransform(
	float x_n, // left x-range on cartesian coordinate
	float x_r, // right x-range
	float y_d, // down y-range
	float y_u, // upper y-range
	float x_s, // x-axis scale on 
	float y_s // y-axis scale on
)
{
	this->m_p_render_engine->SetTransform(x_n, x_r, y_d, y_u, x_s, y_s);
}


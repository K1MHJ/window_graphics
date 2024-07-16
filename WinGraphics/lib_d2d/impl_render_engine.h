#pragma once

class CRenderEngine::impl_render_engine
{
private:
	CView* m_pView;

	CoordinateRange m_Range;

	friend class CRenderEngine;

	void Initialize(CView* pView);
	void ClearScreen();
	void SetTransform(
		float x_n, // left x-range on cartesian coordinate
		float x_r, // right x-range
		float y_d, // down y-range
		float y_u, // upper y-range
		float x_s = 1.0f, // x-axis scale on 
		float y_s = 1.0f // y-axis scale on
	);
public:
	impl_render_engine();
	~impl_render_engine();
};


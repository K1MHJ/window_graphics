#pragma once
#include "lib_d2d_base.h"
#include <memory>

struct CoordinateRange
{
	float x_n; // left x-range on cartesian coordinate
	float x_r; // right x-range
	float y_d; // down y-range
	float y_u; // upper y-range
	float x_s; // x-axis scale on 
	float y_s; // y-axis scale on
};

class LIB_EXT_D2D CRenderEngine
{
private:
	class impl_render_engine;

	std::unique_ptr<impl_render_engine> m_p_render_engine;

public:
	CRenderEngine();

	void Initialize(CView* pView);
	void SetTransform(
		float x_n, // left x-range on cartesian coordinate
		float x_r, // right x-range
		float y_d, // down y-range
		float y_u, // upper y-range
		float x_s, // x-axis scale on 
		float y_s // y-axis scale on
	);

	~CRenderEngine();
};


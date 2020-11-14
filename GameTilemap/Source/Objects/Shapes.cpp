#include "GamePCH.h"
#include "Shapes.h"

//0.0f, 0.7f, // Center
//0.2f, 0.7f, // Top right
//0.1f, 0.5f, // right center
//0.0f, .6f, // right center
//0.2f, 0.6f,
//.1f, .2f,
//.05f, .3f,
//0.15f, .3f,
//0.1f, 0.0f,

const fw::VertexFormat meshAttribs_Human[] =
{
	fw::VertexFormat{0.0f, 0.0f,		0, 0}
};

const int meshPrimType_Human = GL_POINTS;
const int meshNumVerts_Human = (sizeof(meshAttribs_Human)) / (sizeof(fw::VertexFormat));

const fw::VertexFormat meshAttribs_Explosion[] =
{
	fw::VertexFormat{0.0f, 0.0f,		0, 0}
};

const int meshPrimType_Explosion = GL_POINTS;
const int meshNumVerts_Explosion = sizeof(meshAttribs_Explosion) / sizeof(fw::VertexFormat);

const fw::VertexFormat meshAttribs_Bomb[] =
{
	fw::VertexFormat{ 0.0f, 0.4f,	0,0, },
	fw::VertexFormat{-0.2f, 0.0f,	1,1, },
	fw::VertexFormat{0.0f, -0.4f,	1,0, },
	fw::VertexFormat{ 0.2f, 0.0f,	0,0	 }, 
};

const int meshPrimType_Bomb = GL_TRIANGLE_FAN;
const int meshNumVerts_Bomb = sizeof(meshAttribs_Bomb) / sizeof(fw::VertexFormat);

const fw::VertexFormat meshAttribs_Rectangle[] =
{ 
	fw::VertexFormat{-0.25f, -0.25f,	0,0, }, // bl
	fw::VertexFormat{0.25f, 0.25f,		1,1, }, // tr
	fw::VertexFormat{0.25f, -0.25f,		1,0, }, // br

	fw::VertexFormat{-0.25f, -0.25f,	0,0, }, // bl
	fw::VertexFormat{-0.25f, 0.25f,		0,1, }, // tl
	fw::VertexFormat{0.25f, 0.25f,		1,1, }, // tr
};

const int meshPrimType_Rectangle = GL_TRIANGLE_FAN;
const int meshNumVerts_Rectangle = sizeof(meshAttribs_Rectangle) / sizeof(fw::VertexFormat);
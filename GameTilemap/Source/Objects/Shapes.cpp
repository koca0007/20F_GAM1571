#include "GamePCH.h"
#include "Shapes.h"

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



const fw::VertexFormat meshAttribs_Box[] =
{
	fw::VertexFormat{0.0f, 0.0f,	0,0, },
	fw::VertexFormat{0.0f, 1.0f,	0,1, },
	fw::VertexFormat{1.0f, 1.0f,	1,1, },
	fw::VertexFormat{1.0f, 0.0f,	1,0	 },

	//fw::VertexFormat{0.0f, 0.0f,	780 / 1024.0f,			383 / 512.0f,			},
	//fw::VertexFormat{0.0f, 1.0f,	780 / 1024.0f,			(383 + 64) / 512.0f,	},
	//fw::VertexFormat{1.0f, 1.0f,	(780 + 64) / 1024.0f,	(383 + 64) / 512.0f,	},
	//fw::VertexFormat{1.0f, 0.0f,	(780 + 64) / 1024.0f,	383 / 512.0f			},
};

const int meshPrimType_Box = GL_TRIANGLE_FAN;
const int meshNumVerts_Box = sizeof(meshAttribs_Box) / sizeof(fw::VertexFormat);

const fw::VertexFormat meshAttribs_Sprite[] =
{
	fw::VertexFormat{ 0.0f, 0.0f,	0, 0, },
	fw::VertexFormat{ 0.0f, 1.0f,	0, 1, },
	fw::VertexFormat{ 1.0f, 1.0f,	1, 1, },
	fw::VertexFormat{ 1.0f, 0.0f,	1, 0  },
};

const int meshPrimType_Sprite = GL_TRIANGLE_FAN;
const int meshNumVerts_Sprite = sizeof(meshAttribs_Sprite) / sizeof(fw::VertexFormat);
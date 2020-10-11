#include "GamePCH.h"

float meshAttribs_Human[] =
{
	0.0f, 0.7f, // Center
	0.2f, 0.7f, // Top right
	0.1f, 0.5f, // right center
	0.0f, .6f, // right center
	0.2f, 0.6f,
	.1f, .2f,
	.05f, .3f,
	0.15f, .3f,
	0.1f, 0.0f,
};

int meshPrimType_Human = GL_TRIANGLES;
int meshNumVerts_Human = 9;

float meshAttribs_Enemy[] =
{
	0.3f,  0.5f, // Center
	0.0f, 0.1f
};

int meshPrimType_Enemy = GL_LINES;
int meshNumVerts_Enemy = 1;

float meshAttribs_Circle[] =
{
	0.0f,  0.4f, 
	0.2f, 0.3f,
	0.15f, 0.18f,
	0.05f, -0.10f,
	-0.10f, -0.08f,
	-0.12f, 0.14f
};
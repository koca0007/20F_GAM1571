#include "GamePCH.h"

//0.0f, 0.7f, // Center
//0.2f, 0.7f, // Top right
//0.1f, 0.5f, // right center
//0.0f, .6f, // right center
//0.2f, 0.6f,
//.1f, .2f,
//.05f, .3f,
//0.15f, .3f,
//0.1f, 0.0f,

float meshAttribs_Human[] =
{
	0.0f, 0.0f
};

int meshPrimType_Human = GL_POINTS;
int meshNumVerts_Human = 1;

float meshAttribs_Explosion[] =
{
	0.0f, 0.0f, 
	
};

int meshPrimType_Explosion = GL_POINTS;
int meshNumVerts_Explosion = 1;

float meshAttribs_Bomb[] =
{
	0.0f, 0.4f,
	-0.2f, 0.0f,
	0.0f, -0.4f,
	0.2f, 0.0f

};

int meshPrimType_Bomb = GL_TRIANGLE_FAN;
int meshNumVerts_Bomb = 4;
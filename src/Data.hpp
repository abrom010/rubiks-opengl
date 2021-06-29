#pragma once

float squareVertices[] =
{
   -0.8f, -0.8f, // bot left
   0.8f, 0.8f, // top right
   -0.8f, 0.8f, // top left
   0.8f, -0.8f, // bottom right
};

unsigned int squareIndices[] =
{
	0, 1, 2, // square top left
	0, 3, 1, // square bot right
};

float borderVertices[] =
{
	// square verts
	-0.8f, -0.8f, // bot left
   0.8f, 0.8f, // top right
   -0.8f, 0.8f, // top left
   0.8f, -0.8f, // bottom right

   // border verts
   -0.8f, -1.0f, // bot left bot
   0.8f, -1.0f, // bot right bot
   -0.8f, 1.0f, // top left top
   0.8f, 1.0f, // top right top
   -1.0f, -0.8f, // bot left left
   1.0f, -0.8f, // bot right right
   -1.0f, 0.8f, // top left left
   1.0f, 0.8f // top right right
};

unsigned int borderIndices[] =
{
	0, 5, 3, // bottom
	4, 5, 0,

	2, 7, 6, // top
	2, 1, 7,

	1, 9, 11, // right
	1, 3, 9,

	0, 8, 10, // left
	4, 5, 0,
};
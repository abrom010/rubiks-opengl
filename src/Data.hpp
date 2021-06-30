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

   // border edges
   -0.8f, -1.0f, // bot left bot
   0.8f, -1.0f, // bot right bot
   -0.8f, 1.0f, // top left top
   0.8f, 1.0f, // top right top
   -1.0f, -0.8f, // bot left left
   1.0f, -0.8f, // bot right right
   -1.0f, 0.8f, // top left left
   1.0f, 0.8f, // top right right

   // border corners
	-1.0f, -1.0f, // bot left
	1.0f, 1.0f, // top right
	-1.0f, 1.0f, // top left
	1.0f, -1.0f // bot right
};

unsigned int borderIndices[] =
{
	0, 5, 3, // bottom edge
	4, 5, 0,

	2, 7, 6, // top edge
	2, 1, 7,

	1, 9, 11, // right edge
	1, 3, 9,

	0, 10, 8, // left edge
	0, 10, 2,

	// top left corner
	14, 2, 6,
	14, 2, 10,

	// top right corner
	13, 1, 7,
	13, 1, 11,

	// bot left corner
	12, 0, 4,
	12, 0, 8,

	// bot right corner
	15, 3, 5,
	15, 3, 9,
};
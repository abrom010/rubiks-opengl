#pragma once

#include <vector>
#include <iostream>
#include <string>

class Cube
{
public:

	Cube();

	//Base state White (top) Yellow (bottom) Green (front) Blue (back) Orange (left) Red (right)
	enum class Color { white, yellow, green, red, blue, orange };

	std::vector<std::vector<Color>> whiteFace;
	std::vector<std::vector<Color>> redFace;
	std::vector<std::vector<Color>> blueFace;
	std::vector<std::vector<Color>> yellowFace;
	std::vector<std::vector<Color>> orangeFace;
	std::vector<std::vector<Color>> greenFace;


	Color getCenter(std::vector<std::vector<Color>>& face);
	void printColor(Color color);
	void printFace(std::vector<std::vector<Cube::Color>>& face);
	void printCube();
	void rotateFace(std::vector<std::vector<Color>>& face, bool clockwise);
	void rotateFront(std::vector<std::vector<Color>>& face);
	void rotateEdges(std::vector<std::vector<Color>>& face);
	bool isFaceSolved(std::vector<std::vector<Color>>& face);
	void scramble();
	void solve();
};
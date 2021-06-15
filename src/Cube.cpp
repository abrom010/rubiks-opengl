#include "cube.hpp"

Cube::Cube()
{
	Cube::whiteFace =
	{
	  {Color::white, Color::white, Color::white},
	  {Color::white, Color::white, Color::white},
	  {Color::white, Color::white, Color::white}
	};
	Cube::redFace =
	{
	  {Color::red, Color::red, Color::red},
	  {Color::red, Color::red, Color::red},
	  {Color::red, Color::red, Color::red}
	};
	Cube::blueFace =
	{
	  {Color::blue, Color::blue, Color::blue},
	  {Color::blue, Color::blue, Color::blue},
	  {Color::blue, Color::blue, Color::blue}
	};
	Cube::yellowFace =
	{
	  {Color::yellow, Color::yellow, Color::yellow},
	  {Color::yellow, Color::yellow, Color::yellow},
	  {Color::yellow, Color::yellow, Color::yellow}
	};
	Cube::orangeFace =
	{
	  {Color::orange, Color::orange, Color::orange},
	  {Color::orange, Color::orange, Color::orange},
	  {Color::orange, Color::orange, Color::orange}
	};
	Cube::greenFace =
	{
	  {Color::green, Color::green, Color::green},
	  {Color::green, Color::green, Color::green},
	  {Color::green, Color::green, Color::green}
	};
}

void Cube::printColor(Color color)
{
	switch (color)
	{
	case Cube::Color::white:
		std::cout << "WHITE";
		break;
	case Cube::Color::green:
		std::cout << "GREEN";
		break;
	case Cube::Color::orange:
		std::cout << "ORANGE";
		break;
	case Cube::Color::yellow:
		std::cout << "YELLOW";
		break;
	case Cube::Color::blue:
		std::cout << "BLUE";
		break;
	case Cube::Color::red:
		std::cout << "RED";
		break;
	}
}

Cube::Color Cube::getCenter(std::vector<std::vector<Color>>& face)
{
	return face[1][1];
}

void Cube::printCube()
{
	printFace(whiteFace);
	printFace(greenFace);
	printFace(orangeFace);
	printFace(yellowFace);
	printFace(blueFace);
	printFace(redFace);
}

void Cube::printFace(std::vector<std::vector<Cube::Color>> face)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printColor(face[i][j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void Cube::rotateFace(std::vector<std::vector<Cube::Color>>& face, bool clockwise)
{
	rotateFront(face, clockwise);
	rotateEdges(face, clockwise);
}



void Cube::rotateFront(std::vector<std::vector<Color>>& face, bool clockwise)
{
	if (clockwise)
	{
		//Corners White
		Color temp = face[0][0];
		face[0][0] = face[2][0];
		face[2][0] = face[2][2];
		face[2][2] = face[0][2];
		face[0][2] = temp;
		//Edges White
		temp = face[0][1];
		face[0][1] = face[1][0];
		face[1][0] = face[2][1];
		face[2][1] = face[1][2];
		face[1][2] = temp;
	}
	else
	{
		//Corners
		Color temp = face[0][0];
		face[0][0] = face[0][2];
		face[0][2] = face[2][2];
		face[2][2] = face[2][0];
		face[2][0] = temp;
		//Edges
		temp = face[0][1];
		face[2][1] = face[1][0];
		face[1][2] = face[2][1];
		face[0][1] = face[1][2];
		face[0][1] = temp;
	}
}
void Cube::rotateEdges(std::vector<std::vector<Color>>& face, bool clockwise)
{
	// IMPORTANT: right now every rotation is affecting the 0th column of other faces
	//           need to hard code each case individually
	if (clockwise)
	{
		if (getCenter(face) == Color::white)
		{
			std::vector<Color> temp = redFace[0];
			redFace[0] = blueFace[0];
			blueFace[0] = orangeFace[0];
			orangeFace[0] = greenFace[0];
			greenFace[0] = temp;
		}
		else if (getCenter(face) == Color::green)
		{
			std::vector<Color> temp = whiteFace[0];

			// orange column 2 moving into white row 0
			whiteFace[0][0] = orangeFace[0][2];
			whiteFace[0][1] = orangeFace[1][2];
			whiteFace[0][2] = orangeFace[2][2];

			//yellow row 0 moving into orange column 2
			orangeFace[0][2] = yellowFace[0][0];
			orangeFace[1][2] = yellowFace[0][1];
			orangeFace[2][2] = yellowFace[0][2];

			//red column 0 moving into yellow row 0
			yellowFace[0][2] = redFace[0][0];
			yellowFace[0][1] = redFace[1][0];
			yellowFace[0][0] = redFace[2][0];

			//white row 0 moving into red column 0
			redFace[0][0] = temp[2];
			redFace[1][0] = temp[1];
			redFace[2][0] = temp[0];

		}
		else if (getCenter(face) == Color::orange)
		{

			std::vector<Color> temp =
			{
				greenFace[0][0],
				greenFace[1][0],
				greenFace[2][0]
			};

			// white column 2 moving into green column 0
			greenFace[2][0] = whiteFace[0][2];
			greenFace[1][0] = whiteFace[1][2];
			greenFace[0][0] = whiteFace[2][2];

			//blue column 2 moving into white column 2
			whiteFace[0][2] = blueFace[0][2];
			whiteFace[1][2] = blueFace[1][2];
			whiteFace[2][2] = blueFace[2][2];

			//yellow column 0 moving into blue column 2
			blueFace[2][2] = yellowFace[0][0];
			blueFace[1][2] = yellowFace[1][0];
			blueFace[0][2] = yellowFace[2][0];

			//green column 0 moving into yellow column 0
			yellowFace[0][0] = temp[0];
			yellowFace[1][0] = temp[1];
			yellowFace[2][0] = temp[2];
		}
		else if (getCenter(face) == Color::yellow)
		{
			std::vector<Color> temp = redFace[2];
			redFace[2] = greenFace[2];
			greenFace[2] = orangeFace[2];
			orangeFace[2] = blueFace[2];
			blueFace[2] = temp;
		}
		else if (getCenter(face) == Color::blue)    //todo
		{
			std::vector<Color> temp = whiteFace[2];

			// orange column 0 moving into yellow row 2
			whiteFace[0][0] = orangeFace[0][2];
			whiteFace[0][1] = orangeFace[1][2];
			whiteFace[0][2] = orangeFace[2][2];

			//yellow row 2 moving into red column 2
			orangeFace[0][2] = yellowFace[0][0];
			orangeFace[1][2] = yellowFace[0][1];
			orangeFace[2][2] = yellowFace[0][2];

			//red column 2 moving into white row 2
			yellowFace[0][2] = redFace[0][0];
			yellowFace[0][1] = redFace[1][0];
			yellowFace[0][0] = redFace[2][0];

			//white row 2 moving into orange column 0
			redFace[0][0] = temp[2];
			redFace[1][0] = temp[1];
			redFace[2][0] = temp[0];

		}
		else if (getCenter(face) == Color::red) //todo
		{
			std::vector<Color> temp = whiteFace[0];
			whiteFace[0] = greenFace[0];
			greenFace[0] = yellowFace[0];
			yellowFace[0] = blueFace[0];
			blueFace[0] = temp;
		}
	}
	else
	{
		if (getCenter(face) == Color::white)
		{
			std::vector<Color> temp = redFace[0];
			redFace[0] = greenFace[0];
			greenFace[0] = orangeFace[0];
			orangeFace[0] = blueFace[0];
			blueFace[0] = temp;
		}
		else if (getCenter(face) == Color::green)
		{
			std::vector<Color> temp = whiteFace[0];
			whiteFace[0] = redFace[0];
			redFace[0] = yellowFace[0];
			yellowFace[0] = orangeFace[2];
			orangeFace[2] = temp;
		}
		else if (getCenter(face) == Color::orange)
		{
			std::vector<Color> temp = whiteFace[0];
			whiteFace[0] = greenFace[0];
			greenFace[0] = yellowFace[0];
			yellowFace[0] = blueFace[0];
			blueFace[0] = temp;
		}
		else if (getCenter(face) == Color::yellow)
		{
			std::vector<Color> temp = redFace[2];
			redFace[2] = blueFace[0];
			blueFace[0] = orangeFace[0];
			orangeFace[0] = greenFace[0];
			greenFace[0] = temp;
		}
		else if (getCenter(face) == Color::blue)
		{
			std::vector<Color> temp = whiteFace[0];
			whiteFace[0] = orangeFace[0];
			orangeFace[0] = yellowFace[0];
			yellowFace[0] = redFace[0];
			redFace[0] = temp;
		}
		else if (getCenter(face) == Color::red)
		{
			std::vector<Color> temp = whiteFace[0];
			whiteFace[0] = blueFace[0];
			blueFace[0] = yellowFace[0];
			yellowFace[0] = greenFace[0];
			greenFace[0] = temp;
		}
	}
}

bool Cube::isFaceSolved(std::vector<std::vector<Color>> face)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (face[i][j] != face[1][1])
				return false;
		}
	}
	return true;
}

int main() {
	Cube cube;
	cube.rotateFace(cube.whiteFace, true);
	cube.rotateFace(cube.greenFace, true);
	cube.rotateFace(cube.orangeFace, true);
	cube.rotateFace(cube.yellowFace, true);
	cube.printCube();

	return 0;
}
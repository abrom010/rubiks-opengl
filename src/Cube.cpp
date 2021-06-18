#include "Cube.hpp"

Cube::Cube()
{
	Cube::whiteFace =
	{
	  {Color::green, Color::orange, Color::green},
	  {Color::green, Color::white, Color::green},
	  {Color::green, Color::red, Color::green}
	};
	Cube::redFace =
	{
	  {Color::white, Color::white, Color::white},
	  {Color::red, Color::red, Color::red},
	  {Color::yellow, Color::yellow, Color::yellow}
	};
	Cube::blueFace =
	{
	  {Color::orange, Color::blue, Color::orange},
	  {Color::white, Color::blue, Color::white},
	  {Color::red, Color::blue, Color::red}
	};
	Cube::yellowFace =
	{
	  {Color::blue, Color::red, Color::blue},
	  {Color::blue, Color::yellow, Color::blue},
	  {Color::blue, Color::orange, Color::blue}
	};
	Cube::orangeFace =
	{
	  {Color::yellow, Color::orange, Color::white},
	  {Color::yellow, Color::orange, Color::white},
	  {Color::yellow, Color::orange, Color::white}
	};
	Cube::greenFace =
	{
	  {Color::red, Color::green, Color::red},
	  {Color::yellow, Color::green, Color::yellow},
	  {Color::orange, Color::green, Color::orange}
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
	if (clockwise)
	{
		rotateFront(face);
		rotateEdges(face);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			rotateFront(face);
			rotateEdges(face);
		}
	}

}

void Cube::rotateFront(std::vector<std::vector<Color>>& face)
{
	//if (clockwise)
	//{
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
	//}
	/*else
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
	}*/
}
void Cube::rotateEdges(std::vector<std::vector<Color>>& face)
{
	// IMPORTANT: right now every rotation is affecting the 0th column of other faces
	//           need to hard code each case individually
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
	else if (getCenter(face) == Color::blue)
	{
		std::vector<Color> temp = whiteFace[2];

		// red column 2 moving into white row 2
		whiteFace[2][2] = redFace[0][2];
		whiteFace[2][1] = redFace[1][2];
		whiteFace[2][0] = redFace[2][2];

		//yellow row 2 moving into red column 2
		redFace[2][2] = yellowFace[2][0];
		redFace[1][2] = yellowFace[2][1];
		redFace[0][2] = yellowFace[2][2];

		//orange column 0 moving into yellow row 2
		yellowFace[2][0] = orangeFace[0][0];
		yellowFace[2][1] = orangeFace[1][0];
		yellowFace[2][2] = orangeFace[2][0];

		//white row 2 moving into orange column 0
		orangeFace[2][0] = temp[2];
		orangeFace[1][0] = temp[1];
		orangeFace[0][0] = temp[0];

	}
	else if (getCenter(face) == Color::red)
	{
		std::vector<Color> temp =
		{
			greenFace[0][2],
			greenFace[1][2],
			greenFace[2][2]
		};

		// yellow column 2 moving into green column 2
		greenFace[2][2] = yellowFace[2][2];
		greenFace[1][2] = yellowFace[1][2];
		greenFace[0][2] = yellowFace[0][2];

		//blue column 0 moving into yellow column 2
		yellowFace[2][2] = blueFace[0][0];
		yellowFace[1][2] = blueFace[1][0];
		yellowFace[0][2] = blueFace[2][0];

		//white column 0 moving into blue column 0
		blueFace[0][0] = whiteFace[0][0];
		blueFace[1][0] = whiteFace[1][0];
		blueFace[2][0] = whiteFace[2][0];

		//green column 2 moving into white column 0
		whiteFace[2][0] = temp[0];
		whiteFace[1][0] = temp[1];
		whiteFace[0][0] = temp[2];
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
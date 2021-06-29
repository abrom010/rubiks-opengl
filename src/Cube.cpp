#include "Cube.hpp"
#include <list>	//added by Tim for storing list of moves in Scramble
#include <ctime>

enum class move {
	whiteCW, whiteCCW, greenCW, greenCCW, orangeCW, orangeCCW,
	yellowCW, yellowCCW, blueCW, blueCCW, redCW, redCCW, tempMove
};
std::list<move> listOfMoves;


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

void Cube::printFace(std::vector<std::vector<Cube::Color>>& face)
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

void Cube::scramble()
{
	srand(time(NULL));
	bool rotation;
	int i;
	int x;

	for (int j = 0; j < 20; j++)
	{
		i = rand() % 2 + 1;
		if (i == 1)
		{
			rotation = true;
		}
		else
		{
			rotation = false;
		}

		x = rand() % 6 + 1;
		
		switch (x)
		{
		case 1:
			rotateFace(whiteFace, rotation);
			break;
		case 2:
			rotateFace(greenFace, rotation);
			break;
		case 3:
			rotateFace(orangeFace, rotation);
			break;
		case 4:
			rotateFace(yellowFace, rotation);
			break;
		case 5:
			rotateFace(blueFace, rotation);
			break;
		case 6:
			rotateFace(redFace, rotation);
			break;
		default:
			break;
		}		
	}
}

void Cube::solve()	//todo
{
	
}

void Cube::saveMove(std::vector<std::vector<Cube::Color>>& face, bool clockwise)
{
	if (clockwise)
	{
		if (face == Cube::whiteFace)
			listOfMoves.push_front(move::whiteCW);
		else if (face == Cube::greenFace)
			listOfMoves.push_front(move::greenCW);
		else if (face == Cube::orangeFace)
			listOfMoves.push_front(move::orangeCW);
		else if (face == Cube::yellowFace)
			listOfMoves.push_front(move::yellowCW);
		else if (face == Cube::blueFace)
			listOfMoves.push_front(move::blueCW);
		else if (face == Cube::redFace)
			listOfMoves.push_front(move::redCW);
	}
	else
	{
		if (face == Cube::whiteFace)
			listOfMoves.push_front(move::whiteCCW);
		else if (face == Cube::greenFace)
			listOfMoves.push_front(move::greenCCW);
		else if (face == Cube::orangeFace)
			listOfMoves.push_front(move::orangeCCW);
		else if (face == Cube::yellowFace)
			listOfMoves.push_front(move::yellowCCW);
		else if (face == Cube::blueFace)
			listOfMoves.push_front(move::blueCCW);
		else if (face == Cube::redFace)
			listOfMoves.push_front(move::redCCW);
	}
}

void Cube::undo()
{
	if (listOfMoves.empty())
		return;

	move temp = listOfMoves.front();

	if (temp == move::whiteCW)
		undoFace(whiteFace, false);
	else if (temp == move::whiteCCW)
		undoFace(whiteFace, true);
	else if (temp == move::greenCW)
		undoFace(greenFace, false);
	else if (temp == move::greenCCW)
		undoFace(greenFace, true);
	else if (temp == move::orangeCW)
		undoFace(orangeFace, false);
	else if (temp == move::orangeCCW)
		undoFace(orangeFace, true);
	else if (temp == move::yellowCW)
		undoFace(yellowFace, false);
	else if (temp == move::yellowCCW)
		undoFace(yellowFace, true);
	else if (temp == move::blueCW)
		undoFace(blueFace, false);
	else if (temp == move::blueCCW)
		undoFace(blueFace, true);
	else if (temp == move::redCW)
		undoFace(redFace, false);
	else if (temp == move::redCCW)
		undoFace(redFace, true);

	listOfMoves.pop_front();


}

void Cube::rotateFace(std::vector<std::vector<Cube::Color>>& face, bool clockwise)
{
	if (clockwise)
	{
		rotateFront(face);
		rotateEdges(face);
		saveMove(face, clockwise);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			rotateFront(face);
			rotateEdges(face);
		}
		saveMove(face, clockwise);
	}

}

void Cube::undoFace(std::vector<std::vector<Cube::Color>>& face, bool clockwise)
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


bool Cube::isFaceSolved(std::vector<std::vector<Color>>& face)
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
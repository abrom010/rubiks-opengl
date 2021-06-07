#include "cube.h"

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
    /*for (std::vector<std::vector<Cube::Color>>& face : faces)
    {*/
    printFace(whiteFace);
    printFace(redFace);
    printFace(blueFace);
    printFace(orangeFace);
    printFace(yellowFace);
    printFace(greenFace);
    //}
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
            whiteFace[0] = orangeFace[0];
            orangeFace[0] = yellowFace[0];
            yellowFace[0] = redFace[0];
            redFace[0] = temp;
        }
        else if (getCenter(face) == Color::orange)
        {
            std::vector<Color> temp = whiteFace[0];
            whiteFace[0] = blueFace[0];
            blueFace[0] = yellowFace[0];
            yellowFace[0] = greenFace[0];
            greenFace[0] = temp;
        }/*
        else if (getCenter(face) == Cube::Cube::Color::yellow)
        {
            std::vector<Cube::Color> temp = redFace[0];
            redFace[0] = whiteFace[0];
            whiteFace[0] = orangeFace[0];
            orangeFace[0] = yellowFace[0];
            yellowFace[0] = temp;
        }
        else if (getCenter(face) == Cube::Cube::Color::blue)
        {
            std::vector<Cube::Color> temp = redFace[0];
            redFace[0] = whiteFace[0];
            whiteFace[0] = orangeFace[0];
            orangeFace[0] = yellowFace[0];
            yellowFace[0] = temp;
        }
        else if (getCenter(face) == Cube::Cube::Color::red)
        {
            std::vector<Cube::Color> temp = redFace[0];
            redFace[0] = whiteFace[0];
            whiteFace[0] = orangeFace[0];
            orangeFace[0] = yellowFace[0];
            yellowFace[0] = temp;
        }*/
    }
    else
    {

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

//int main() {
//    std::cout << isFaceSolved(redFace) << std::endl;
//    std::cout << isFaceSolved(whiteFace) << std::endl;
//    rotateFace(redFace, true);
//
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            printColor(whiteFace[i][j]);
//        }
//    }
//
//    //printCube();
//    return 0;
//}
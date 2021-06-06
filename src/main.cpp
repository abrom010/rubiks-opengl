#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <string>


//Base state White (top) Yellow (bottom) Green (front) Blue (back) Orange (left) Red (right)
enum class Color { white, yellow, green, red, blue, orange };

std::vector<std::vector<Color>> whiteFace
{
  {Color::white, Color::white, Color::white},
  {Color::white, Color::white, Color::white},
  {Color::white, Color::white, Color::white}
};
std::vector<std::vector<Color>> redFace
{
  {Color::red, Color::red, Color::red},
  {Color::red, Color::red, Color::red},
  {Color::red, Color::red, Color::red}
};
std::vector<std::vector<Color>> blueFace
{
  {Color::blue, Color::blue, Color::blue},
  {Color::blue, Color::blue, Color::blue},
  {Color::blue, Color::blue, Color::blue}
};
std::vector<std::vector<Color>> yellowFace{
  {Color::yellow, Color::yellow, Color::yellow},
  {Color::yellow, Color::yellow, Color::yellow},
  {Color::yellow, Color::yellow, Color::yellow}
};
std::vector<std::vector<Color>> orangeFace
{
  {Color::orange, Color::orange, Color::orange},
  {Color::orange, Color::orange, Color::orange},
  {Color::orange, Color::orange, Color::orange}
};
std::vector<std::vector<Color>> greenFace
{
  {Color::green, Color::green, Color::green},
  {Color::green, Color::green, Color::green},
  {Color::green, Color::green, Color::green}
};

std::vector<std::vector<std::vector<Color>>> faces
{
  whiteFace, redFace, blueFace, yellowFace, orangeFace, greenFace
};

void printColor(Color color)
{
    switch (color)
    {
    case Color::white:
        std::cout << "WHITE";
        break;
    case Color::green:
        std::cout << "GREEN";
        break;
    case Color::orange:
        std::cout << "ORANGE";
        break;
    case Color::yellow:
        std::cout << "YELLOW";
        break;
    case Color::blue:
        std::cout << "BLUE";
        break;
    case Color::red:
        std::cout << "RED";
        break;
    }
}

Color getCenter(std::vector<std::vector<Color>>& face)
{
    return face[1][1];
}

void printCube() {
    for (std::vector<std::vector<Color>> face : faces)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printColor(face[i][j]);
            }
        }
    }
}

void rotateFace(std::vector<std::vector<Color>>& face, bool clockwise)
{
    rotateFront(face, clockwise);
    rotateEdges(face, clockwise);
}



void rotateFront(std::vector<std::vector<Color>>& face, bool clockwise)
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
void rotateEdges(std::vector<std::vector<Color>>& face, bool clockwise)
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
        else if (getCenter(face) == Color::yellow)
        {
            std::vector<Color> temp = redFace[0];
            redFace[0] = whiteFace[0];
            whiteFace[0] = orangeFace[0];
            orangeFace[0] = yellowFace[0];
            yellowFace[0] = temp;
        }
        else if (getCenter(face) == Color::blue)
        {
            std::vector<Color> temp = redFace[0];
            redFace[0] = whiteFace[0];
            whiteFace[0] = orangeFace[0];
            orangeFace[0] = yellowFace[0];
            yellowFace[0] = temp;
        }
        else if (getCenter(face) == Color::red)
        {
            std::vector<Color> temp = redFace[0];
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

bool isFaceSolved(std::vector<std::vector<Color>> face)
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
    std::cout << isFaceSolved(redFace) << std::endl;
    std::cout << isFaceSolved(whiteFace) << std::endl;
    rotateFace(redFace, true);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printColor(whiteFace[i][j]);
        }
    }

    //printCube();
    return 0;
}
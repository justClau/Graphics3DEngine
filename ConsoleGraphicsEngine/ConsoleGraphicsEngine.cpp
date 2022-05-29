#include "olcConsoleGameEngine.h"

//3d vector
struct vec3d 
{
    float x, y, z;
};

struct triangle 
{
    vec3d p[3];
};

struct mesh
{
    std::vector<triangle> tris;
};


// The 3D Engine (Console Game Engine is used to create the console screen buffer)
class engine3d : public olcConsoleGameEngine
{
public:
    engine3d() 
    {
        m_sAppName = L"3D Demo";
    }


private:
    mesh meshCube;

public:
    bool OnUserCreate() override 
    {
        meshCube.tris = {
            //sud
            {0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f},

            //est
            {1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f},
            {1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, 1.0f},

            //nord
            {1.0f, 0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, 1.0f},
            {1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 1.0f,   0.0f, 0.0f, 1.0f},

            //vest
            {0.0f, 0.0f, 1.0f,   0.0f, 1.0f, 1.0f,   0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f, 0.0f},

            //top
            {0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f},
            {0.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 0.0f},

            //bottom
            {1.0f, 0.0f, 1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 1.0f,   0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f}



        };


        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {

        Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);

        for (auto tri : meshCube.tris)
        {

        }

        return true;
    }
};


int main()
{
    engine3d Demo;
    if (Demo.ConstructConsole(256, 240, 4, 4))
        Demo.Start();
    
    return 0;
}

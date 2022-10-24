#include "common/types.h"
#include "raylib.h"
#include <stdio.h>

#define MAX_POINTS 10
static int POINTS_COUNT = 1;

/* == Mini Metro Style Colors ======================================== */
#define MM_BG           CLITERAL(Color){ 243, 241, 237, 255 }
#define MM_YELLOW       CLITERAL(Color){ 250, 211, 1,   255 }
#define MM_RED          CLITERAL(Color){ 237, 45,  25,  255 }
#define MM_BLUE         CLITERAL(Color){ 35,  65,  147, 255 }
#define MM_BROWN        CLITERAL(Color){ 62,  49,  46,  255 }
#define MM_WATER_LIGHT  CLITERAL(Color){ 199, 234, 243, 255 }
#define MM_WATER_DARK   CLITERAL(Color){ 105, 203, 243, 255 }
/* ================================================================== */

void addPoint(Vector2 newPoint, Vector2* points) 
{
    points[POINTS_COUNT] = newPoint;
    POINTS_COUNT++;
    printf("Added New Point: (%f,%f). Point Count: %i\n", newPoint.x, newPoint.y, POINTS_COUNT);
}

void clearPoints(Vector2* points, size_t size)
{
    for(int i = 0; i<= size; i++)
    {
        points[i] = (Vector2){0,0};
    }

    POINTS_COUNT = 0;
}


void printVec2(Vector2 v)
{
    printf("x= %f, y= %f\n", v.x, v.y);
}

bool isZeroVector(Vector2 v)
{
    bool isEmpty = false;
    if(v.x == 0 && v.y == 0)
    {
        isEmpty = true;
    }
    return isEmpty;
}

int main() {

    InitWindow(800,600, "Game");

    Vector2 points[MAX_POINTS];
    points[0] = (Vector2){400,300};

    float delta = 0.0;

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();

        if(IsMouseButtonPressed(0))
        {
            Vector2 point = GetMousePosition();
            addPoint(point, points);
        }

        if(IsMouseButtonPressed(1))
        {
            clearPoints(points, MAX_POINTS);
        }

        ClearBackground(MM_BG);
        BeginDrawing();

        for (int i = 0; i <= MAX_POINTS - 1; ++i) 
        {
            Vector2 a = points[i];
            Vector2 b = points[i + 1];

            // FIXME Temporary solution to get rid of the first vector
            // point even though it there isn't one initially.
            if(isZeroVector(a) && isZeroVector(b))
            {
                DrawCircle(a.x,a.y, 8, MM_BLUE);
            }else
            {
                DrawCircle(a.x,a.y, 8, MM_BLUE);
                DrawLineEx(a,b,5, MM_BLUE);
            }

            // Draw circle at end of path
            if(i == MAX_POINTS - 1)
            {
                DrawCircle(b.x,b.y, 9, MM_YELLOW);
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}


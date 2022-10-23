#include "common/types.h"
#include "raylib.h"

#define MAX_POINTS 10

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
    static int POINTS_COUNT = 0;
    points[POINTS_COUNT] = newPoint;
    POINTS_COUNT++;
    printf("Added New Point: (%f,%f). Point Count: %i\n", newPoint.x, newPoint.y, POINTS_COUNT);
}

int main() {

    InitWindow(800,600, "Game");

    Vector2 points[MAX_POINTS];

    float delta = 0.0;

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();

        if(IsMouseButtonPressed(0))
        {
            Vector2 point = GetMousePosition();
            addPoint(point, points);
        }

        ClearBackground(GRAY);
        BeginDrawing();

            for (int i = 0; i <= MAX_POINTS - 1; i++) 
            {
                Vector2 point = points[i];
                DrawRectangle(point.x, point.y, 5,5, DARKGRAY);
                DrawLineStrip(points, MAX_POINTS, BLACK);
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}


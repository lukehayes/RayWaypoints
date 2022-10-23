#include "common/types.h"
#include "raylib.h"

#define MAX_POINTS 10

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


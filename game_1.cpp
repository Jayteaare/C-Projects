#include "raylib.h"

int main()
{
    // Window dimensions
    int width{ 800 };
    int height{ 450 };
    InitWindow(width, height, "Tallis' Window");

    // Circle coordinates
    int circle_x{ 200 };
    int circle_y{ 200 };

    int circle_radius{ 25 };

    // Circle edges
    int l_circle_x{ circle_x - circle_radius };
    int r_circle_x{ circle_x + circle_radius };
    int u_circle_y{ circle_y - circle_radius };
    int b_circle_y{ circle_y + circle_radius };

    // Rectangle coordinates
    int rect_x{ 400 };
    int rect_y{ 0 };

    int rect_length{ 50 };

    // Rectangle edges
    int l_rect_x{ rect_x };
    int r_rect_x{ rect_x + rect_length };
    int u_rect_y{ rect_y };
    int b_rect_y{ rect_y + rect_length };

    int direction{ 10 };

    // Collision with rectangle
    bool collision_with_rect = 
                                (b_rect_y >= u_circle_y) && 
                                (u_rect_y <= b_circle_y) && 
                                (r_rect_x >= l_circle_x) && 
                                (l_rect_x <= r_circle_x); 

    SetTargetFPS(60);

    while ( WindowShouldClose() == false )
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Collision
        if ( collision_with_rect )
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            // Game logic begins
            
            // Update shapes
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_rect_x = rect_x;
            r_rect_x = rect_x + rect_length;
            u_rect_y = rect_y;
            b_rect_y = rect_y + rect_length;

            //Update collision_with_rect
            collision_with_rect = 
                                (b_rect_y >= u_circle_y) && 
                                (u_rect_y <= b_circle_y) && 
                                (r_rect_x >= l_circle_x) && 
                                (l_rect_x <= r_circle_x); 

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(rect_x, rect_y, rect_length, rect_length, RED);

            // Move the rectangle
            rect_y += direction;
            if( rect_y > height || rect_y < 0)
            {
                direction = -direction;
            }

            // Move the circle
            if ( IsKeyDown(KEY_D) && circle_x < width )
            {
                circle_x += 10  ;
            }
            else if ( IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

            // Game logic ends
        }

        EndDrawing();
    }
}

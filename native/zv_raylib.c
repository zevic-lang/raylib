// A thin layer over raylib for the Zevic package `Raylib`.
// raylib passes small structs (Color, Vector2, Rectangle) by value, which depends on the platform ABI.
// This layer takes plain scalars (int, double, const char*) instead, so the Zevic side never passes a struct to C.
#include <raylib.h>

static Color zv_color(int r, int g, int b, int a) {
    Color c = { (unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a };
    return c;
}

// ---- window ----
void zv_rl_init_window(int w, int h, const char *title) { InitWindow(w, h, title); }
void zv_rl_close_window(void) { CloseWindow(); }
int zv_rl_window_should_close(void) { return WindowShouldClose() ? 1 : 0; }
int zv_rl_is_window_ready(void) { return IsWindowReady() ? 1 : 0; }
void zv_rl_set_target_fps(int fps) { SetTargetFPS(fps); }
int zv_rl_screen_width(void) { return GetScreenWidth(); }
int zv_rl_screen_height(void) { return GetScreenHeight(); }

// ---- time ----
double zv_rl_frame_time(void) { return (double)GetFrameTime(); }
double zv_rl_time(void) { return GetTime(); }
int zv_rl_fps(void) { return GetFPS(); }

// ---- drawing ----
void zv_rl_begin_drawing(void) { BeginDrawing(); }
void zv_rl_end_drawing(void) { EndDrawing(); }
void zv_rl_clear_background(int r, int g, int b, int a) { ClearBackground(zv_color(r, g, b, a)); }

void zv_rl_draw_text(const char *text, int x, int y, int size, int r, int g, int b, int a) {
    DrawText(text, x, y, size, zv_color(r, g, b, a));
}
int zv_rl_measure_text(const char *text, int size) { return MeasureText(text, size); }

void zv_rl_draw_rect(int x, int y, int w, int h, int r, int g, int b, int a) {
    DrawRectangle(x, y, w, h, zv_color(r, g, b, a));
}
void zv_rl_draw_rect_lines(int x, int y, int w, int h, int r, int g, int b, int a) {
    DrawRectangleLines(x, y, w, h, zv_color(r, g, b, a));
}
void zv_rl_draw_circle(int cx, int cy, double radius, int r, int g, int b, int a) {
    DrawCircle(cx, cy, (float)radius, zv_color(r, g, b, a));
}
void zv_rl_draw_line(int x1, int y1, int x2, int y2, int r, int g, int b, int a) {
    DrawLine(x1, y1, x2, y2, zv_color(r, g, b, a));
}
void zv_rl_draw_fps(int x, int y) { DrawFPS(x, y); }

// ---- input ----
int zv_rl_is_key_down(int key) { return IsKeyDown(key) ? 1 : 0; }
int zv_rl_is_key_pressed(int key) { return IsKeyPressed(key) ? 1 : 0; }
int zv_rl_is_key_released(int key) { return IsKeyReleased(key) ? 1 : 0; }
int zv_rl_mouse_x(void) { return GetMouseX(); }
int zv_rl_mouse_y(void) { return GetMouseY(); }
int zv_rl_is_mouse_down(int button) { return IsMouseButtonDown(button) ? 1 : 0; }
int zv_rl_is_mouse_pressed(int button) { return IsMouseButtonPressed(button) ? 1 : 0; }

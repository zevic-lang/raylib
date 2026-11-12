# Raylib

[raylib](https://www.raylib.com/) for [Zevic](https://github.com/zevic-lang/zevic): a window, 2D drawing, keyboard and mouse. The public API uses only Zevic types; a small C layer (`native/zv_raylib.c`) takes plain numbers, so no struct is ever passed by value to C.

This first version covers the basics. Textures, sound, fonts and 3D are not wrapped yet.

## Install

Needs raylib 5 and its development files (`brew install raylib`, or build it from source; on Debian and Ubuntu there may be no package).

```
zevpm get zevic-lang/zevic-raylib@v0.1.0
```

or in `zevic.toml`:

```
[deps]
Raylib = { git = "https://github.com/zevic-lang/zevic-raylib", tag = "v0.1.0" }
```

If raylib is not in a standard place, add its folder in your own `zevic.toml`:

```
[native]
lib_dirs = ["/opt/raylib/lib"]
include_dirs = ["/opt/raylib/include"]
```

## Use

```
module Main

import Raylib

fn Main() {
    Raylib.InitWindow(800, 450, "hello")
    defer Raylib.CloseWindow()
    Raylib.SetTargetFps(60)

    while (!Raylib.WindowShouldClose()) {
        Raylib.BeginDrawing()
        Raylib.ClearBackground(Raylib.RayWhite)
        Raylib.DrawText("Hello from Zevic", 190, 200, 20, Raylib.Gray)
        Raylib.EndDrawing()
    }
}
```

A bigger one is in `examples/bounce`: `cd examples/bounce && zevpm run`.

## API

| | |
| --- | --- |
| `InitWindow(w, h, title)` `CloseWindow()` `WindowShouldClose()` `SetTargetFps(n)` `ScreenWidth()` `ScreenHeight()` | the window |
| `FrameTime()` `Time()` `Fps()` | timing |
| `BeginDrawing()` `EndDrawing()` `ClearBackground(c)` | one frame |
| `DrawText` `MeasureText` `DrawRect` `DrawRectLines` `DrawCircle` `DrawLine` `DrawFps` | drawing |
| `IsKeyDown(k)` `IsKeyPressed(k)` `IsKeyReleased(k)` `KeySpace` `KeyEscape` `KeyEnter` `KeyUp` `KeyDown` `KeyLeft` `KeyRight` `KeyA` `KeyD` `KeyS` `KeyW` | keyboard |
| `MouseX()` `MouseY()` `IsMouseDown(b)` `IsMousePressed(b)` `MouseLeft` `MouseRight` `MouseMiddle` | mouse |
| `Color.New(r, g, b, a)` `c.WithAlpha(a)` and the palette (`Red`, `Blue`, `RayWhite`, ...) | colors |

Call everything from the main thread, and only between `InitWindow` and `CloseWindow`.

## Test

```
zevpm test
```

The tests need no window. Opening one needs a display, so the drawing functions are checked by running `examples/bounce` by hand.

## License

Apache-2.0

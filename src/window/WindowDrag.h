#pragma once

#include <raylib.h>

class WindowDrag {
public:
  void Update();

private:
  bool dragging = false;
  Vector2 mouse_offset = {0, 0};
};

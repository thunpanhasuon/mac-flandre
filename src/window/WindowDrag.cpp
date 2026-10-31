#include "WindowDrag.h"

void WindowDrag::Update() {
  Vector2 mouse = GetMousePosition();

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    dragging = true;
    mouse_offset = mouse;
  }

  if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
    dragging = false;
  }

  if (dragging) {
    Vector2 window_position = GetWindowPosition();
    SetWindowPosition((int)(window_position.x + mouse.x - mouse_offset.x),
                      (int)(window_position.y + mouse.y - mouse_offset.y));
  }
}

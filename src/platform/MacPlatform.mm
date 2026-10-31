#import <Cocoa/Cocoa.h>

#include "MacPlatform.h"

Vector2 GetMacOsGlobalMousePosition() {
  NSPoint mouse = [NSEvent mouseLocation];
  return {
    (float)mouse.x,
    (float)mouse.y,
  };
}

void ConfigureMacOsWindow() {
  NSWindow *window = [[NSApp windows] firstObject];
  if (window) {
    [window setCollectionBehavior:
        NSWindowCollectionBehaviorCanJoinAllSpaces |
        NSWindowCollectionBehaviorFullScreenAuxiliary];
  }
}

#include "assets/AssetManager.h"
#include "animation/Animation.h"
#include "platform/MacPlatform.h"
#include "window/WindowDrag.h"
#include <string>
#include <vector>
#include <raylib.h>


class Flandre {
  
  private: 
  int idle_frame = 0;
  int look_left_frame = 0;
  int look_right_frame = 0;
  int reach_frame = 0;
  int wave_frame = 0;
  int hand_to_face_frame = 0;
  int down_frame = 0;

  std::vector<Texture2D> flan_sprites; 
  std::vector<Texture2D> flan_wings; 
  std::vector<Texture2D> left_look_sprites; 
  std::vector<Texture2D> right_look_sprites;
  std::vector<Texture2D> reach_sprites;
  std::vector<Texture2D> wave_sprites;
  std::vector<Texture2D> hand_to_face_sprites;
  std::vector<Texture2D> down_sprites;


  public: 

    Vector2 flan_position = {0, 0};
    Vector2 flan_wings_offset = {1, 5}; 
    float scale = 3.0f;

    void LoadTextures() {
      AssetManager assets;
      flan_sprites = assets.LoadAsset("asset/flandre.json", "idle");
      flan_wings = assets.LoadAsset("asset/flandre.json", "wings");
      left_look_sprites = assets.LoadAsset("asset/flandre.json", "lookLeft");
      right_look_sprites = assets.LoadAsset("asset/flandre.json", "lookRight");
      reach_sprites = assets.LoadAsset("asset/flandre.json", "reach");
      wave_sprites = assets.LoadAsset("asset/flandre.json", "wave");
      hand_to_face_sprites = assets.LoadAsset("asset/flandre.json", "handToFace");
      down_sprites = assets.LoadAsset("asset/flandre.json", "down");
    }

    void UnloadTextures() {
      for (std::size_t i = 0; i < flan_sprites.size(); i++) {
        UnloadTexture(flan_sprites[i]);
      }
      flan_sprites.clear();

      for (std::size_t i = 0; i < flan_wings.size(); i++) {
        UnloadTexture(flan_wings[i]);
      }
      flan_wings.clear();

      for (std::size_t i = 0; i < left_look_sprites.size(); i++) {
        UnloadTexture(left_look_sprites[i]);
      }
      left_look_sprites.clear();

      for (std::size_t i = 0; i < right_look_sprites.size(); i++) {
        UnloadTexture(right_look_sprites[i]);
      }
      right_look_sprites.clear();

      for (std::size_t i = 0; i < reach_sprites.size(); i++) {
        UnloadTexture(reach_sprites[i]);
      }
      reach_sprites.clear();

      for (std::size_t i = 0; i < wave_sprites.size(); i++) {
        UnloadTexture(wave_sprites[i]);
      }
      wave_sprites.clear();

      for (std::size_t i = 0; i < hand_to_face_sprites.size(); i++) {
        UnloadTexture(hand_to_face_sprites[i]);
      }
      hand_to_face_sprites.clear();

      for (std::size_t i = 0; i < down_sprites.size(); i++) {
        UnloadTexture(down_sprites[i]);
      }
      down_sprites.clear();
    }

    Vector2 flan_jealousy(int monitor_w, int monitor_h) {
      Vector2 user_mouse = GetMacOsGlobalMousePosition(); 
      float cen_x = monitor_w / 2.0f; 
      float cen_y = monitor_h / 2.0f; 
      float safe_zoon = 300.0f; 
      if (user_mouse.y > cen_y) {
        if (user_mouse.x < cen_x - safe_zoon) {
          return {1, 0};
        }
        if (user_mouse.x > cen_x + safe_zoon){
          return {0, 1};
        }
      } 

      return {0, 0};
    }
    
    void updateIdleFrames(float &timer) {
      if (timer >= 0.15f) {
        timer = 0.0f;
        idle_frame = (idle_frame + 1) % 5;
      }
    }

    void updateLookLeftFrames(float &timer) {
      if (timer >= 0.15f) {
        timer = 0.0f;
        look_left_frame = (look_left_frame + 1) % 4;
      }
    }

    void updateLookRightFrames(float &timer) {
      if (timer >= 0.15f) {
        timer = 0.0f;
        look_right_frame = (look_right_frame + 1) % 4;
      }
    }

    void updateReachFrames(float &timer) {
      if (timer >= 0.15f) {
        timer = 0.0f;
        reach_frame = (reach_frame + 1) % 9;
      }
    }

    void updateWaveFrames(float &timer) {
      if (timer >= 0.15f) {
        timer = 0.0f;
        wave_frame = (wave_frame + 1) % 9;
      }
    }

    void updateHandToFaceFrames(float &timer) {
      if (timer >= 0.15f) {
        timer = 0.0f;
        hand_to_face_frame = (hand_to_face_frame + 1) % 6;
      }
    }

    void updateDownFrames(float &timer) {
      if (timer >= 0.15f) {
        timer = 0.0f;
        down_frame = (down_frame + 1) % 4;
      }
    }

    void DrawFlandre() {
      DrawTextureEx(flan_wings[idle_frame], 
          {flan_position.x + flan_wings_offset.x * scale, 
           flan_position.y + flan_wings_offset.y * scale
          }, 
          0.0f, 
          scale,
          WHITE
      );
      DrawTextureEx(flan_sprites[idle_frame], {flan_position.x, flan_position.y}, 0.0f, scale, WHITE);
    }

    void DrawReach() {
      DrawTextureEx(reach_sprites[reach_frame], flan_position, 0.0f, scale, WHITE);
    }

    void DrawWave() {
      DrawTextureEx(wave_sprites[wave_frame], flan_position, 0.0f, scale, WHITE);
    }

    void DrawHandToFace() {
      DrawTextureEx(hand_to_face_sprites[hand_to_face_frame], flan_position, 0.0f, scale, WHITE);
    }

    void DrawDown() {
      DrawTextureEx(down_sprites[down_frame], flan_position, 0.0f, scale, WHITE);
    }

    void DrawLeft() {
      DrawTextureEx(left_look_sprites[look_left_frame], {flan_position.x, flan_position.y}, 0.0f, scale, WHITE);
    }

    void DrawRight() {
      DrawTextureEx(right_look_sprites[look_right_frame], {flan_position.x, flan_position.y}, 0.0f, scale, WHITE);
    }


};

int main() {
    constexpr int screenWidth = 400;
    constexpr int screenHeight = 300;

    SetConfigFlags(
        FLAG_WINDOW_UNDECORATED |
        FLAG_WINDOW_TRANSPARENT |
        FLAG_WINDOW_TOPMOST
    );

    InitWindow(screenWidth, screenHeight, "Pets - Hello Raylib (C++)");
    SetTargetFPS(60);

    ConfigureMacOsWindow();
    int monitor_w = GetMonitorWidth(0);
    int monitor_h = GetMonitorHeight(0);

    Flandre flan;
    flan.flan_position = {(screenWidth / 2) - 150, (screenHeight / 2) - 100};
    flan.LoadTextures();

    float timer = 0.0f;

    float animation_timer = 0.0f;
    int animation = 4; // Start with down.

    WindowDrag window_drag;
    
    while (!WindowShouldClose()) {
        timer += GetFrameTime();
       
        Vector2 jealousy = flan.flan_jealousy(monitor_w, monitor_h);
        if (jealousy.x == 1 /* left */) {
          flan.updateLookLeftFrames(timer);
        } else if (jealousy.y == 1 /* right */) {
          flan.updateLookRightFrames(timer);
        } else {
          animation_timer += GetFrameTime();
          float duration = 10.0f;
          if (animation == 4) {
            duration = 20.0f;
          }
          if (animation_timer >= duration) {
            animation_timer = 0.0f;
            timer = 0.0f;
            animation = (animation + 1) % 5;
          }

          switch (animation) {
            case 0:
              flan.updateIdleFrames(timer);
              break;
            case 1:
              flan.updateReachFrames(timer);
              break;
            case 2:
              flan.updateWaveFrames(timer);
              break;
            case 3:
              flan.updateHandToFaceFrames(timer);
              break;
            case 4:
              flan.updateDownFrames(timer);
              break;
          }
        }
                
        window_drag.Update();

        BeginDrawing();
        ClearBackground(BLANK);

        if (jealousy.x == 1) {
          flan.DrawLeft();
        } else if (jealousy.y == 1) {
          flan.DrawRight();
        } else {
          switch (animation) {
            case 0:
              flan.DrawFlandre();
              break;
            case 1:
              flan.DrawReach();
              break;
            case 2:
              flan.DrawWave();
              break;
            case 3:
              flan.DrawHandToFace();
              break;
            case 4:
              flan.DrawDown();
              break;
          }
        }

        EndDrawing();
    }
    
    flan.UnloadTextures();
    CloseWindow();
    return 0;
}

#pragma once

enum class AnimationState {
  Idle,
  LookLeft,
  LookRight,
};

struct Animation {
  int currentFrame = 0;
  float elapsed = 0.0f;
  AnimationState state = AnimationState::Idle;
};

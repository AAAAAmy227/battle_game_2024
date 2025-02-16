#pragma once
#include "battle_game/core/unit.h"

namespace battle_game::unit {
class Blitz : public Unit {
 public:
  Blitz(GameCore *game_core, uint32_t id, uint32_t player_id);
  void Render() override;
  void Update() override;
  [[nodiscard]] bool IsHit(glm::vec2 position) const override;
  [[nodiscard]] float GetHealthScale() const override;
  [[nodiscard]] float GetSpeedScale() const override;
  [[nodiscard]] float GetDamageScale() const override;
  [[nodiscard]] uint32_t GetManaPoint() const; //actual MP e.g.1-100
  [[nodiscard]] float GetMP() const; //[0,1]
  //void RenderLifeBar() override;
  void RenderHelper() override;
  void RenderManaBar();
  uint32_t mana_point_{0};
  uint32_t mana_point_max_{100};
 protected:

  bool manabar_display_{true};
  glm::vec2 manabar_offset_ = {0.0f, 1.2f};
  glm::vec4 background_manabar_color_ = {0.0f, 0.0f, 1.0f, 0.9f};
  glm::vec4 front_manabar_color_ = {0.0f, 1.0f, 1.0f, 0.9f};
  glm::vec4 fadeout_manabar_color_ = {1.0f, 1.0f, 1.0f, 0.5f};
  float fadeout_MP_ = 1;
  float manabar_length_{2.4f};
  void TankMove(float move_speed, float rotate_angular_speed);
  void TurretRotate();
  void Fire();
  [[nodiscard]] const char *UnitName() const override;
  [[nodiscard]] const char *Author() const override;
  friend class MPBullet;
  float turret_rotation_{0.0f};
  uint32_t fire_count_down_{0};
  uint32_t doge_count_down_{0};
  uint32_t energy_ball_count_down_{0};
  uint32_t mine_count_down_{0};
};
}  // namespace battle_game::unit

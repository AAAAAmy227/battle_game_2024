#pragma once
#include "battle_game/core/bullet.h"

namespace battle_game::bullet {
class EnergyBall : public Bullet {
 public:
  EnergyBall(GameCore *core,
             uint32_t id,
             uint32_t unit_id,
             uint32_t player_id,
             glm::vec2 position,
             float rotation,
             float damage_scale,
             glm::vec2 velocity);
  ~EnergyBall() override;
  void Render() override;
  void Update() override;
  //[[nodiscard]] uint32_t GetManaPointConsumption() const;
  static const uint32_t mana_point_consumption_{50};
 private:
  glm::vec2 velocity_{};
  //uint32_t mana_point_consumption_{50};
};
}  // namespace battle_game::bullet

#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <string>

enum class TipoEnemigo {
    Melee,
    RangeFisico,
    RangeMagico,
    Boss
};

class Enemy : public Entity {
public:
    Enemy(const std::string& name, TipoEnemigo tipo);
    ~Enemy();

    void update() override;
    void render() override;
    // Define el comportamiento de la IA en tiempo real
    void comportamientoIA(Entity* target);

    TipoEnemigo getTipo() const;

private:
    TipoEnemigo tipoEnemigo;
};

#endif // ENEMY_H

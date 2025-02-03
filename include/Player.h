#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Inventory.h"
#include "Ability.h"
#include "SkillTree.h"
#include <string>

class Player : public Entity {
public:
    Player(const std::string& clase);
    ~Player();

    void update() override;
    void render() override;
    void realizarAtaqueBasico();
    void bloquear();
    void usarHabilidad(int id);

private:
    std::string clase;
    Inventory* inventario;
    SkillTree* skillTree;
    // Otros atributos específicos del jugador
};

#endif // PLAYER_H

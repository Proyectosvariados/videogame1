#include "Player.h"
#include <iostream>

Player::Player(const std::string& clase) : Entity("Jugador"), clase(clase) {
    inventario = new Inventory();
    skillTree = new SkillTree();
    // Configuración inicial según la clase elegida
    if(clase == "Cuerpo a Cuerpo") {
        ataqueFisico = 15;
        defensaFisica = 10;
        velocidad = 5;
    } else if(clase == "Distancia") {
        ataqueMagico = 15;
        velocidad = 7;
        rango = 3;
    } else if(clase == "Soporte") {
        regenVida = 3;
        defensaMagica = 10;
    }
}

Player::~Player() {
    delete inventario;
    delete skillTree;
}

void Player::update() {
    // Actualización general de la entidad y otros aspectos específicos del jugador
    Entity::update();
    // Aquí se podría actualizar el inventario, cooldowns de habilidades, etc.
}

void Player::render() {
    std::cout << "Jugador (" << clase << "): " << vida << "/" << vidaMaxima << " HP" << std::endl;
    // Se puede añadir la visualización del inventario y habilidades
}

void Player::realizarAtaqueBasico(Entity* target) {
    std::cout << name << " ataca a " << target->getName() << " con ataque básico." << std::endl;
    atacar(target);
}

void Player::bloquear() {
    // Ejemplo sencillo de bloqueo: aumenta temporalmente la defensa
    std::cout << name << " se bloquea para reducir daño." << std::endl;
    defensaFisica += 5;
    // En una implementación real se debería restaurar la defensa tras un tiempo o tras la acción
}

void Player::usarHabilidad(int id, Entity* target) {
    // Llamar al SkillTree para activar la habilidad correspondiente (este es un ejemplo)
    std::cout << name << " usa habilidad con ID: " << id << std::endl;
    // Aquí se implementaría la activación de la habilidad y sus efectos sobre el target
}

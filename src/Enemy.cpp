#include "Enemy.h"
#include <iostream>
#include <cstdlib>

Enemy::Enemy(const std::string& name, TipoEnemigo tipo) : Entity(name), tipoEnemigo(tipo) {
    // Configurar atributos según el tipo de enemigo
    switch(tipo) {
        case TipoEnemigo::Melee:
            ataqueFisico = 12;
            defensaFisica = 8;
            break;
        case TipoEnemigo::RangeFisico:
            ataqueFisico = 10;
            rango = 3;
            break;
        case TipoEnemigo::RangeMagico:
            ataqueMagico = 14;
            rango = 4;
            break;
        case TipoEnemigo::Boss:
            vidaMaxima = 300;
            vida = vidaMaxima;
            ataqueFisico = 20;
            break;
    }
}

Enemy::~Enemy() {}

void Enemy::update() {
    // Actualizar la lógica interna del enemigo
    Entity::update();
}

void Enemy::render() {
    std::cout << "Enemigo (" << name << "): " << vida << "/" << vidaMaxima << " HP" << std::endl;
}

void Enemy::comportamientoIA(Entity* target) {
    // Ejemplo muy simple de comportamiento IA: decisión aleatoria entre atacar o esperar
    if (target && vida > 0) {
        int decision = rand() % 2; // 0: atacar, 1: esperar
        if(decision == 0) {
            std::cout << name << " ataca a " << target->getName() << std::endl;
            atacar(target);
        } else {
            std::cout << name << " se mantiene a la espera." << std::endl;
        }
    }
}

TipoEnemigo Enemy::getTipo() const {
    return tipoEnemigo;
}

#include "Entity.h"
#include <iostream>

Entity::Entity() : name("Entidad"), posX(0), posY(0),
                   vida(100), vidaMaxima(100),
                   ataqueFisico(10), defensaFisica(5),
                   velocidad(5), velocidadAtaque(5),
                   defensaMagica(5), ataqueMagico(10),
                   probCritico(0.1f), rango(1),
                   regenVida(1), nivel(1) {
}

Entity::Entity(const std::string& name) : name(name), posX(0), posY(0),
                   vida(100), vidaMaxima(100),
                   ataqueFisico(10), defensaFisica(5),
                   velocidad(5), velocidadAtaque(5),
                   defensaMagica(5), ataqueMagico(10),
                   probCritico(0.1f), rango(1),
                   regenVida(1), nivel(1) {
}

Entity::~Entity() {}

void Entity::update() {
    // Por ejemplo, regenerar vida
    if (vida < vidaMaxima) {
        vida += regenVida;
        if (vida > vidaMaxima) vida = vidaMaxima;
    }
}

void Entity::render() {
    // Renderizado por consola (se debe reemplazar por gráficos en el juego real)
    std::cout << name << " (" << vida << "/" << vidaMaxima << " HP)" << std::endl;
}

void Entity::recibirDanio(int dano) {
    int danoReal = dano - defensaFisica;
    if (danoReal < 0) {
        danoReal = 0;
    }
    vida -= danoReal;
    if (vida < 0) vida = 0;
}

void Entity::atacar(Entity* target) {
    if (target) {
        target->recibirDanio(ataqueFisico);
    }
}

std::string Entity::getName() const {
    return name;
}

int Entity::getVida() const {
    return vida;
}

void Entity::setVida(int vida) {
    this->vida = vida;
}

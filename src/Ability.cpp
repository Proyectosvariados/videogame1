#include "Ability.h"
#include <iostream>
#include <chrono>

Ability::Ability(const std::string& nombre, TipoHabilidad tipo, int cooldown)
    : nombre(nombre), tipo(tipo), cooldown(cooldown), cooldownActual(0) {
    lastActivationTime = std::chrono::steady_clock::now();
}

Ability::~Ability() {}

void Ability::activar() {
    if (estaDisponible()) {
        std::cout << "Habilidad " << nombre << " activada." << std::endl;
        // Aquí se implementa el efecto de la habilidad
        cooldownActual = cooldown;
        lastActivationTime = std::chrono::steady_clock::now();
    } else {
        std::cout << "Habilidad " << nombre << " en cooldown." << std::endl;
    }
}

void Ability::actualizarCooldown() {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastActivationTime).count();
    if (elapsed >= cooldown) {
        cooldownActual = 0;
    } else {
        cooldownActual = cooldown - static_cast<int>(elapsed);
    }
}

bool Ability::estaDisponible() const {
    return cooldownActual <= 0;
}

std::string Ability::getNombre() const {
    return nombre;
}

int Ability::getCooldown() const {
    return cooldown;
}

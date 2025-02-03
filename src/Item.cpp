#include "Item.h"
#include <iostream>

Item::Item(const std::string& nombre, TipoItem tipo) : nombre(nombre), tipo(tipo) {
    // Ejemplo: si el item es un arma, asignar un bonus de ataque
    if(tipo == TipoItem::Arma) {
        bonusAtributos["ataqueFisico"] = 5;
    }
}

Item::~Item() {}

std::string Item::getNombre() const {
    return nombre;
}

TipoItem Item::getTipo() const {
    return tipo;
}

const std::map<std::string, int>& Item::getBonos() const {
    return bonusAtributos;
}

void Item::aplicarEfecto() {
    std::cout << "Aplicando efecto del item " << nombre << std::endl;
    // Aquí se implementa la lógica de efecto (por ejemplo, aumentar estadísticas)
}

#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {}

Inventory::~Inventory() {
    // Liberar la memoria de los items almacenados
    for(auto item : items) {
        delete item;
    }
}

void Inventory::agregarItem(Item* item) {
    items.push_back(item);
}

void Inventory::removerItem(int index) {
    if(index >= 0 && index < static_cast<int>(items.size())) {
        delete items[index];
        items.erase(items.begin() + index);
    }
}

void Inventory::usarItem(int index) {
    if(index >= 0 && index < static_cast<int>(items.size())) {
        std::cout << "Usando item: " << items[index]->getNombre() << std::endl;
        // Aquí se implementa la lógica de uso del item
    }
}

void Inventory::equiparItem(int index) {
    if(index >= 0 && index < static_cast<int>(items.size())) {
        std::cout << "Equipando item: " << items[index]->getNombre() << std::endl;
        // Aquí se implementa la lógica de equipamiento
    }
}

void Inventory::mostrarInventario() const {
    std::cout << "Inventario:" << std::endl;
    for(int i = 0; i < static_cast<int>(items.size()); i++) {
        std::cout << i << ": " << items[i]->getNombre() << std::endl;
    }
}

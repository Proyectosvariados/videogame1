#include "SkillTree.h"
#include <iostream>

SkillTree::SkillTree() {}

SkillTree::~SkillTree() {
    for(auto habilidad : habilidades) {
        delete habilidad;
    }
}

void SkillTree::agregarHabilidad(Ability* habilidad) {
    habilidades.push_back(habilidad);
}

void SkillTree::subirNivelHabilidad(int index) {
    if(index >= 0 && index < static_cast<int>(habilidades.size())) {
        std::cout << "Subiendo nivel de la habilidad: " << habilidades[index]->getNombre() << std::endl;
        // Aquí se implementa la lógica para mejorar la habilidad
    }
}

void SkillTree::mostrarHabilidades() const {
    std::cout << "Árbol de habilidades:" << std::endl;
    for (int i = 0; i < static_cast<int>(habilidades.size()); i++) {
        std::cout << i << ": " << habilidades[i]->getNombre() << std::endl;
    }
}

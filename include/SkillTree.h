#ifndef SKILLTREE_H
#define SKILLTREE_H

#include "Ability.h"
#include <vector>

class SkillTree {
public:
    SkillTree();
    ~SkillTree();

    void agregarHabilidad(Ability* habilidad);
    void subirNivelHabilidad(int index);
    void mostrarHabilidades() const;

private:
    std::vector<Ability*> habilidades;
};

#endif // SKILLTREE_H

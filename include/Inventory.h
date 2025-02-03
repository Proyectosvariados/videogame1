#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>

class Inventory {
public:
    Inventory();
    ~Inventory();

    void agregarItem(Item* item);
    void removerItem(int index);
    void usarItem(int index);
    void equiparItem(int index);

    void mostrarInventario() const;

private:
    std::vector<Item*> items;
};

#endif // INVENTORY_H

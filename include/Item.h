#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>

enum class TipoItem {
    Casco,
    Armadura,
    Arma,
    Mochila,
    Consumible
};

class Item {
public:
    Item(const std::string& nombre, TipoItem tipo);
    virtual ~Item();

    std::string getNombre() const;
    TipoItem getTipo() const;

    // Bonus de atributos (por ejemplo, ataque, defensa, etc.)
    const std::map<std::string, int>& getBonos() const;

    // Método para aplicar el efecto del item (según su tipo)
    virtual void aplicarEfecto();

protected:
    std::string nombre;
    TipoItem tipo;
    std::map<std::string, int> bonusAtributos;
};

#endif // ITEM_H

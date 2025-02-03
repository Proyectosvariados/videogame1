#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <chrono>

enum class TipoHabilidad {
    Activa,
    Pasiva
};

class Ability {
public:
    Ability(const std::string& nombre, TipoHabilidad tipo, int cooldown);
    virtual ~Ability();

    // Para activar la habilidad (usada para habilidades activas)
    virtual void activar();
    // Actualiza el tiempo de cooldown
    virtual void actualizarCooldown();

    bool estaDisponible() const;

    std::string getNombre() const;
    int getCooldown() const;

protected:
    std::string nombre;
    TipoHabilidad tipo;
    int cooldown; // Tiempo de cooldown en milisegundos
    int cooldownActual; // Tiempo restante de cooldown

    // Se puede utilizar std::chrono para gestionar el tiempo
    std::chrono::steady_clock::time_point lastActivationTime;
};

#endif // ABILITY_H

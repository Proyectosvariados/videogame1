#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
    Entity();
    Entity(const std::string& name);
    virtual ~Entity();

    // Métodos virtuales para permitir sobreescritura en clases derivadas
    virtual void update();
    virtual void render();

    // Métodos de combate
    virtual void recibirDanio(int dano);
    virtual void atacar(Entity* target);

    // Getters y setters
    std::string getName() const;
    int getVida() const;
    void setVida(int vida);

protected:
    std::string name;
    int posX;
    int posY;
    int vida;
    int vidaMaxima;
    int ataqueFisico;
    int defensaFisica;
    int velocidad;
    int velocidadAtaque;
    int defensaMagica;
    int ataqueMagico;
    float probCritico;
    int rango;
    int regenVida;
    int nivel;
};

#endif // ENTITY_H

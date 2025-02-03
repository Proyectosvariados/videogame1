# Roguelike Medieval Fantasy

**Co-created by [Adriano García-Giralda Milena](https://github.com/adrianoggm) and [Nicolás Hideo Vílchez Imanishi](https://github.com/your-link)**

## Overview

This project is a video game developed in **C++** that combines classic roguelike elements with real-time gameplay and multiple players (1-4). The game is set in a medieval fantasy world where magic and melee coexist, and features procedural dungeon generation with a tileset similar to the style of *The Binding of Isaac* (4x4 cell layout).

## Features

- **Multiplayer:** Supports 1 to 4 players.
- **Real-time Gameplay:** Experience fast-paced action with various AI behaviors.
- **Procedural Dungeon Generation:** A dynamic 4x4 cell dungeon is generated each game using a customizable tileset.
- **Classes:** Choose from three distinct classes:
  - **Melee (Cuerpo a Cuerpo)**
  - **Ranged (Distancia)**
  - **Support (Soporte)**
- **Enemies:**
  - **Melee Enemies** (close combat)
  - **Physical Ranged Enemies**
  - **Magical Ranged Enemies**
  - **Boss Enemy** (with experience parameter)
- **Attributes:** Each character (players and enemies) have attributes such as:
  - Physical Attack
  - Physical Defense
  - Speed
  - Attack Speed
  - Life (HP)
  - Magical Defense
  - Magical Attack
  - Critical Hit Chance
  - Range
  - Life Regeneration
  - Level
- **Inventory & Equipment:** Manage your items with a full inventory system including equipment slots for:
  - Helmet (casco)
  - Armor (armadura)
  - Weapon (arma)
  - Backpack (mochila)
- **Combat Mechanics:**
  - Basic Attack
  - Blocking
- **Abilities System:**
  - Active Abilities (with cooldown)
  - Passive Abilities
  - Level up your abilities (2 active and 2 passive in a skill tree)
- **Experience and Leveling:** Gain experience and level up your character.
- **Game Progression:** 5 levels culminating in a boss battle.
- **User Interface:**
  - Start screen with options: *Play*, *Continue*, *Options*, *Credits*, *Exit*
  - Save game management
  - Inventory menu with options to close, save, and finish the game.
  - HUD showing the party's health, the player’s own health, and the boss's health.
- **Sprite Management:** Automatic sprite scaling and tile adjustments for the dungeon.

## Getting Started

### Prerequisites

- A C++ compiler supporting C++11 (or higher).
- [CMake](https://cmake.org/) (if you choose to use it for building the project) or a suitable Makefile.
- SDL, SFML, or another graphics library (if you plan to implement a graphical interface).

### Building the Project

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/your-username/roguelike-medieval-fantasy.git
   cd roguelike-medieval-fantasy

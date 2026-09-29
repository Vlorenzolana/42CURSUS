# 🎮 Cub3D

<p align="center">
  <img src="https://img.shields.io/badge/42-Project-blue?style=for-the-badge" alt="42 Project"/>
  <img src="https://img.shields.io/badge/Language-C-green?style=for-the-badge" alt="C"/>
  <img src="https://img.shields.io/badge/Graphics-MLX42-orange?style=for-the-badge" alt="MLX42"/>
</p>

<p align="center">
  <i>My first RayCaster with MLX42</i>
</p>

---

## 📖 Description

**cub3D** is a 42 school project inspired by the legendary game [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D) (1992), considered the first FPS in history. The goal is to create a simplified 3D graphics engine using the **Ray-Casting** technique.

The program renders a maze in pseudo-3D perspective from the player's point of view, allowing:
- 🚶 First-person movement (WASD)
- 🔄 Camera rotation (arrows or mouse)
- 🗺️ Custom map loading in `.cub` format
- 🎨 Customizable textures for walls, floor and ceiling

---

## 🧮 Algorithm: Ray-Casting with DDA

The project implements the **Ray-Casting** algorithm using **DDA (Digital Differential Analyzer)** to efficiently calculate ray intersections with map walls.

### How does it work?

```
                     Camera Shot
                  ←─────────────────→
                         ╱│╲
                        ╱ │ ╲
                       ╱  │  ╲
               Ray    ╱   │   ╲  Ray
                     ╱    │    ╲
                    ╱     │     ╲
                   ╱      │      ╲
                  ╱       │       ╲
                 ╱        ▼        ╲
            ┌───┬───┬───┬───┬───┬───┬───┐
            │   │   │ █ │ █ │ █ │   │   │
            ├───┼───┼───┼───┼───┼───┼───┤
            │   │   │   │   │   │   │   │
            ├───┼───┼───┼───┼───┼───┼───┤
            │ █ │   │ P │   │   │   │ █ │  ← 2D Map
            ├───┼───┼───┼───┼───┼───┼───┤
            │ █ │   │   │   │   │   │ █ │
            └───┴───┴───┴───┴───┴───┴───┘
```

1. **For each pixel column** on the screen, a ray is cast from the player's position
2. **DDA** calculates step by step which map cell the ray passes through
3. When the ray **hits a wall** (`'1'`), the perpendicular distance is calculated
4. The **vertical line height** is calculated inversely proportional to the distance
5. The **corresponding texture** is applied based on wall direction (N, S, E, W)

### DDA Advantages
- ✅ Avoids square root calculations
- ✅ Only uses additions and comparisons in the main loop
- ✅ O(n) complexity where n is the distance to the wall

---

## 📁 Project Structure

```
cub3D/
├── 📄 Makefile              # Project compilation
├── 📄 README.md             # This file
│
├── 📂 sources/              # Main source code
│   ├── main.c               # Entry point
│   ├── raycast.c            # Ray-casting algorithm (DDA)
│   ├── draw.c               # Wall rendering
│   ├── texture.c            # Texture management
│   ├── controls.c           # Player movement
│   ├── hooks.c              # Events and main loop
│   ├── parse_file.c         # .cub file parser
│   ├── parse_color.c        # F/C color parser
│   ├── parse_textures.c     # NO/SO/WE/EA texture parser
│   ├── load_map_parser.c    # Map validation
│   ├── check_utils.c        # Validation utilities
│   ├── initialize.c         # Structure initialization
│   ├── data_to_game.c       # Parsed data conversion
│   ├── gc.c                 # Garbage Collector
│   ├── free_utils.c         # Memory deallocation
│   ├── dup_map.c            # Map duplication
│   ├── read_file_to_array.c # File reading
│   └── utils.c              # Helper functions
│
├── 📂 bonus/                # Bonus source code
│   ├── minimap_bonus.c      # Minimap rendering
│   ├── minimap_utils_bonus.c # Minimap utilities
│   └── *_bonus.c            # Bonus versions of each file
│
├── 📂 includes/             # Headers
│   └── cub3d.h              # Main header
│
├── 📂 libft/                # 42's custom library
│   ├── sources/             # libft source code
│   └── include/libft.h      # libft header
│
├── 📂 MLX42/                # Graphics library
│   ├── src/                 # MLX42 source code
│   ├── include/             # MLX42 headers
│   └── build/               # Compiled library
│
├── 📂 maps/                 # Example maps
│   ├── map.cub              # Main map
│   └── *.cub                # Other test maps
│
└── 📂 textures/             # Game textures (PNG)
    ├── north.png
    ├── south.png
    ├── east.png
    └── west.png
```

---

## ✨ Implemented Bonus Features

### 🗺️ Minimap
A real-time minimap showing:
- Player position (centered)
- Surrounding walls
- Camera direction
- View that moves with the player

```
┌─────────────┐
│ █ █ █ █ █ █ │
│ █         █ │
│ █    ▲    █ │  ← Player centered
│ █         █ │
│ █ █ █ █ █ █ │
└─────────────┘
```

### 🖱️ Mouse Rotation
- Horizontal mouse movement = camera rotation
- Adjusted sensitivity for precise control
- Cursor hides during gameplay

---

## 🛠️ Compilation

### Prerequisites
- GCC or Clang
- Make
- CMake (for MLX42)
- Development libraries: `glfw`, `OpenGL`

### On Debian/Ubuntu systems:
```bash
sudo apt-get install build-essential cmake libglfw3-dev libgl1-mesa-dev
```

### Compilation

```bash
# Clone the repository
git clone https://github.com/Drewaan/cub3d.git
cd cub3d

# Clone MLX42 library (required)
git clone https://github.com/codam-coding-college/MLX42.git

# Compile mandatory version
make

# Compile bonus version (with minimap and mouse)
make bonus

# Clean object files
make clean

# Clean everything (including executable)
make fclean

# Rebuild from scratch
make re
```

---

## 🎮 Usage

```bash
# Run mandatory version
./cub3D maps/map.cub

# Run bonus version
./cub3D_bonus maps/map.cub
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `🖱️` | Rotate camera (bonus only) |
| `ESC` | Exit game |

---

## 🗺️ Map Format (.cub)

```
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png

F 220,100,0
C 135,206,235

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101011111011110001
11111111 1111111111111111111111
```

### Identifiers:
- `NO`, `SO`, `WE`, `EA`: Paths to wall textures
- `F`: Floor color (R,G,B)
- `C`: Ceiling color (R,G,B)

### Map Characters:
- `0`: Empty space (walkable)
- `1`: Wall
- `N`, `S`, `E`, `W`: Player's initial position and direction
- ` `: Space (outside map)

---

<p align="center">

<!-- ![Gameplay](./screenshots/gameplay.png) -->


### 📸 Gameplay View

<p align="center">
  <img src="https://raw.githubusercontent.com/Drewaan/cub3d/main/screenshots/gameplay_1.png" width="800" alt="Cub3D Gameplay 1">
</p>


<p align="center">
  <img src="https://raw.githubusercontent.com/Drewaan/cub3d/main/screenshots/gameplay_2.png" width="800" alt="Cub3D Gameplay 2">
</p>

### Minimap (Bonus)

<p align="center">
  <img src="https://raw.githubusercontent.com/Drewaan/cub3d/main/screenshots/minimap_detail.png" width="200" alt="Minimap Detail">
</p>

---

## 👥 Authors

| Author | GitHub |
|--------|--------|
| **aamaya-g** | [@Drewaan](https://github.com/Drewaan) |  
| **vlorenzo** | [@Vlorenzolana](https://github.com/Vlorenzolana)|

---

## 📚 References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Complete ray-casting tutorial
- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42) - Graphics library documentation
- [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D) - The original game that inspired this project

---

<p align="center">
  <b>42 Urduliz · 2025</b>
</p>

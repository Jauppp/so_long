<p align="center">
  <img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" alt="project-logo">
</p>
<p align="center">
	<img src="https://img.shields.io/github/last-commit/Jauppp/so_long?style=default&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/Jauppp/so_long?style=default&color=0080ff" alt="repo-top-language">
<p>
<p align="center">
	<!-- default option, no dependency badges. -->
</p>

<br><!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary><br>

- [ Overview](#-overview)
- [ Features](#-features)
- [ Repository Structure](#-repository-structure)
- [ Modules](#-modules)
- [ Getting Started](#-getting-started)
  - [ Installation](#-installation)
  - [ Usage](#-usage)
  - [ Tests](#-tests)
- [ Project Roadmap](#-project-roadmap)
- [ Contributing](#-contributing)
- [ License](#-license)
- [ Acknowledgments](#-acknowledgments)
</details>
<hr>

##  Overview

SO_LONG, is a 2D grid-based adventure game written in C and leveraging the LFT and MLX libraries. The projects core focus is on providing a level for users to traverse.The game is compiled using a custom Makefile that enables various tasks like building the entire project (`all`), cleaning up (`clean`), or recompiling specific sources (`fclean`). A helpful command, also included, provides a list of available actions. 

##  Features

|   |    Feature          | Description                                                                                             |
|----|---------------------|---------------------------------------------------------------------------------------------------------|
| ⚙️ | Architecture       | The project utilizes C language for game logic and uses Makefile to compile the game with LFT and MLX libraries. The final executable is named SO_LONG.                                               |
| 🔌 | Integrations       | The project relies upon external libraries, namely LFT (Linux Framework) and MLX for handling windows, graphics, and user inputs.                                                     |
| 📦 | Dependencies       | The project requires the `make` command and the LFT and MLX libraries for compilation and execution.             |

---

##  Repository Structure

```sh
└── /
    ├── Makefile
    ├── build
    │   ├── libft
    │   └── mlx
    ├── maps
    │   ├── bad_maps
    │   ├── map_01.ber
    │   ├── map_02.ber
    │   ├── map_03.ber
    │   ├── map_04.ber
    │   ├── small_map.ber
    │   ├── square_map.ber
    │   ├── tiny_map.ber
    │   └── tiny_tall.ber
    ├── project
    │   ├── Makefile
    │   ├── error_handling.c
    │   ├── hook_functions.c
    │   ├── init_sprites.c
    │   ├── init_utils.c
    │   ├── load_map.c
    │   ├── load_map_utils.c
    │   ├── main.c
    │   ├── map_handling.c
    │   ├── mem_handling.c
    │   ├── parsing.c
    │   ├── parsing_utils.c
    │   ├── player_moves.c
    │   ├── so_long.h
    │   ├── text.c
    │   ├── utils.c
    │   ├── win_screen.c
    │   └── window_handling.c
    └── sprites
        ├── bg.xpm
        ├── exit.xpm
        ├── exit_02.xpm
        ├── items.xpm
        ├── player.xpm
        ├── player_01.xpm
        ├── player_02.xpm
        ├── png
        ├── wall.xpm
        └── win_screen.xpm
```

##  Modules

<details closed><summary>.</summary>

| File| Summary|
| ---| ---|
| [Makefile](https://github.com/Jauppp/so_long/blob/master/Makefile) | This Makefile compiles a game called SO_LONG by assembling various C source files and linking with the LFT and MLX libraries. Upon execution, it generates an executable named SO_LONG. The file outlines targets like all, clean, fclean to run, clean, or recompile the project respectively. Other features include a help command that lists all possible actions, and even a kitty printout as a fun touch. |

</details>

<details closed><summary>maps</summary>

| File| Summary|
| ---                                                                                 | ---|
| [maps](https://github.com/Jauppp/so_long/blob/master/maps)         | This subdirectory countains eight maps of different sizes and complexity used to render the levels of the game ; all are considered to be valid maps.                            |
</details>

<details closed><summary>maps.bad_maps</summary>

| File| Summary|
| ---| ---|
| [bad.maps](https://github.com/Jauppp/so_long/blob/master/maps/bad_maps)| Maps in this subdirectory are considered invalid and were used to test the parsing. They are either too big, have missing elements (no player, no exit, no collectibles, or inaccessible items), or are not rectangular nor walled in.|
</details>

<details closed><summary>project</summary>

| File| Summary|
| ---| ---    |
| [load_map_utils.c](https://github.com/Jauppp/so_long/blob/master/project/load_map_utils.c)   | In this C file, three functions (load_player, load_decor, load_background) are defined to dynamically display specific images based on the corresponding elements (P, C, 1, etc.) at a particular position in the two-dimensional game map. The load_background function displays wall or background depending on the cell content, while the load_player function renders the player image in the same manner. Load_decor is a composite function that draws decorations like items or exits as well. It prioritizes wall elements before decoration elements when determining what to draw at each position. |
| [init_sprites.c](https://github.com/Jauppp/so_long/blob/master/project/init_sprites.c)| In this project' subdirectory, `init_sprites.c` initializes visual game elements by loading sprites into the display. The script ensures the correct importation of background, wall, item, exit, and player images from the sprites directory."|
| [error_handling.c](https://github.com/Jauppp/so_long/blob/master/project/error_handling.c)| Manages error scenarios for the game project. Facilitates graceful exits when encountering memory, parsing, or MLX issues. Functions such as `mem_err`, `parse_err`, `mlx_error`, and `print_error` ensure program termination with informative messages, maximizing user experience in case of errors.|
| [player_moves.c](https://github.com/Jauppp/so_long/blob/master/project/player_moves.c) | The player character based on user input in four directions.Checks: if moving into walls (represented by 1), collectible items (represented by C) or exit (represented by E).It updates the map, move count and item collection count after each movement. and displaysa message indicating the number of remaining items required to open the exit. Repeatedly runs until player reaches the exit, creating a simple maze game structure.|
| [text.c](https://github.com/Jauppp/so_long/blob/master/project/text.c)  |In essence, the code here helps to keep users informed about their progress : displaying and updating player movement count, clearing old move counts, displaying a victory message with move count, and formatting the text accordingly on the screen depending on the window size.|
| [hook_functions.c](https://github.com/Jauppp/so_long/blob/master/project/hook_functions.c)| The `hook_functions.c` file enables movement control for the player character by capturing keyboard inputs (w, a, s, d) and providing corresponding directional movements within the game map. Additionally, it offers an exit functionality by responding to the ESC keypress, gracefully closing the game window when invoked.|
| [main.c](https://github.com/Jauppp/so_long/blob/master/project/main.c)  | This main.c file serves as the entry point for the project. It initiates the program by loading the map (either from standard input or from a specified file) and launching the window display. The code validates the loaded map and manages potential errors accordingly, ensuring a correct map structure before rendering it. This enables users to navigate through the custom 2D game environment defined in multiple.ber files within the repositorys maps folder.|
| [parsing.c](https://github.com/Jauppp/so_long/blob/master/project/parsing.c)| Inspects and validates a given map for our So-Long project, ensuring it adheres to critical requirements. Key functions enforced by this file include map rectangularity, closure (encompassed by walls), presence of one starting point, collectible objects, and a single exit. Failure to pass these checks results in error handling, preserving the games integrity.|
| [load_map.c](https://github.com/Jauppp/so_long/blob/master/project/load_map.c)| The `load_map.c` file, nestled within the main project directory, orchestrates the loading process for game maps in the so-long engine. It initializes the displays coordinate system and sequentially loads decorations, players, and items onto the screen. Moreover, it includes a function, `load_move()`, that refreshes the map as the player moves.|
| [so_long.h](https://github.com/Jauppp/so_long/blob/master/project/so_long.h)| The header for this project, defining the function prototypes and several data structures for coordinate and map display handling|
| [utils.c](https://github.com/Jauppp/so_long/blob/master/project/utils.c)| In this utility module `project/utils.c`, functions are defined that help manage the So-Long games map and data. The core functionalities include calculating map dimensions, clearing the map by resetting non-player cells, and determining the players initial position in the center of the map. These utilities facilitate easy handling of game map structures for better navigation and display control within the game architecture.           |
| [Makefile](https://github.com/Jauppp/so_long/blob/master/project/Makefile)| This Makefile serves as the build script for a program called SO_LONG. By executing the make command, the source files are compiled into an executable named SO_LONG which can then be run using the command./SO_LONG.|
| [win_screen.c](https://github.com/Jauppp/so_long/blob/master/project/win_screen.c)| This file, `win_screen.c`, handles the animation and display of victory screens in the game. It refreshes the players sprite during animations and loads the win screen with the corresponding image, while adjusting it to the center of the map. Moreover, it initiates an exit animation upon opening the door, subsequently ending the MLX loop, concluding the game victoriously.|
| [map_handling.c](https://github.com/Jauppp/so_long/blob/master/project/map_handling.c)| Init_map_stdin()` and `init_map_fd()`. These functions read the map either from a specified file or standard input stream. It also enforces validation rules for a valid game level, ensuring its rectangular, closed (surrounded by walls), contains at least one entry point and one exit, has items to collect, and doesnt trap the player.|
| [init_utils.c](https://github.com/Jauppp/so_long/blob/master/project/init_utils.c)| Assigns default values to all graphical elements (sprites, maps) and counter variables.-Counts the number of collectibles in the map for tracking progress.-Nullifies coordinates and calculates sprite coordinates when needed.|
| [parsing_utils.c](https://github.com/Jauppp/so_long/blob/master/project/parsing_utils.c)| The `parsing_utils.c` file within the game project serves to verify map validity, resolve issues such as trapped sprites, and locate specific sprite coordinates in the given map structure. Ensuring a well-structured map for error-free gameplay.|
| [mem_handling.c](https://github.com/Jauppp/so_long/blob/master/project/mem_handling.c)| Manages dynamic memory allocation within the project, ensuring resources are properly cleaned up. Key functions like `free_tab` free arrays, while `free_double_tab` handles two-dimensional data structures. The critical `free_and_exit` function deallocates memory and terminates the program if necessary. Lastly, the `free_mlx` routine cleans up all associated graphic resources for mlx handling prior to program exit, keeping memory consumption efficient.|
| [window_handling.c](https://github.com/Jauppp/so_long/blob/master/project/window_handling.c) | Initializes display, decor, player, and map; displays welcome message with total moves counter; degisters input hooks (keypress and window close); loads game maps using provided utility functions; continuously updates MLX loop to render graphics.|

</details>

---

##  Getting Started

**System Requirements:**

* **C**: `C17`

###  Installation

<h4>From <code>source</code></h4>


> ```console
> $ git clone https://github.com/Jauppp/so_long/ so_long
> $ cd so_long
>```

###  Usage

<h4>From <code>source</code></h4>

> Run  using the command below:
> ```console
> $ ./so_long maps/[your-map-choice].ber
> $ # if you run ./so_long by itself, it will open STDIN and wait for your input
> ```
<br>
<p align="center">
   <a href="https://github.com{/Jauppp/so_long/}graphs/contributors">
      <img src="https://contrib.rocks/image?repo=Jauppp/so_long">
   </a>
</p>
</details>

---

##  License

This project is protected under the [SELECT-A-LICENSE](https://choosealicense.com/licenses) License. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/) file.

---

##  Acknowledgments

- <a href="https://reactive.so/post/42-a-comprehensive-guide-to-so_long"> MLX documentation 
- <a href="https://harm-smits.github.io/42docs/libs/minilibx"> More MLX documentation </a>

[**Return**](#-overview)

---
<p align="center">
  <img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" alt="project-logo">
</p>
<p align="center">
	<img src="https://img.shields.io/github/last-commit/Jauppp/so_long?style=default&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/Jauppp/so_long?style=default&color=0080ff" alt="repo-top-language">
<p>
<p align="center">
	<!-- default option, no dependency badges. -->
</p>

<br><!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary><br>

- [ Overview](#-overview)
- [ Features](#-features)
- [ Repository Structure](#-repository-structure)
- [ Modules](#-modules)
- [ Getting Started](#-getting-started)
  - [ Installation](#-installation)
  - [ Usage](#-usage)
  - [ Tests](#-tests)
- [ Project Roadmap](#-project-roadmap)
- [ Contributing](#-contributing)
- [ License](#-license)
- [ Acknowledgments](#-acknowledgments)
</details>
<hr>

##  Overview

SO_LONG, is a 2D grid-based adventure game written in C and leveraging the LFT and MLX libraries. The projects core focus is on providing a level for users to traverse.The game is compiled using a custom Makefile that enables various tasks like building the entire project (`all`), cleaning up (`clean`), or recompiling specific sources (`fclean`). A helpful command, also included, provides a list of available actions. 

##  Features

|   |    Feature          | Description                                                                                             |
|----|---------------------|---------------------------------------------------------------------------------------------------------|
| ⚙️ | Architecture       | The project utilizes C language for game logic and uses Makefile to compile the game with LFT and MLX libraries. The final executable is named SO_LONG.                                               |
| 🔌 | Integrations       | The project relies upon external libraries, namely LFT (Linux Framework) and MLX for handling windows, graphics, and user inputs.                                                     |
| 📦 | Dependencies       | The project requires the `make` command and the LFT and MLX libraries for compilation and execution.             |

---

##  Repository Structure

```sh
└── /
    ├── Makefile
    ├── build
    │   ├── libft
    │   └── mlx
    ├── maps
    │   ├── bad_maps
    │   ├── map_01.ber
    │   ├── map_02.ber
    │   ├── map_03.ber
    │   ├── map_04.ber
    │   ├── small_map.ber
    │   ├── square_map.ber
    │   ├── tiny_map.ber
    │   └── tiny_tall.ber
    ├── project
    │   ├── Makefile
    │   ├── error_handling.c
    │   ├── hook_functions.c
    │   ├── init_sprites.c
    │   ├── init_utils.c
    │   ├── load_map.c
    │   ├── load_map_utils.c
    │   ├── main.c
    │   ├── map_handling.c
    │   ├── mem_handling.c
    │   ├── parsing.c
    │   ├── parsing_utils.c
    │   ├── player_moves.c
    │   ├── so_long.h
    │   ├── text.c
    │   ├── utils.c
    │   ├── win_screen.c
    │   └── window_handling.c
    └── sprites
        ├── bg.xpm
        ├── exit.xpm
        ├── exit_02.xpm
        ├── items.xpm
        ├── player.xpm
        ├── player_01.xpm
        ├── player_02.xpm
        ├── png
        ├── wall.xpm
        └── win_screen.xpm
```

##  Modules

<details closed><summary>.</summary>

| File| Summary|
| ---| ---|
| [Makefile](https://github.com/Jauppp/so_long/blob/master/Makefile) | This Makefile compiles a game called SO_LONG by assembling various C source files and linking with the LFT and MLX libraries. Upon execution, it generates an executable named SO_LONG. The file outlines targets like all, clean, fclean to run, clean, or recompile the project respectively. Other features include a help command that lists all possible actions, and even a kitty printout as a fun touch. |

</details>

<details closed><summary>maps</summary>

| File| Summary|
| ---                                                                                 | ---|
| [maps](https://github.com/Jauppp/so_long/blob/master/maps)         | This subdirectory countains eight maps of different sizes and complexity used to render the levels of the game ; all are considered to be valid maps.                            |
</details>

<details closed><summary>maps.bad_maps</summary>

| File| Summary|
| ---| ---|
| [bad.maps](https://github.com/Jauppp/so_long/blob/master/maps/bad_maps)| Maps in this subdirectory are considered invalid and were used to test the parsing. They are either too big, have missing elements (no player, no exit, no collectibles, or inaccessible items), or are not rectangular nor walled in.|
</details>

<details closed><summary>project</summary>

| File| Summary|
| ---| ---    |
| [load_map_utils.c](https://github.com/Jauppp/so_long/blob/master/project/load_map_utils.c)   | In this C file, three functions (load_player, load_decor, load_background) are defined to dynamically display specific images based on the corresponding elements (P, C, 1, etc.) at a particular position in the two-dimensional game map. The load_background function displays wall or background depending on the cell content, while the load_player function renders the player image in the same manner. Load_decor is a composite function that draws decorations like items or exits as well. It prioritizes wall elements before decoration elements when determining what to draw at each position. |
| [init_sprites.c](https://github.com/Jauppp/so_long/blob/master/project/init_sprites.c)| In this project' subdirectory, `init_sprites.c` initializes visual game elements by loading sprites into the display. The script ensures the correct importation of background, wall, item, exit, and player images from the sprites directory."|
| [error_handling.c](https://github.com/Jauppp/so_long/blob/master/project/error_handling.c)| Manages error scenarios for the game project. Facilitates graceful exits when encountering memory, parsing, or MLX issues. Functions such as `mem_err`, `parse_err`, `mlx_error`, and `print_error` ensure program termination with informative messages, maximizing user experience in case of errors.|
| [player_moves.c](https://github.com/Jauppp/so_long/blob/master/project/player_moves.c) | The player character based on user input in four directions.Checks: if moving into walls (represented by 1), collectible items (represented by C) or exit (represented by E).It updates the map, move count and item collection count after each movement. and displaysa message indicating the number of remaining items required to open the exit. Repeatedly runs until player reaches the exit, creating a simple maze game structure.|
| [text.c](https://github.com/Jauppp/so_long/blob/master/project/text.c)  |In essence, the code here helps to keep users informed about their progress : displaying and updating player movement count, clearing old move counts, displaying a victory message with move count, and formatting the text accordingly on the screen depending on the window size.|
| [hook_functions.c](https://github.com/Jauppp/so_long/blob/master/project/hook_functions.c)| The `hook_functions.c` file enables movement control for the player character by capturing keyboard inputs (w, a, s, d) and providing corresponding directional movements within the game map. Additionally, it offers an exit functionality by responding to the ESC keypress, gracefully closing the game window when invoked.|
| [main.c](https://github.com/Jauppp/so_long/blob/master/project/main.c)  | This main.c file serves as the entry point for the project. It initiates the program by loading the map (either from standard input or from a specified file) and launching the window display. The code validates the loaded map and manages potential errors accordingly, ensuring a correct map structure before rendering it. This enables users to navigate through the custom 2D game environment defined in multiple.ber files within the repositorys maps folder.|
| [parsing.c](https://github.com/Jauppp/so_long/blob/master/project/parsing.c)| Inspects and validates a given map for our So-Long project, ensuring it adheres to critical requirements. Key functions enforced by this file include map rectangularity, closure (encompassed by walls), presence of one starting point, collectible objects, and a single exit. Failure to pass these checks results in error handling, preserving the games integrity.|
| [load_map.c](https://github.com/Jauppp/so_long/blob/master/project/load_map.c)| The `load_map.c` file, nestled within the main project directory, orchestrates the loading process for game maps in the so-long engine. It initializes the displays coordinate system and sequentially loads decorations, players, and items onto the screen. Moreover, it includes a function, `load_move()`, that refreshes the map as the player moves.|
| [so_long.h](https://github.com/Jauppp/so_long/blob/master/project/so_long.h)| The header for this project, defining the function prototypes and several data structures for coordinate and map display handling|
| [utils.c](https://github.com/Jauppp/so_long/blob/master/project/utils.c)| In this utility module `project/utils.c`, functions are defined that help manage the So-Long games map and data. The core functionalities include calculating map dimensions, clearing the map by resetting non-player cells, and determining the players initial position in the center of the map. These utilities facilitate easy handling of game map structures for better navigation and display control within the game architecture.           |
| [Makefile](https://github.com/Jauppp/so_long/blob/master/project/Makefile)| This Makefile serves as the build script for a program called SO_LONG. By executing the make command, the source files are compiled into an executable named SO_LONG which can then be run using the command./SO_LONG.|
| [win_screen.c](https://github.com/Jauppp/so_long/blob/master/project/win_screen.c)| This file, `win_screen.c`, handles the animation and display of victory screens in the game. It refreshes the players sprite during animations and loads the win screen with the corresponding image, while adjusting it to the center of the map. Moreover, it initiates an exit animation upon opening the door, subsequently ending the MLX loop, concluding the game victoriously.|
| [map_handling.c](https://github.com/Jauppp/so_long/blob/master/project/map_handling.c)| Init_map_stdin()` and `init_map_fd()`. These functions read the map either from a specified file or standard input stream. It also enforces validation rules for a valid game level, ensuring its rectangular, closed (surrounded by walls), contains at least one entry point and one exit, has items to collect, and doesnt trap the player.|
| [init_utils.c](https://github.com/Jauppp/so_long/blob/master/project/init_utils.c)| Assigns default values to all graphical elements (sprites, maps) and counter variables.-Counts the number of collectibles in the map for tracking progress.-Nullifies coordinates and calculates sprite coordinates when needed.|
| [parsing_utils.c](https://github.com/Jauppp/so_long/blob/master/project/parsing_utils.c)| The `parsing_utils.c` file within the game project serves to verify map validity, resolve issues such as trapped sprites, and locate specific sprite coordinates in the given map structure. Ensuring a well-structured map for error-free gameplay.|
| [mem_handling.c](https://github.com/Jauppp/so_long/blob/master/project/mem_handling.c)| Manages dynamic memory allocation within the project, ensuring resources are properly cleaned up. Key functions like `free_tab` free arrays, while `free_double_tab` handles two-dimensional data structures. The critical `free_and_exit` function deallocates memory and terminates the program if necessary. Lastly, the `free_mlx` routine cleans up all associated graphic resources for mlx handling prior to program exit, keeping memory consumption efficient.|
| [window_handling.c](https://github.com/Jauppp/so_long/blob/master/project/window_handling.c) | Initializes display, decor, player, and map; displays welcome message with total moves counter; degisters input hooks (keypress and window close); loads game maps using provided utility functions; continuously updates MLX loop to render graphics.|

</details>

---

##  Getting Started

**System Requirements:**

* **C**: `C17`

###  Installation

<h4>From <code>source</code></h4>


> ```console
> $ git clone https://github.com/Jauppp/so_long/ so_long
> $ cd so_long
>```

###  Usage

<h4>From <code>source</code></h4>

> Run  using the command below:
> ```console
> $ ./so_long maps/[your-map-choice].ber
> $ # if you run ./so_long by itself, it will open STDIN and wait for your input
> ```
<br>
<p align="center">
   <a href="https://github.com{/Jauppp/so_long/}graphs/contributors">
      <img src="https://contrib.rocks/image?repo=Jauppp/so_long">
   </a>
</p>
</details>

---

##  License

This project is protected under the [SELECT-A-LICENSE](https://choosealicense.com/licenses) License. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/) file.

---

##  Acknowledgments

- <a href="https://reactive.so/post/42-a-comprehensive-guide-to-so_long"> MLX documentation 
- <a href="https://harm-smits.github.io/42docs/libs/minilibx"> More MLX documentation </a>

[**Return**](#-overview)

---
<p align="center">
  <img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" alt="project-logo">
</p>
<p align="center">
	<img src="https://img.shields.io/github/last-commit/Jauppp/so_long?style=default&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/Jauppp/so_long?style=default&color=0080ff" alt="repo-top-language">
<p>
<p align="center">
	<!-- default option, no dependency badges. -->
</p>

<br><!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary><br>

- [ Overview](#-overview)
- [ Features](#-features)
- [ Repository Structure](#-repository-structure)
- [ Modules](#-modules)
- [ Getting Started](#-getting-started)
  - [ Installation](#-installation)
  - [ Usage](#-usage)
  - [ Tests](#-tests)
- [ Project Roadmap](#-project-roadmap)
- [ Contributing](#-contributing)
- [ License](#-license)
- [ Acknowledgments](#-acknowledgments)
</details>
<hr>

##  Overview

SO_LONG, is a 2D grid-based adventure game written in C and leveraging the LFT and MLX libraries. The projects core focus is on providing a level for users to traverse.The game is compiled using a custom Makefile that enables various tasks like building the entire project (`all`), cleaning up (`clean`), or recompiling specific sources (`fclean`). A helpful command, also included, provides a list of available actions. 

##  Features

|   |    Feature          | Description                                                                                             |
|----|---------------------|---------------------------------------------------------------------------------------------------------|
| ⚙️ | Architecture       | The project utilizes C language for game logic and uses Makefile to compile the game with LFT and MLX libraries. The final executable is named SO_LONG.                                               |
| 🔌 | Integrations       | The project relies upon external libraries, namely LFT (Linux Framework) and MLX for handling windows, graphics, and user inputs.                                                     |
| 📦 | Dependencies       | The project requires the `make` command and the LFT and MLX libraries for compilation and execution.             |

---

##  Repository Structure

```sh
└── /
    ├── Makefile
    ├── build
    │   ├── libft
    │   └── mlx
    ├── maps
    │   ├── bad_maps
    │   ├── map_01.ber
    │   ├── map_02.ber
    │   ├── map_03.ber
    │   ├── map_04.ber
    │   ├── small_map.ber
    │   ├── square_map.ber
    │   ├── tiny_map.ber
    │   └── tiny_tall.ber
    ├── project
    │   ├── Makefile
    │   ├── error_handling.c
    │   ├── hook_functions.c
    │   ├── init_sprites.c
    │   ├── init_utils.c
    │   ├── load_map.c
    │   ├── load_map_utils.c
    │   ├── main.c
    │   ├── map_handling.c
    │   ├── mem_handling.c
    │   ├── parsing.c
    │   ├── parsing_utils.c
    │   ├── player_moves.c
    │   ├── so_long.h
    │   ├── text.c
    │   ├── utils.c
    │   ├── win_screen.c
    │   └── window_handling.c
    └── sprites
        ├── bg.xpm
        ├── exit.xpm
        ├── exit_02.xpm
        ├── items.xpm
        ├── player.xpm
        ├── player_01.xpm
        ├── player_02.xpm
        ├── png
        ├── wall.xpm
        └── win_screen.xpm
```

##  Modules

<details closed><summary>.</summary>

| File| Summary|
| ---| ---|
| [Makefile](https://github.com/Jauppp/so_long/blob/master/Makefile) | This Makefile compiles a game called SO_LONG by assembling various C source files and linking with the LFT and MLX libraries. Upon execution, it generates an executable named SO_LONG. The file outlines targets like all, clean, fclean to run, clean, or recompile the project respectively. Other features include a help command that lists all possible actions, and even a kitty printout as a fun touch. |

</details>

<details closed><summary>maps</summary>

| File| Summary|
| ---                                                                                 | ---|
| [maps](https://github.com/Jauppp/so_long/blob/master/maps)         | This subdirectory countains eight maps of different sizes and complexity used to render the levels of the game ; all are considered to be valid maps.                            |
</details>

<details closed><summary>maps.bad_maps</summary>

| File| Summary|
| ---| ---|
| [bad.maps](https://github.com/Jauppp/so_long/blob/master/maps/bad_maps)| Maps in this subdirectory are considered invalid and were used to test the parsing. They are either too big, have missing elements (no player, no exit, no collectibles, or inaccessible items), or are not rectangular nor walled in.|
</details>

<details closed><summary>project</summary>

| File| Summary|
| ---| ---    |
| [load_map_utils.c](https://github.com/Jauppp/so_long/blob/master/project/load_map_utils.c)   | In this C file, three functions (load_player, load_decor, load_background) are defined to dynamically display specific images based on the corresponding elements (P, C, 1, etc.) at a particular position in the two-dimensional game map. The load_background function displays wall or background depending on the cell content, while the load_player function renders the player image in the same manner. Load_decor is a composite function that draws decorations like items or exits as well. It prioritizes wall elements before decoration elements when determining what to draw at each position. |
| [init_sprites.c](https://github.com/Jauppp/so_long/blob/master/project/init_sprites.c)| In this project' subdirectory, `init_sprites.c` initializes visual game elements by loading sprites into the display. The script ensures the correct importation of background, wall, item, exit, and player images from the sprites directory."|
| [error_handling.c](https://github.com/Jauppp/so_long/blob/master/project/error_handling.c)| Manages error scenarios for the game project. Facilitates graceful exits when encountering memory, parsing, or MLX issues. Functions such as `mem_err`, `parse_err`, `mlx_error`, and `print_error` ensure program termination with informative messages, maximizing user experience in case of errors.|
| [player_moves.c](https://github.com/Jauppp/so_long/blob/master/project/player_moves.c) | The player character based on user input in four directions.Checks: if moving into walls (represented by 1), collectible items (represented by C) or exit (represented by E).It updates the map, move count and item collection count after each movement. and displaysa message indicating the number of remaining items required to open the exit. Repeatedly runs until player reaches the exit, creating a simple maze game structure.|
| [text.c](https://github.com/Jauppp/so_long/blob/master/project/text.c)  |In essence, the code here helps to keep users informed about their progress : displaying and updating player movement count, clearing old move counts, displaying a victory message with move count, and formatting the text accordingly on the screen depending on the window size.|
| [hook_functions.c](https://github.com/Jauppp/so_long/blob/master/project/hook_functions.c)| The `hook_functions.c` file enables movement control for the player character by capturing keyboard inputs (w, a, s, d) and providing corresponding directional movements within the game map. Additionally, it offers an exit functionality by responding to the ESC keypress, gracefully closing the game window when invoked.|
| [main.c](https://github.com/Jauppp/so_long/blob/master/project/main.c)  | This main.c file serves as the entry point for the project. It initiates the program by loading the map (either from standard input or from a specified file) and launching the window display. The code validates the loaded map and manages potential errors accordingly, ensuring a correct map structure before rendering it. This enables users to navigate through the custom 2D game environment defined in multiple.ber files within the repositorys maps folder.|
| [parsing.c](https://github.com/Jauppp/so_long/blob/master/project/parsing.c)| Inspects and validates a given map for our So-Long project, ensuring it adheres to critical requirements. Key functions enforced by this file include map rectangularity, closure (encompassed by walls), presence of one starting point, collectible objects, and a single exit. Failure to pass these checks results in error handling, preserving the games integrity.|
| [load_map.c](https://github.com/Jauppp/so_long/blob/master/project/load_map.c)| The `load_map.c` file, nestled within the main project directory, orchestrates the loading process for game maps in the so-long engine. It initializes the displays coordinate system and sequentially loads decorations, players, and items onto the screen. Moreover, it includes a function, `load_move()`, that refreshes the map as the player moves.|
| [so_long.h](https://github.com/Jauppp/so_long/blob/master/project/so_long.h)| The header for this project, defining the function prototypes and several data structures for coordinate and map display handling|
| [utils.c](https://github.com/Jauppp/so_long/blob/master/project/utils.c)| In this utility module `project/utils.c`, functions are defined that help manage the So-Long games map and data. The core functionalities include calculating map dimensions, clearing the map by resetting non-player cells, and determining the players initial position in the center of the map. These utilities facilitate easy handling of game map structures for better navigation and display control within the game architecture.           |
| [Makefile](https://github.com/Jauppp/so_long/blob/master/project/Makefile)| This Makefile serves as the build script for a program called SO_LONG. By executing the make command, the source files are compiled into an executable named SO_LONG which can then be run using the command./SO_LONG.|
| [win_screen.c](https://github.com/Jauppp/so_long/blob/master/project/win_screen.c)| This file, `win_screen.c`, handles the animation and display of victory screens in the game. It refreshes the players sprite during animations and loads the win screen with the corresponding image, while adjusting it to the center of the map. Moreover, it initiates an exit animation upon opening the door, subsequently ending the MLX loop, concluding the game victoriously.|
| [map_handling.c](https://github.com/Jauppp/so_long/blob/master/project/map_handling.c)| Init_map_stdin()` and `init_map_fd()`. These functions read the map either from a specified file or standard input stream. It also enforces validation rules for a valid game level, ensuring its rectangular, closed (surrounded by walls), contains at least one entry point and one exit, has items to collect, and doesnt trap the player.|
| [init_utils.c](https://github.com/Jauppp/so_long/blob/master/project/init_utils.c)| Assigns default values to all graphical elements (sprites, maps) and counter variables.-Counts the number of collectibles in the map for tracking progress.-Nullifies coordinates and calculates sprite coordinates when needed.|
| [parsing_utils.c](https://github.com/Jauppp/so_long/blob/master/project/parsing_utils.c)| The `parsing_utils.c` file within the game project serves to verify map validity, resolve issues such as trapped sprites, and locate specific sprite coordinates in the given map structure. Ensuring a well-structured map for error-free gameplay.|
| [mem_handling.c](https://github.com/Jauppp/so_long/blob/master/project/mem_handling.c)| Manages dynamic memory allocation within the project, ensuring resources are properly cleaned up. Key functions like `free_tab` free arrays, while `free_double_tab` handles two-dimensional data structures. The critical `free_and_exit` function deallocates memory and terminates the program if necessary. Lastly, the `free_mlx` routine cleans up all associated graphic resources for mlx handling prior to program exit, keeping memory consumption efficient.|
| [window_handling.c](https://github.com/Jauppp/so_long/blob/master/project/window_handling.c) | Initializes display, decor, player, and map; displays welcome message with total moves counter; degisters input hooks (keypress and window close); loads game maps using provided utility functions; continuously updates MLX loop to render graphics.|

</details>

---

##  Getting Started

**System Requirements:**

* **C**: `C17`

###  Installation

<h4>From <code>source</code></h4>


> ```console
> $ git clone https://github.com/Jauppp/so_long/ so_long
> $ cd so_long
>```

###  Usage

<h4>From <code>source</code></h4>

> Run  using the command below:
> ```console
> $ ./so_long maps/[your-map-choice].ber
> $ # if you run ./so_long by itself, it will open STDIN and wait for your input
> ```
<br>
<p align="center">
   <a href="https://github.com{/Jauppp/so_long/}graphs/contributors">
      <img src="https://contrib.rocks/image?repo=Jauppp/so_long">
   </a>
</p>
</details>

---

##  License

This project is protected under the [SELECT-A-LICENSE](https://choosealicense.com/licenses) License. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/) file.

---

##  Acknowledgments

- <a href="https://reactive.so/post/42-a-comprehensive-guide-to-so_long"> MLX documentation 
- <a href="https://harm-smits.github.io/42docs/libs/minilibx"> More MLX documentation </a>

[**Return**](#-overview)

---

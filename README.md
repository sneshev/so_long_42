Step-by-Step Plan for So_Long Project
1. Initial Setup and Preparation

    Understand the project requirements: Read the subject carefully, paying attention to the mandatory and bonus parts, map specifications, and the rules for the project.

    Set up your development environment:

        Install the MiniLibX graphics library (or use the version provided by your school).

        Install a C compiler (like gcc), and set up your IDE or text editor (VSCode, Sublime, etc.).

        Ensure that libft (if needed) is available and ready to use for the project.

    Create a Git repository: This is where you'll store all your project files. Make sure it's linked to your school’s repository for submission.

2. Create Your Project Folder Structure

    Create a directory for the project.

    Inside, create subdirectories for:

        src/ for source files

        inc/ for header files

        textures/ for images or sprite sheets

        maps/ for .ber map files

        bonus/ for any bonus-related files if you plan to implement them later.

3. Write a Makefile

    Create the Makefile:

        Define rules for NAME, all, clean, fclean, re.

        Add -Wall, -Wextra, -Werror flags to ensure clean code.

        Include libft compilation if necessary (use $(LIBFT) to link it).

        Include a rule for compiling your program with the correct flags.

        Make sure the bonus part is separate and doesn’t impact the mandatory part.

4. Develop the Game (Mandatory Part)
4.1. Set up Window and Event Handling

    Open a window using MiniLibX:

        Use mlx_init() to initialize MiniLibX.

        Use mlx_new_window() to create the window.

        Set a key event handler for the keys (W, A, S, D for movement) using mlx_hook().

    Handle window closing:

        Handle window close event with mlx_hook() (on close or ESC key).

        Ensure graceful shutdown using exit() to prevent memory leaks.

4.2. Define the Map and Map Parsing

    Create the Map Parser:

        Parse the .ber map file.

        Validate map format (walls, collectibles, starting position, exit, etc.).

        Ensure there’s one starting position (P), one exit (E), and at least one collectible (C).

        Validate map boundaries (must be surrounded by walls).

        Verify the path between the start and exit is clear.

    Store the map:

        Store map data in a 2D array (e.g., char **map).

        Define constants for walls (1), empty spaces (0), collectibles (C), and exit (E).

4.3. Implement Movement and Gameplay

    Player movement:

        Handle player movement using W, A, S, D keys (or ZQSD/arrow keys).

        Ensure the player can only move in valid directions (no moving through walls).

    Game logic:

        The goal is to collect all collectibles and reach the exit.

        Display the number of movements in the shell after each move.

        Implement a check that verifies all collectibles are collected before allowing exit.

4.4. Implement Graphics

    Draw the map:

        Use the MiniLibX functions (mlx_put_image_to_window()) to draw the map on the window based on your 2D array representation.

        Draw walls, collectibles, player, and exit with different textures or colors.

    Handle smooth window transitions:

        Ensure the window updates smoothly when moving between different scenes (e.g., player movement).

        Handle window resizing or minimizing.

4.5. Error Handling and Exiting

    Exit cleanly:

        If the map is invalid, display an error message ("Error\n") and exit gracefully.

        Ensure proper memory freeing (free()) for the map and any dynamically allocated memory.

        Handle file errors (invalid map file, parsing issues, etc.).

5. Bonus Part (Optional)

    Enemy patrol:

        Add enemies that patrol a predefined path.

        End the game if the player touches an enemy (collision detection).

    Sprite animations:

        Implement sprite animations for the player or other entities (e.g., walking animation for the player).

    Display movement count in-game:

        Display the number of movements directly on the window, rather than in the shell, using mlx_string_put().

6. Testing and Debugging

    Test basic gameplay: Test player movement, map parsing, and interactions (collecting items, reaching the exit).

    Check for edge cases:

        Ensure invalid maps trigger the correct error messages.

        Test the map's boundary handling and correct collision detection.

    Check memory leaks: Use a tool like valgrind to check for memory leaks.

7. Final Steps

    Review the project requirements: Ensure you have met all the mandatory requirements.

    Complete the bonus part (if implemented).

    Clean up code: Ensure your code follows the Norm (coding standard) and is well-documented.

    Submit the project: Push your project to the Git repository and submit it for evaluation.

8. Peer-Evaluation (if applicable)

    Prepare for defense: Be ready to explain your design, how you implemented key features, and discuss any challenges you encountered.

    Test your project on other computers (if possible) to ensure it works on different setups.

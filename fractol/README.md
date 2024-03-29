# Fract-ol

Fract-ol is a project aimed at generating three different fractals using only the MiniLib library, which allows painting pixels on the screen.
<img src="images/julia1.png" alt="Julia Set" width="350">
<img src="images/julia2.png" alt="Julia Set" width="350">
<img src="images/mandel1.png" alt="Mandel Set" width="350">
<img src="images/mandel2.png" alt="Mandel Set" width="500">
<img src="images/spel1.png" alt="Spel Set" width="350">
<img src="images/spel2.png" alt="Spel Set" width="350">
<img src="images/spel3.png" alt="Spel Set" width="350">

## Installation

To use Fract-ol, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/your_username/fract-ol.git
    ```

2. Navigate to the project directory:

    ```bash
    cd fract-ol
    ```

3. Compile the project using Makefile:

    ```bash
    make
    ```

## Usage


Once compiled, you can execute Fract-ol by passing the fractal you want to visualize as a parameter:

```bash
./fractol [fractal]
```

Where [fractal] can be:
- `j` for julia set.
- `m` for Mandelbrot set.
- `s` for Sierpinski triangle.

## After opening the fractal, you can interact with it using the following controls:
- Use the numbers `1`, `2`, `3`, and `4` to change colors.
- Use `arrow keys` to move around.
- Use the `scroll wheel` of the mouse or the `+` and `-` keys to zoom in and out.
- Press `r` to reset.

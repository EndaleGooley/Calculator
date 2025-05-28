# Terminal Calculator

A simple C++ terminal calculator that lets you perform basic arithmetic (addition, subtraction, multiplication, division) using either keyboard or file input, and output results to the console or an output file.

---

## Features

- **Dual input modes:**
  - **Keyboard**: enter two numbers and an operator interactively  
  - **File**: read `num1 op num2` from a text file  
- **Dual output modes:**
  - **Console**: display `num1 op num2 = result` on screen  
  - **File**: write the result to a text file  
- **Robust validation**: checks for non-numeric input, invalid operators, division by zero, and file I/O errors  
- **Repeatable**: perform as many calculations as you like in one run  

---

## Prerequisites

- A C++ compiler supporting C++11 or later (e.g. `g++`, `clang++`)  
- Standard C++ library (no external dependencies)  

---

## Compilation

```bash
g++ -std=c++11 -o calculator main.cpp
```

---

## Usage

```bash
./calculator
```

1. **Input choice**  
   - `K` (keyboard) or `F` (file) or `Q` (quit)  
2. **Enter values**  
   - If **K**: you’ll be prompted for `num1 operator num2`  
   - If **F**: enter your input filename (e.g. `input.txt`)  
3. **Output choice**  
   - `C` (console) or `F` (file)  
4. **Repeat**  
   - After each calculation you can choose to run another  

---

## File Formats

- **Input file**:  
  ```
  <num1> <operator> <num2>
  ```  
- **Output file**:  
  ```
  <num1> <operator> <num2> = <result>
  ```

---

## Examples

### Keyboard → Console

```plaintext
Would you like to input from the [K]eyboard or [F]ile? K
Enter num1, operator (+ - * /), and num2: 3 + 5
Would you like to output to the [C]onsole or to a [F]ile? C
3 + 5 = 8
Would you like to perform another calculation? (Y/N): N
```

### File → File

```bash
$ cat input.txt
10 / 2

$ ./calculator
Would you like to input from the [K]eyboard or [F]ile? F
Enter the input filename: input.txt
Would you like to output to the [C]onsole or to a [F]ile? F
Enter the output filename: output.txt
Result written to file.

$ cat output.txt
10 / 2 = 5
```

---

## How It Works

- **main.cpp**  
  - Presents a menu for input/output mode  
  - Validates and reads `num1`, `op`, `num2`  
  - Calls one of four functions (`add`, `subtract`, `multiply`, `divide`)  
  - Handles errors (invalid input, division by zero, file failures)  
  - Offers to repeat until the user quits  

---

## Author

Endale Gooley

---

## License

This project is released under the [MIT License](LICENSE).







# Simple Calculator App

This is a simple **calculator** application built using **Qt** and **C++**. The calculator performs basic arithmetic operations such as addition, subtraction, multiplication, and division.

## Features

- Perform **basic arithmetic operations**: Addition, Subtraction, Multiplication, Division.
- Responsive and **easy-to-use** interface.
- **Clear display** with a maximum of 15 digits.
- **Error handling** for division by zero.

## Technologies Used

### 1. **C++**
   - **C++** is the core programming language used to build this application. C++ is known for its efficiency and control over system resources, making it a great choice for creating desktop applications like this calculator.
   - C++ provides the object-oriented framework in which classes like `Calculator` are built, making the code modular and reusable.

### 2. **Qt Framework**
   - **Qt** is a powerful cross-platform application development framework that is widely used for developing GUI applications.
   - This project uses **Qt Widgets**, a module that provides a rich set of UI controls like buttons, text boxes, and layouts, all used to create the graphical user interface for this calculator.
   
   #### Key Qt Components:
   - **QMainWindow**: Provides the main window structure for the app, including the menu bar and the central widget (which in this case is the calculator layout).
   - **QPushButton**: Used to create the buttons for numbers, operators, and control actions (e.g., `=`, `C`).
   - **QLineEdit**: A single-line text input widget used as the display for the calculator. The `QLineEdit` is set to read-only so users can only interact through the buttons.
   - **QGridLayout**: Used to organize the buttons in a grid-like layout to ensure the UI is clean and responsive.
   - **Signal-Slot Mechanism**: A core feature of Qt that allows the buttons to trigger specific actions when clicked. This mechanism connects the signals (button clicks) to slots (functions like `digitClicked()` and `operatorClicked()`).

### 3. **Object-Oriented Programming (OOP)**
   - The project heavily relies on **OOP principles** like encapsulation and abstraction.
   - The calculator functionality is organized into a `Calculator` class that encapsulates all the operations and data needed for performing calculations.
   - This structure makes it easier to manage and scale the application by adding more features, like scientific operations or keyboard input.

### 4. **Cross-Platform Support**
   - Since **Qt** is a cross-platform framework, this calculator application can be compiled and run on different operating systems such as **Windows**, **Linux**, and **macOS** without major changes to the code.
   - This allows the same codebase to be shared and deployed on various platforms with minimal configuration.

## Prerequisites

To build and run this application, you will need:
- **Qt 5.x** or later (with Qt Widgets module installed).
- **C++11** or later.

Ensure you have the required Qt development environment set up. You can install Qt from [here](https://www.qt.io/download).

## How to Build and Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Locked-Cloud/calculator-app.git
   cd calculator-app

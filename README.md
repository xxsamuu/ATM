# ATM Machine Simulator

This project is a C++ program that simulates an ATM machine with full authentication system and a small database using CSV files. The program is designed to handle basic banking transactions such as withdrawal, deposit, and balance inquiry.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Classes](#classes)


## Installation

To run the program, you need to have C++ installed on your computer. You can download the source code from the Github repository:

```bash
git clone https://github.com/your_username/ATM-machine-simulator.git
```

Once you have the source code, you can compile it using any C++ compiler.

## Usage

To use the program, you can simply run the executable file. The program will prompt you to either login or signup if you don't have an account. After you authenticate yourself, you can choose the type of transaction you want to perform.

## Features

- Full authentication system
- Basic banking transactions: withdraw, deposit, and balance inquiry
- Small database using CSV files
- Simple and user-friendly interface
- Error handling

## Classes

- Bank: This class handles user authentication and account creation. It checks if the given username and PIN are found in the CSV file, and if not, it registers the user.
- Customer: This class holds all the user properties: name, PIN, and balance.
- Transaction: This class handles the transactions: withdrawal, deposit, and balance inquiry. It updates the user's balance in the CSV file.
- ReadCSVFile: This class handles the reading and writing of the CSV file. It extracts and modifies data from the file.


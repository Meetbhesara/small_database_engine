# Mini SQL-like Database Engine

A lightweight, interactive command-line C++ application that mimics basic SQL database functionalities. Supports creating tables, inserting data, and running simple SELECT queries with logical conditions—all in memory using modern C++.

## Features

- Custom table creation (`CREATE`)
- Row insertion (`INSERT`)
- Data selection with column projection and conditions (`SELECT`, with AND/OR/NOT logic)
- Modular, in-memory data storage using STL containers
- Object-oriented, easily extensible design for learning and prototyping

## How to Run

1. **Clone the Repository:**
    ```
    git clone https://github.com/Meetbhesara/small_database_engine.git
    cd small_database_engine
    ```

2. **Compile:**
    ```
    g++ index.cpp -o mini_db
    ```

3. **Run:**
    ```
    ./mini_db
    ```
    *(or `mini_db.exe` on Windows)*

## Example Usage


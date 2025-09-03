# 🗄️ Simple In-Memory SQL Engine in C++

This is a lightweight, in-memory SQL-like database engine written in **C++**. It supports basic SQL operations such as creating tables, inserting data, and querying with filtering logic. Ideal for learning how SQL parsing and execution works under the hood.

---

## 📚 Table of Contents

- [Features](#-features)
- [How It Works](#-how-it-works)
- [Setup & Compilation](#-setup--compilation)
- [Usage](#-usage)
- [Supported SQL Syntax](#-supported-sql-syntax)
- [Example Queries](#-example-queries)
- [Limitations](#-limitations)
- [Future Improvements](#-future-improvements)
- [License](#-license)

---

## ✅ Features

- 🧱 Create tables with any number of columns
- 📝 Insert rows of string data
- 🔍 Select all or specific columns
- 🧠 Filter rows using `WHERE` clause
- ⚙️ Logical operators supported: `AND`, `OR`, `NOT`
- 🧪 Simple command-line interface for testing

---

## ⚙️ How It Works

- Tables are stored in-memory using C++ `unordered_map`.
- Each table has:
  - A name
  - A list of columns (`vector<string>`)
  - A list of rows (`vector<Row>`)
- The engine parses commands like:
  - `CREATE TableName col1 col2 ...`
  - `INSERT TableName val1 val2 ...`
  - `SELECT [cols...] TableName [WHERE col op val ...]`
- Supports filtering using simple conditions with `=` operator.

---

## 🛠️ Setup & Compilation

### Requirements:
- C++11 or higher
- GCC or compatible compiler

### Compile:
```bash
g++ -std=c++11 -o sql_engine main.cpp

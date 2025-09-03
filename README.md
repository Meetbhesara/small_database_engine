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
🚀 Usage
After compiling and running the executable, you’ll see a prompt:

shell
Copy code
SQL>
From here, you can enter SQL-like commands to interact with your in-memory database.

To exit the program, type:

sql
Copy code
exit
🧾 Supported SQL Syntax
Create a Table
sql
Copy code
CREATE TableName Column1 Column2 Column3 ...
Example:

sql
Copy code
CREATE Students ID Name Age City
Insert Data into a Table
sql
Copy code
INSERT TableName Value1 Value2 Value3 ...
Example:

sql
Copy code
INSERT Students 1 Alice 21 NewYork
Select All Columns
sql
Copy code
SELECT TableName
Example:

sql
Copy code
SELECT Students
Select Specific Columns
sql
Copy code
SELECT Column1 Column2 TableName
Example:

sql
Copy code
SELECT Name Age Students
Select with WHERE Condition
sql
Copy code
SELECT TableName WHERE Column = Value
Example:

sql
Copy code
SELECT Students WHERE Age = 21
Select with Multiple Conditions
sql
Copy code
SELECT Column1 Column2 TableName WHERE Column1 = Value1 AND Column2 = Value2
Example:

sql
Copy code
SELECT Name Age Students WHERE Age = 21 AND City = NewYork
Using OR and NOT
sql
Copy code
SELECT Students WHERE Age = 21 OR City = Boston
SELECT Students WHERE NOT Age = 21
🧪 Example Session
sql
Copy code
CREATE Students ID Name Age City
INSERT Students 1 Alice 21 NewYork
INSERT Students 2 Bob 22 Boston
INSERT Students 3 Charlie 21 NewYork

SELECT Students
SELECT Name Age Students WHERE Age = 21
SELECT Students WHERE Age = 21 AND City = NewYork
SELECT Students WHERE NOT City = Boston
🚧 Limitations
Only the = operator is supported in WHERE clause (no <, >, !=, etc.)

Data is not stored persistently (memory only)

No support for advanced SQL (JOIN, GROUP BY, UPDATE, DELETE, etc.)

All values are treated as strings

Simple line-based command parser

🔮 Future Improvements
Add support for more operators: <, >, !=, etc.

Implement persistent storage (e.g., save/load to files)

Add UPDATE, DELETE, and ALTER functionalities

Improve error handling and validation

Introduce support for multiple data types (int, string, etc.)

Build a command history and auto-completion feature

📄 License
This project is open source under the MIT License.
Feel free to use, modify, and distribute.

👨‍💻 Author
Developed by Meet Bhesara
If you find this project helpful or want to contribute, feel free to fork or submit a pull request!

pgsql
Copy code

Do you want me to also **add your name in the Author section** Meet Bhesara

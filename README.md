# 🗄️ Simple In-Memory SQL Engine in C++

This is a lightweight, in-memory SQL-like database engine written in **C++**. It supports basic SQL operations such as creating tables, inserting data, and querying with filtering logic. Ideal for learning how SQL parsing and execution works under the hood.

---

## 📚 Table of Contents
- Features
- How It Works
- Limitations
- Future Improvements
- License
- Author

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

## 🚧 Limitations
- Only the `=` operator is supported in WHERE clause (no `<`, `>`, `!=`, etc.)  
- Data is not stored persistently (memory only)  
- No support for advanced SQL (`JOIN`, `GROUP BY`, `UPDATE`, `DELETE`, etc.)  
- All values are treated as strings  
- Simple line-based command parser  

---

## 🔮 Future Improvements
- Add support for more operators: `<`, `>`, `!=`, etc.  
- Implement persistent storage (e.g., save/load to files)  
- Add `UPDATE`, `DELETE`, and `ALTER` functionalities  
- Improve error handling and validation  
- Introduce support for multiple data types (int, string, etc.)  
- Build a command history and auto-completion feature  

---

## 📄 License
This project is open source under the MIT License.  
Feel free to use, modify, and distribute.  

---

## 👨‍💻 Author
Developed by **Meet Bhesara**  
If you find this project helpful or want to contribute, feel free to fork or submit a pull request!

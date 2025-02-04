# 🔢 C++ CLI Calculator  

A simple **command-line calculator** built with C++ that supports basic arithmetic operations and complex mathematical expressions. This program converts infix expressions to postfix notation and evaluates them efficiently.  

---

## ✨ Features  
✅ Basic arithmetic operations: **Addition (+), Subtraction (-), Multiplication (*), Division (/)**  
✅ Supports **complex mathematical expressions** with operator precedence  
✅ **Implicit multiplication handling** (e.g., `15(5+7)` is interpreted as `15*(5+7)`)  
✅ **Error handling** for invalid inputs and division by zero  
✅ **Interactive CLI Menu** for manual operations and full expression solving  

---

## 📂 Installation & Compilation  
### **Prerequisites**  
🔹 Install a C++ compiler (e.g., g++, clang)  

### **Steps**  
1️⃣ Clone this repository:  
git clone https://github.com/your-username/your-repo-name.git

2️⃣ Navigate to the project folder:
cd your-repo-name

3️⃣ Compile the code using g++:
g++ calculator.cpp -o calculator

4️⃣ Run the executable:
bash ./calculator

🛠️ Usage
After running the program, you will see a menu:

===================================== CLI Calculator Menu =====================================
1. Add  
2. Subtract  
3. Multiply  
4. Divide  
5. Solve an Expression  
6. Exit  
Enter your choice:  
Choose 1-4 for basic operations and enter two numbers.
Choose 5 to enter a mathematical expression (e.g., 20+15*(5*7)).
Enter 6 to exit the program.

🚀 Example Calculations
![image](https://github.com/user-attachments/assets/fd4e93eb-f45a-4e2c-8c35-60deb42c1ab2)


🐛 Known Issues
No support for exponentiation (^)
Does not handle trigonometric or logarithmic functions
Currently supports only integer and decimal numbers

🤝 Contributing
Want to improve this project? Follow these steps:
1️⃣ Fork the repository
2️⃣ Create a new branch (git checkout -b feature-branch)
3️⃣ Make your changes and commit (git commit -m "Add new feature")
4️⃣ Push to the branch (git push origin feature-branch)
5️⃣ Open a Pull Request

📜 License
This project is open-source and available under the MIT License.

⭐ If you like this project, consider giving it a star! ⭐

# Student Report Card Generator

A minimalistic C++ project for generating and managing student report cards. This program allows admins and students to log in, view, modify, and delete student records, and calculate grades based on marks.

---

## Features

- **Admin Login**:
  - Create new student and admin accounts.
  - Add, modify, or delete student records.
  - View all student records or search by roll number.
  - Display class results with average percentage.

- **Student Login**:
  - View personal report card.
  - View class results.
  - Search for other student records.

- **Grade Calculation**:
  - Automatically calculates percentage and grade based on marks in 8 subjects.

---

## How to Use

1. **Compile the Program**:
   - Use a C++ compiler (e.g., `g++`) to compile the code:
     ```bash
     g++ Student_Report_Card_Generator.cpp -o report_card
     ```

2. **Run the Program**:
   - Execute the compiled program:
     ```bash
     ./report_card
     ```

3. **Main Menu**:
   - Choose between **Admin Login** or **Student Login**.
   - Follow the on-screen instructions to perform actions like adding records, viewing results, or modifying data.

---

## File Structure

- **`student.dat`**: Binary file storing student records.
- **`data.dat`**: Stores admin login credentials.
- **`stData.dat`**: Stores student login credentials.

---

## Notes

- Admins can create new accounts and manage student data.
- Students can only view their records and class results.
- Ensure the data files (`student.dat`, `data.dat`, `stData.dat`) are in the same directory as the executable.

---

## Author

Developed by **M.i Shaown**.

---

## License

This project is open-source and free to use. Modify and distribute as needed.

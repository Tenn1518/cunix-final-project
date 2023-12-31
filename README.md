# cunix-final-project
Result Management System

**Objective:** Develop a console-based Result Management System in C that allows
teachers to login to upload and manage student’s marks and permits students to view
their individual marks only.

**Usage:** Only teachers can register their accounts.  They can add course names
and create student accounts.  The expectation is that teachers will create
student accounts for each student, and then give the ID to the students for them
to login.  Students are only able to view their grades, which will be printed as
output on login.

### Specifications:
- Roles:
  - Teacher: Allowed to upload, view, edit, and manage student marks.
  - Student: Allowed to view their individual marks.
- File I/O:
  - One file used to store credentials
  - Another file to store student data and their marks in a file.  You'll use
    this file for reading and updating data.
- Teacher Features:
  - Login
  - Upload Grades
  - Edit Grades
  - Sort Grades
  - View Grades
  - Statistics
  - Student Search
- Student Features:
  - Login
  - View Grades.

Design a clear and concise main menu to navigate between roles (teacher or
student).

## Compile

```
$ git clone https://github.com/Tenn1518/cunix-final-project.git

$ cd cunix-final-project

$ gcc -o main main.c data.c commands.c

$ ./main
```

CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    department VARCHAR(50)
);

INSERT INTO employees (id, name, age, department)
VALUES
    (1, 'John Doe', 30, 'HR'),
    (2, 'Jane Smith', 25, 'Marketing'),
    (3, 'Michael Johnson', 40, 'Finance'),
    (4, 'Emily Brown', 28, 'Sales'),
    (5, 'William Lee', 35, 'Engineering'),
    (6, 'Olivia Wilson', 29, 'HR'),
    (7, 'James Anderson', 42, 'Operations'),
    (8, 'Emma Davis', 27, 'Marketing'),
    (9, 'Alexander Martinez', 33, 'Finance'),
    (10, 'Sophia Rodriguez', 31, 'Engineering')
 
 SELE*FROM employees;
CREATE TABLE EMPLOYEE (
  empId INT PRIMARY KEY,
  name VARCHAR(50) NOT NULL,
  dept VARCHAR(20),
  salary DECIMAL(10,2),
  hire_date DATE DEFAULT CURRENT_DATE
);


-- Table with auto-increment and foreign key
CREATE TABLE orders (
  order_id INT AUTO_INCREMENT PRIMARY KEY,
  emp_id INT,
  amount DECIMAL(10,2),
  order_date DATETIME DEFAULT NOW(),
  FOREIGN KEY (emp_id) REFERENCES EMPLOYEE(empId)
);

CREATE TABLE employee_backup (
  empId INT PRIMARY KEY,
  name VARCHAR(50) NOT NULL,
  dept VARCHAR(20),
  salary DECIMAL(10,2),
  hire_date DATE DEFAULT CURRENT_DATE
);

INSERT INTO EMPLOYEE (empId, name, dept, salary)
VALUES (1, 'Clark', 'Sales', 50000);

INSERT INTO EMPLOYEE (empId, name, dept, salary)
VALUES (2, 'Dave', 'Accounting', 45000);

INSERT INTO EMPLOYEE (empId, name, dept, salary)
VALUES (3, 'Ava', 'Sales', 55000);

-- Insert multiple rows at once
INSERT INTO EMPLOYEE (empId, name, dept, salary) VALUES
  (4, 'Bob', 'Engineering', 65000),
  (5, 'Eve', 'HR', 52000);

-- Insert with default values
INSERT INTO EMPLOYEE (empId, name) VALUES (6, 'Charlie');

-- Insert from select
INSERT INTO employee_backup SELECT * FROM EMPLOYEE;

-- Select all
SELECT * FROM EMPLOYEE;

-- Select specific columns
SELECT name, salary FROM EMPLOYEE;

-- Select with condition
SELECT * FROM EMPLOYEE WHERE dept = 'Sales';

-- Select with multiple conditions
SELECT * FROM EMPLOYEE WHERE dept = 'Sales' AND salary > 50000;

-- Select with pattern matching
SELECT * FROM EMPLOYEE WHERE name LIKE 'A%';

-- Select with ordering
SELECT * FROM EMPLOYEE ORDER BY salary DESC;

-- Select with limit and offset (pagination)
SELECT * FROM EMPLOYEE LIMIT 10 OFFSET 20;

-- Select with BETWEEN
SELECT * FROM EMPLOYEE WHERE salary BETWEEN 45000 AND 60000;


-- Update single column
UPDATE EMPLOYEE SET dept = 'Marketing' WHERE empId = 1;

-- Update multiple columns
UPDATE EMPLOYEE SET dept = 'Sales', salary = 52000 WHERE empId = 2;

-- Update with calculation
UPDATE EMPLOYEE SET salary = salary * 1.10 WHERE dept = 'Engineering';

-- Update with subquery
UPDATE EMPLOYEE SET salary = (SELECT avg_sal FROM (SELECT AVG(salary) AS avg_sal FROM EMPLOYEE) AS tmp)
WHERE empId = 3;

-- Update with LIMIT
UPDATE EMPLOYEE SET salary = salary + 1000 WHERE dept = 'Sales' LIMIT 2;

-- Delete specific row
DELETE FROM EMPLOYEE WHERE empId = 1;

-- Delete with condition
DELETE FROM EMPLOYEE WHERE dept = 'Sales' AND salary < 45000;

-- Delete with subquery
DELETE FROM EMPLOYEE
WHERE salary < (SELECT AVG(salary) FROM (SELECT salary FROM EMPLOYEE) AS temp);

-- Delete with limit
DELETE FROM EMPLOYEE WHERE dept = 'Inactive' LIMIT 100;

-- Remove all data (keeps table structure)
TRUNCATE TABLE orders;
TRUNCATE TABLE EMPLOYEE;


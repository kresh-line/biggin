
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

select * from EMPLOYEE;
select name, dept from EMPLOYEE;
select name, salary from EMPLOYEE;
select * from  EMPLOYEE where dept='sales';
select * from  EMPLOYEE where dept='sales' and salary>50000;
select * from EMPLOYEE  where name  like 'A%';
select * from EMPLOYEE order by  salary desc;
select * from EMPLOYEE  where salary>=45000 and salary<=60000;
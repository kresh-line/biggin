-- Hapi 1: Ekzekuto vetëm këtë bllok fillimisht (selekto dhe Run)
DROP TABLE IF EXISTS EMPLOYEE;
CREATE TABLE EMPLOYEE (
empId INTEGER PRIMARY KEY,
name TEXT NOT NULL,
dept TEXT NOT NULL
);
INSERT INTO EMPLOYEE VALUES (1, 'Clark', 'Sales');
INSERT INTO EMPLOYEE VALUES (2, 'Dave', 'Accounting');
INSERT INTO EMPLOYEE VALUES (3, 'Ava', 'Sales');

-- Hapi 2: Pastaj selekto vetëm këtë rresht dhe Run
SELECT * FROM EMPLOYEE WHERE dept = 'Sales';
SELECT * FROM EMPLOYEE WHERE dept = 'Accounting';


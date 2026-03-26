

DROP TABLE IF EXISTS teachers;

CREATE TABLE teachers (
    teacher_id INT NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phone_number VARCHAR(20),
    k_id_d INT,
    PRIMARY KEY (teacher_id)
);

-- Shto te dhenat ketu posht:
INSERT INTO teachers (teacher_id, first_name, last_name, email, phone_number, k_id_d) VALUES
(001, 'John', 'Doe', 'john.doe@example.com', '123-456-7890', 001),
(002, 'Maria', 'Smith', 'maria.smith@example.com', '123-456-7891', 002),
(003, 'Robert', 'Brown', 'robert.brown@example.com', '123-456-7892', 001),
(004, 'Anna', 'White', 'anna.white@example.com', '123-456-7893', 003),
(005, 'James', 'Wilson', 'james.wilson@example.com', '123-456-7894', 002);





-- Shiko te dhenat:
SELECT * FROM teachers;


--CREATE TABLE axiologies (
    --axiology_id INT NOT NULL,
    --teacher_id INT NOT NULL,
    --subject VARCHAR(100) NOT NULL,
    --PRIMARY KEY (axiology_id),
    --FOREIGN KEY (teacher_id) REFERENCES teachers(teacher_id)
--);
-- ============================================
-- DEMO: B-TREE INDEX NË MARIADB
-- ============================================

-- 1. Krijo databazën
DROP DATABASE IF EXISTS btree_demo;
CREATE DATABASE btree_demo;
USE btree_demo;

-- 2. Krijo tabelën (InnoDB përdor B+Tree automatikisht)
CREATE TABLE studentet (
    id INT PRIMARY KEY AUTO_INCREMENT,
    emri VARCHAR(50),
    mbiemri VARCHAR(50),
    mosha INT,
    qyteti VARCHAR(50),
    nota DECIMAL(4,2)
) ENGINE=InnoDB;

-- 3. Krijo procedurën që mbush 100,000 rekorde
DELIMITER $$
CREATE PROCEDURE mbush_te_dhena()
BEGIN
    DECLARE i INT DEFAULT 0;
    WHILE i < 100000 DO
        INSERT INTO studentet (emri, mbiemri, mosha, qyteti, nota)
        VALUES (
            CONCAT('Emri_', i),
            CONCAT('Mbiemri_', i),
            FLOOR(18 + RAND() * 12),
            ELT(FLOOR(1 + RAND() * 5), 'Heraklio', 'Athina', 'Selanik', 'Patra', 'Larisa'),
            ROUND(5 + RAND() * 5, 2)
        );
        SET i = i + 1;
    END WHILE;
END$$
DELIMITER ;

-- 4. Ekzekuto procedurën (do zgjasë 30-60 sekonda)
CALL mbush_te_dhena();

-- 5. Verifiko sa rekorde u futën
SELECT COUNT(*) AS total_rekorde FROM studentet;
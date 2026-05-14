-- Krijo databazën nëse nuk ekziston
CREATE DATABASE IF NOT EXISTS productsdb;
USE productsdb;

-- Krijo tabelën products
CREATE TABLE IF NOT EXISTS products (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    description VARCHAR(255),
    price DECIMAL(10,2) NOT NULL
);

-- Shto produkte
INSERT INTO products (id, name, price, catid) VALUES
(1, 'Laptop',    1299.99, ''),
(2, 'Mouse Wireless Logitech', 29.99, '
(4, 'Monitor 24 inç',        249.99, 'Monitor Full HD IPS 144Hz'),
(5, 'Kufje Sony WH-1000XM5', 349.99, 'Kufje me anulim zhurmash'),

-- Krijo databazën nëse nuk ekziston
CREATE DATABASE IF NOT EXISTS shop;
USE shop;

-- Krijo tabelën products
CREATE TABLE IF NOT EXISTS products (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    description VARCHAR(255),
    price DECIMAL(10,2) NOT NULL
);

-- Shto produkte
INSERT INTO products (name, price, description) VALUES
('Laptop Dell XPS 15',    1299.99, 'Laptop i fuqishëm me ekran 15.6 inç'),
('Mouse Wireless Logitech', 29.99, 'Maus pa tel me bateri të gjatë'),
('Tastierë Mekanike',      79.99, 'Tastierë gaming me ndriçim RGB'),
('Monitor 24 inç',        249.99, 'Monitor Full HD IPS 144Hz'),
('Kufje Sony WH-1000XM5', 349.99, 'Kufje me anulim zhurmash'),
('Telefon Samsung A54',   399.99, 'Smartphone 5G me kamerë 50MP'),
('Tablet iPad Air',       699.99, 'Tablet Apple me çip M1'),
('SSD 1TB Samsung',        89.99, 'Disk SSD NVMe M.2 1 terabajt'),
('Webcam Logitech C920',   79.99, 'Kamerë HD 1080p për streaming'),
('Karigar USB-C 65W',      24.99, 'Karigar i shpejtë universali');

-- =====================================================
-- Βάση δεδομένων: productsdb
-- Πίνακας: products
-- Το πεδίο catid αντιστοιχεί στο id του πίνακα category
-- Εισαγωγή: επιλέξτε πρώτα τη βάση productsdb και μετά Import
-- =====================================================

DROP TABLE IF EXISTS `products`;
CREATE TABLE `products` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(150) NOT NULL,
  `price` DECIMAL(10,2) NOT NULL,
  `catid` INT(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `catid` (`catid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `products` (`id`, `name`, `price`, `catid`) VALUES
(1,  'Φορητός Υπολογιστής Lenovo IdeaPad',      649.90, 1),
(2,  'Φορητός Υπολογιστής Dell Inspiron 15',    729.00, 1),
(3,  'Φορητός Υπολογιστής HP Pavilion',         799.50, 1),
(4,  'Επιτραπέζιος Υπολογιστής HP Pro Tower',   549.00, 2),
(5,  'Επιτραπέζιος Υπολογιστής Dell OptiPlex',  689.00, 2),
(6,  'Οθόνη Samsung 24 ιντσών Full HD',         139.99, 3),
(7,  'Οθόνη LG UltraGear 27 ιντσών',            259.00, 3),
(8,  'Οθόνη AOC 22 ιντσών',                      99.90, 3),
(9,  'Σκληρός Δίσκος Seagate 1TB',               54.90, 4),
(10, 'Σκληρός Δίσκος Western Digital 2TB',       74.50, 4),
(11, 'Δίσκος SSD Samsung 970 EVO 500GB',         69.90, 5),
(12, 'Δίσκος SSD Kingston A400 480GB',           42.00, 5),
(13, 'Δίσκος SSD Crucial MX500 1TB',             89.90, 5);

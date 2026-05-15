-- =====================================================
-- Βάση δεδομένων: productsdb
-- Πίνακας: category
-- Εισαγωγή: επιλέξτε πρώτα τη βάση productsdb και μετά Import
-- =====================================================

DROP TABLE IF EXISTS `category`;
CREATE TABLE `category` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `category` (`id`, `name`) VALUES
(1, 'Laptops'),
(2, 'Desktop'),
(3, 'Monitors'),
(4, 'HDD'),
(5, 'SSD');

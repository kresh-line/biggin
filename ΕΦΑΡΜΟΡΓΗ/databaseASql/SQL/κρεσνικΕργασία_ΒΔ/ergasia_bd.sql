-- ============================================================
-- Εργασία Βάσεις Δεδομένων
-- Τοπικό Πρωτάθλημα Ποδοσφαίρου
-- ============================================================

-- ============================================================
-- ΑΣΚΗΣΗ 2: Δημιουργία Πινάκων (CREATE TABLE - DDL)
-- ============================================================

CREATE TABLE SYLLOGOS (
    AM_Syllogou     INT PRIMARY KEY,
    Eponimia        VARCHAR(100) NOT NULL,
    Kat             CHAR(1),
    Imnia_Sistasis  DATE
);

CREATE TABLE PROPONITIS (
    AFM         BIGINT PRIMARY KEY,
    Onoma       VARCHAR(100) NOT NULL,
    Tilefono    VARCHAR(20),
    Diefthinsi  VARCHAR(100)
);

CREATE TABLE ATHLITIS (
    AD_Athliti      INT PRIMARY KEY,
    Imnia_Genn      DATE,
    Onoma           VARCHAR(100) NOT NULL,
    Ypsos           DECIMAL(3,2),
    Varos           INT,
    AM_Syllogou     INT,
    FOREIGN KEY (AM_Syllogou) REFERENCES SYLLOGOS(AM_Syllogou)
);

CREATE TABLE AGONAS (
    Kod_Agona   BIGINT PRIMARY KEY,
    Imnia       DATE,
    Ora         TIME,
    Typos       VARCHAR(20)
);

CREATE TABLE SYMMETOXI (
    AD_Athliti  INT,
    Kod_Agona   BIGINT,
    PRIMARY KEY (AD_Athliti, Kod_Agona),
    FOREIGN KEY (AD_Athliti) REFERENCES ATHLITIS(AD_Athliti),
    FOREIGN KEY (Kod_Agona) REFERENCES AGONAS(Kod_Agona)
);


-- ============================================================
-- ΑΣΚΗΣΗ 3: Εισαγωγή Δεδομένων (INSERT INTO - DML)
-- ============================================================

-- ΣΥΛΛΟΓΟΣ
INSERT INTO SYLLOGOS VALUES (12362, 'Κεραυνός Πρινέ', 'Β', '1956-05-29');
INSERT INTO SYLLOGOS VALUES (14284, 'Δόξα Ατσιπόπουλου', 'Α', '1966-09-01');
INSERT INTO SYLLOGOS VALUES (8532, 'Θύελλα Ραφήνας', 'Α', '1949-04-19');
INSERT INTO SYLLOGOS VALUES (48593, 'Αναγέννηση Ευόσμου', 'Β', '1975-07-22');
INSERT INTO SYLLOGOS VALUES (84672, 'Πόντιοι Βέροιας', 'Γ', '1994-09-19');
INSERT INTO SYLLOGOS VALUES (992, 'Αλθαμένης Κρηττηνίας', 'Β', '1937-06-13');
INSERT INTO SYLLOGOS VALUES (91125, 'Α.Ο. Σύρου', 'Γ', '1994-10-22');

-- ΠΡΟΠΟΝΗΤΗΣ
INSERT INTO PROPONITIS VALUES (114578368, 'Ξάφης Σπ.', '6978123456', 'Μιλάτου 64');
INSERT INTO PROPONITIS VALUES (109845375, 'Μελετίου Χρ.', '6977987654', 'Ούλαφ Πάλμε 45');
INSERT INTO PROPONITIS VALUES (136978564, 'Νύκτας Μ.', '6976321789', 'Ιωνίας 108');
INSERT INTO PROPONITIS VALUES (189645875, 'Χουρδάκης Εμμ.', '6974741258', 'Κονδυλάκη 24');
INSERT INTO PROPONITIS VALUES (149865326, 'Δρακόπουλος Π.', '6975369852', 'Θερίσου 75');
INSERT INTO PROPONITIS VALUES (198764132, 'Βούζας Ελ.', '6977741529', 'Κνωσού 231');
INSERT INTO PROPONITIS VALUES (157346753, 'Σαρρής Νικ.', '6972617865', 'Γερωνυμάκη 32');

-- ΑΘΛΗΤΗΣ
INSERT INTO ATHLITIS VALUES (8653, '2004-06-03', 'Παππάς Χρ.', 1.84, 86, 84672);
INSERT INTO ATHLITIS VALUES (1472, '2003-09-17', 'Μπαλωμένος Γ.', 1.92, 93, 992);
INSERT INTO ATHLITIS VALUES (588, '2003-05-28', 'Ηλιάκης Θ.', 1.78, 74, 12362);
INSERT INTO ATHLITIS VALUES (4127, '2004-07-04', 'Μπλαζάκης Δημ.', 1.76, 72, 84672);
INSERT INTO ATHLITIS VALUES (6533, '2005-03-12', 'Ιωάννου Γ.', 1.82, 80, 91125);
INSERT INTO ATHLITIS VALUES (5178, '2002-07-06', 'Ράλλης Αν.', 1.69, 70, 48593);
INSERT INTO ATHLITIS VALUES (2365, '2004-04-21', 'Γλιτσός Ευάγγ.', 1.80, 76, 8532);
INSERT INTO ATHLITIS VALUES (1024, '2003-02-08', 'Κυριακάκης Εμμ.', 1.94, 94, 14284);

-- ΑΓΩΝΑΣ
INSERT INTO AGONAS VALUES (2015348, '2025-03-03', '16:00:00', 'ΠΡΩΤΑΘΛΗΜΑ');
INSERT INTO AGONAS VALUES (20141322, '2024-04-04', '18:00:00', 'ΚΥΠΕΛΛΟ');
INSERT INTO AGONAS VALUES (20151124, '2025-05-05', '18:00:00', 'ΠΡΩΤΑΘΛΗΜΑ');
INSERT INTO AGONAS VALUES (2014938, '2024-06-06', '16:00:00', 'ΦΙΛΙΚΟ');
INSERT INTO AGONAS VALUES (2015362, '2025-07-07', '12:00:00', 'ΠΡΩΤΑΘΛΗΜΑ');
INSERT INTO AGONAS VALUES (20142033, '2024-08-08', '18:00:00', 'ΚΥΠΕΛΛΟ');
INSERT INTO AGONAS VALUES (201542, '2025-09-09', '16:00:00', 'ΦΙΛΙΚΟ');

-- ΣΥΜΜΕΤΟΧΗ
INSERT INTO SYMMETOXI VALUES (588, 2015348);
INSERT INTO SYMMETOXI VALUES (1024, 20141322);
INSERT INTO SYMMETOXI VALUES (588, 20151124);
INSERT INTO SYMMETOXI VALUES (1024, 2014938);
INSERT INTO SYMMETOXI VALUES (588, 2015362);
INSERT INTO SYMMETOXI VALUES (5178, 2015348);
INSERT INTO SYMMETOXI VALUES (8653, 20141322);
INSERT INTO SYMMETOXI VALUES (8653, 2015362);
INSERT INTO SYMMETOXI VALUES (5178, 20151124);


-- ============================================================
-- ΑΣΚΗΣΗ 4: Προσθήκη πεδίου Προπονητής στον πίνακα ΣΥΛΛΟΓΟΣ
--           (ALTER TABLE + UPDATE)
-- ============================================================

ALTER TABLE SYLLOGOS ADD Proponitis VARCHAR(100);

-- Αντιστοίχιση με τη σειρά εμφάνισης στον πίνακα ΠΡΟΠΟΝΗΤΗΣ
UPDATE SYLLOGOS SET Proponitis = 'Ξάφης Σπ.' WHERE AM_Syllogou = 12362;
UPDATE SYLLOGOS SET Proponitis = 'Μελετίου Χρ.' WHERE AM_Syllogou = 14284;
UPDATE SYLLOGOS SET Proponitis = 'Νύκτας Μ.' WHERE AM_Syllogou = 8532;
UPDATE SYLLOGOS SET Proponitis = 'Χουρδάκης Εμμ.' WHERE AM_Syllogou = 48593;
UPDATE SYLLOGOS SET Proponitis = 'Δρακόπουλος Π.' WHERE AM_Syllogou = 84672;
UPDATE SYLLOGOS SET Proponitis = 'Βούζας Ελ.' WHERE AM_Syllogou = 992;
UPDATE SYLLOGOS SET Proponitis = 'Σαρρής Νικ.' WHERE AM_Syllogou = 91125;


-- ============================================================
-- ΑΣΚΗΣΗ 5: Αλλαγή ονομάτων αθλητών με αγαπημένους
--           ποδοσφαιριστές (UPDATE)
-- ============================================================

UPDATE ATHLITIS SET Onoma = 'Messi Lionel' WHERE AD_Athliti = 8653;
UPDATE ATHLITIS SET Onoma = 'Ronaldo Cristiano' WHERE AD_Athliti = 1472;
UPDATE ATHLITIS SET Onoma = 'Mbappé Kylian' WHERE AD_Athliti = 588;
UPDATE ATHLITIS SET Onoma = 'Haaland Erling' WHERE AD_Athliti = 4127;
UPDATE ATHLITIS SET Onoma = 'Bellingham Jude' WHERE AD_Athliti = 6533;
UPDATE ATHLITIS SET Onoma = 'Vinícius Jr.' WHERE AD_Athliti = 5178;
UPDATE ATHLITIS SET Onoma = 'De Bruyne Kevin' WHERE AD_Athliti = 2365;
UPDATE ATHLITIS SET Onoma = 'Salah Mohamed' WHERE AD_Athliti = 1024;


-- ============================================================
-- ΑΣΚΗΣΗ 6: SQL Ερωτήματα (SELECT Queries)
-- ============================================================

-- 6.1: Επωνυμίες ομάδων Β κατηγορίας
SELECT Eponimia
FROM SYLLOGOS
WHERE Kat = 'Β';

-- 6.2: Ονόματα και ύψος αθλητών με ύψος >= 1.80
SELECT Onoma, Ypsos
FROM ATHLITIS
WHERE Ypsos >= 1.80;

-- 6.3: Ημερομηνίες αγώνων πρωταθλήματος
SELECT Imnia
FROM AGONAS
WHERE Typos = 'ΠΡΩΤΑΘΛΗΜΑ';

-- 6.4: Όνομα, τηλέφωνο, διεύθυνση προπονητή Αναγέννησης Ευόσμου
SELECT P.Onoma, P.Tilefono, P.Diefthinsi
FROM PROPONITIS P, SYLLOGOS S
WHERE S.Proponitis = P.Onoma
  AND S.Eponimia = 'Αναγέννηση Ευόσμου';

-- 6.5: Ονόματα αθλητών που παίζουν σε αγώνες κυπέλου
SELECT A.Onoma
FROM ATHLITIS A, SYMMETOXI S, AGONAS AG
WHERE A.AD_Athliti = S.AD_Athliti
  AND S.Kod_Agona = AG.Kod_Agona
  AND AG.Typos = 'ΚΥΠΕΛΛΟ';

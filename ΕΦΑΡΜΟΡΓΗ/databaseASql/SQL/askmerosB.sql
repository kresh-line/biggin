create database askmerosB;

use askmerosB;

create table Kathghths 
(
    KK int primary key,
    Ονομα varchar(255) not null,
    Επονυμο varchar(255) not null,
    Μισθος decimal(10, 2) not null
);

create table Mathimata
(
    Cid int primary key,
    Τιτλος varchar(255) not null,
    KK int not null,
    foreign key (KK) references Kathghths(KK)

);


INSERT INTO Kathghths VALUES (1, 'Nikos', 'Papadopoulos', 2500.00), (2, 'Maria', 'Konstantinou', 2800.00); 
insert into Kathghths values (3, 'Giorgos', 'Lazaridis', 2300.00);
update Kathghths set Μισθος = Μισθος + 500;


INSERT INTO Mathimata VALUES ('CS101', 'Baseis Dedomenwn', 1), ('CS102', 'Programmatismos', 2); 

delete from Mathimata where Cid = 'CS101';

 
SELECT m.Τιτλος, k.Επονυμο
FROM Mathimata m
 INNER JOIN Kathghths k ON m.KK = k.KK;

 
SELECT Επονυμο
FROM Kathghths
WHERE Μισθος > (SELECT AVG(Μισθος) FROM Kathghths);


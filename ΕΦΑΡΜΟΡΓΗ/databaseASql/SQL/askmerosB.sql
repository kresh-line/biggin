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
INSERT INTO Mathimata VALUES ('CS101', 'Baseis Dedomenwn', 1), ('CS102', 'Programmatismos', 2); 


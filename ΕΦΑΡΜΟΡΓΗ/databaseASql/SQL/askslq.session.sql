/*SELECT c.customerNumber,
       c.customerName,
       c.phone,
       p.checkNumber,
       p.paymentDate,
       p.amount
FROM customers c
JOIN payments p
  ON c.customerNumber = p.customerNumber;
  */

/*SELECT e.lastName, e.firstName, e.jobTitle, o.phone, o.country FROM employees e JOIN offices o ON e.officeCode = o.officeCode WHERE e.jobTitle LIKE '%Rep%' AND o.country <> 'USA';*/

-- Ushtrim 4: Emri, vendi dhe telefoni i klientit + numri dhe data e porosisë
-- për të gjitha porositë e dërguara në vitin 2004, të renditura zbritshëm sipas datës së dërgimit
/*SELECT c.customerName,
       c.country,
       c.phone,
       o.orderNumber,
       o.orderDate
FROM customers c
JOIN orders o ON c.customerNumber = o.customerNumber
WHERE YEAR(o.shippedDate) = 2004
ORDER BY o.shippedDate DESC;*/

-- Ushtrim 5: Numri i porosisë, statusi, kodi dhe sasia e produktit
-- për porositë e tremujorit të parë 2003 me sasi > 40, zbritshëm sipas sasisë
/*SELECT o.orderNumber,
       o.status,
       od.productCode,
       od.quantityOrdered
FROM orders o
JOIN orderdetails od ON o.orderNumber = od.orderNumber
WHERE o.orderDate BETWEEN '2003-01-01' AND '2003-03-31'
  AND od.quantityOrdered > 40
ORDER BY od.quantityOrdered DESC;*/

-- Ushtrim 6: Numri dhe data e porosisë, emri i produktit, rreshti, sasia dhe çmimi
-- për porositë e Marsit 2005, rritshëm sipas numrit të porosisë dhe rreshtit
/*SELECT o.orderNumber,
       o.orderDate,
       p.productName,
       od.orderLineNumber,
       od.quantityOrdered,
       od.priceEach
FROM orders o
JOIN orderdetails od ON o.orderNumber = od.orderNumber
JOIN products p     ON od.productCode = p.productCode
WHERE o.orderDate BETWEEN '2005-03-01' AND '2005-03-31'
ORDER BY o.orderNumber ASC, od.orderLineNumber ASC;*/

-- Ushtrim 7: Mbiemri, emri i punonjësit dhe emri i klientit që shërben (LEFT JOIN)
-- rritshëm sipas emrit të klientit
/*SELECT e.lastName,
       e.firstName,
       c.customerName
FROM employees e
LEFT JOIN customers c ON e.employeeNumber = c.salesRepEmployeeNumber
ORDER BY c.customerName ASC;*/

-- Ushtrim 8: Emri i klientëve që nuk kanë bërë asnjë porosi (LEFT JOIN + IS NULL)
SELECT c.customerName
FROM customers c
LEFT JOIN orders o ON c.customerNumber = o.customerNumber
WHERE o.orderNumber IS NULL;




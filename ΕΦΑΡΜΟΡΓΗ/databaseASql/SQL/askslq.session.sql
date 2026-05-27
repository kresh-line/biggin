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

SELECT e.lastName, e.firstName, e.jobTitle, o.phone, o.country FROM employees e JOIN offices o ON e.officeCode = o.officeCode WHERE e.jobTitle LIKE '%Rep%' AND o.country <> 'USA';
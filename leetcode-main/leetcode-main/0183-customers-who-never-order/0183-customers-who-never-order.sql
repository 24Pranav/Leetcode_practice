# Write your MySQL query statement below
# Solution 1
# select c.name As Customers
# FROM customers c
# LEFT JOIN Orders o
# ON c.id=o.customerId
# where o.id IS NULL

#Solution 2
SELECT c.name AS Customers
FROM Customers c
Where c.id NOT IN
(SELECT c.id FROM Customers c INNER JOIN Orders o ON c.id=o.customerId)
## `AND` , `OR` , `NOT`
```sql
SELECT first_name, last_name
FROM Customers
WHERE country = 'USA' AND last_name = 'Doe';

SELECT first_name, last_name
FROM Customers
WHERE country = 'USA' OR last_name = 'Doe';

SELECT first_name, last_name
FROM Customers
WHERE NOT country = 'USA';
```
## DISTINCT
- selects rows with distinct country
```sql
SELECT DISTINCT country
FROM Customers;
```
- Here, the SQL command selects rows if the combination of `country `and `first_name` is unique.
```sql
SELECT DISTINCT country, first_name
FROM Customers;
```
![eg](https://cdn.programiz.com/cdn/farfuture/WP7sxcLj_fxNzSgV5lk_KGTHYtI-8VibWnc3o9z9sA4/mtime:1632998636/sites/tutorial2program/files/sql-select-distinct-2.png)

---
## ALIAS
The `AS` keyword is used to give columns or tables a temporary name that can be used to identify that column or table later.
```sql
-- to identify columns with alias
SELECT customer_id AS cid, first_name AS name
FROM Customers;

-- to identify new column with alias
SELECT CONCAT(first_name, ' ', last_name) AS full_name
FROM Customers;

-- to identify tables with alias
SELECT cu.first_name, cu.last_name
FROM Customers AS cu;
```
---
## `LIMIT` and `OFFSET`
```sql
-- lmits to the first 2 rows
SELECT first_name, age
FROM Customers
LIMIT 2;

-- Here, the SQL command selects 2 rows starting from the fourth row. OFFSET 3 means the first 3 rows are excluded.
SELECT first_name, last_name
FROM Customers
LIMIT 2 OFFSET 3; -- 3 rows after first row and onlt 2 rows to be displayed
-- when you dont use offset the offset default may be 0
```
---
## `IN`
```sql
SELECT first_name, country
FROM Customers
WHERE country IN ('USA', 'UK');

-- NOT IN
SELECT first_name, country
FROM Customers
WHERE country NOT IN ('UK', 'UAE');

-- with subqueries
SELECT customer_id, first_name
FROM Customers 
WHERE customer_id IN (
  SELECT customer_id
  FROM Orders
);
```
---
## `BETWEEN`
```sql
SELECT item, amount
FROM Orders
WHERE amount BETWEEN 300 AND 500;

SELECT item, amount
FROM Orders
WHERE amount NOT BETWEEN 300 AND 500;

SELECT item
FROM Orders
WHERE item BETWEEN 'Key' AND 'Mou';
-- selects all the words in dictionary which may come between them
```
---
## `NULL`
```sql
SELECT COUNT(*)
FROM Employee
WHERE email IS NULL;
```  
---
## MIN,MAX,AVG
```sql
-- Get entire rows containing the minimum age
SELECT *
FROM Customers
WHERE age = (
    SELECT MIN(age)
    FROM Customers
);

-- Here, the SQL command returns max age in each country from the Customers table.
SELECT *
FROM Customers
GROUP BY country
HAVING MAX(age);
```
---
## `COUNT`
```sql
-- Here, the SQL command returns the count of unique countries.
SELECT COUNT(DISTINCT country)
FROM Customers;

-- Here, the SQL command returns the number of customers in each country.
SELECT country, COUNT(*) AS customers
FROM Customers
GROUP BY country;

-- with HAVING
SELECT COUNT(customer_id), country
FROM Customers
GROUP BY country
HAVING COUNT(customer_id) > 1;
```
---
## `ORDER BY`
```sql
-- asc - ascending
-- desc - descending
SELECT *
FROM Customers
ORDER BY first_name, age;
-- Here, the SQL command selects all the records and then sorts them by first_name. If the first_name repeats more than once, it sorts those records by age.
```
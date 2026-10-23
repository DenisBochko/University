-- 1. Создать представление, которое выводит следующие колонки: order_date, required date, shipped date, 
-- ship postal code, company_name, contact name, phone, last name, first name, title из таблиц orders, customers и employees.
-- Сделать select к созданному представлению, выведя все записи, где order_date больше 1-то января 1997 года
CREATE VIEW orders_customers_employees AS 
SELECT order_date, required_date, shipped_date, 
  ship_postal_code, company_name, 
  contact_name, phone, last_name, first_name, title
FROM orders
JOIN customers ON orders.customer_id = customers.customer_id
JOIN employees ON orders.employee_id = employees.employee_id;

SELECT * FROM orders_customers_employees
WHERE order_date > '1997-01-01';

DROP VIEW orders_customers_employees;

-- 2. Создать представление, которое выводит следующие колонки:
-- order_date, required_date, shipped_date, ship_postal_code, 
-- ship_country, company_name, contact_name, phone, last_name, first_name, title из таблиц
-- orders, customers, employees

-- Попробовать добавить к представлению (после его создания) колонки ship_country, postal_code и reports_to 
-- (добавить не в конец, а куда-нибудь посередине). Убедиться, что происходит ошибка.
-- Переименовать представление и создать новое уже с дополнительными колонками;
-- Сделать к нему запрос, выбрав все записи, отсортировав их по
-- ship_country;
-- Удалить переименованное представление.
CREATE VIEW orders_customers_employees AS
SELECT order_date, required_date, shipped_date, ship_postal_code, 
  ship_country, company_name, contact_name, phone, last_name, first_name, title
FROM orders
JOIN customers ON orders.customer_id = customers.customer_id
JOIN employees ON orders.employee_id = employees.employee_id;

-- не сработает
CREATE OR REPLACE VIEW orders_customers_employees AS 
SELECT 
  customers.postal_code, reports_to, -- новые поля
  order_date, required_date, shipped_date, ship_postal_code, 
  ship_country, company_name, contact_name, phone, last_name, first_name, title
FROM orders
JOIN customers ON orders.customer_id = customers.customer_id
JOIN employees ON orders.employee_id = employees.employee_id;

ALTER VIEW orders_customers_employees
RENAME TO orders_customers_employees_old;

-- сработает
CREATE VIEW orders_customers_employees AS 
SELECT 
  order_date, required_date, shipped_date, ship_postal_code, 
  ship_country, company_name, contact_name, phone, last_name, first_name, title,
  customers.postal_code, reports_to -- новые поля 
FROM orders
JOIN customers ON orders.customer_id = customers.customer_id
JOIN employees ON orders.employee_id = employees.employee_id;

SELECT *
FROM orders_customers_employees
ORDER BY ship_country;

DROP VIEW orders_customers_employees_old;

-- 3.Создать представление "активных" (discontinued = 0) продуктов, содержащее все колонки. 
-- Представление должно быть защищено от вставки записей, в которых discontinued = 1.
-- Попробовать сделать вставку записи с полем discontinued = 1 - убедиться, что не проходит.


INSERT INTO customers(customer_id, contact_name, city, country, company_name)
VALUES
    ('AAAAA', 'Alfred Mann', NULL, 'USA', 'fake_company'),
    ('BBBBB', 'Alfred Mann', NULL, 'Austria', 'fake_company');

-- 1. Вывести имя контакта заказчика, его город и страну,
-- отсортировав по возрастанию поимени контакта и городу,
-- а если город равен NULL, то по имени контакта и стране.
-- Проверить результат, используя заранее вставленные строки.
SELECT
    contact_name,
    city,
    country
FROM customers
ORDER BY
    contact_name ASC,
    CASE
        WHEN city IS NULL THEN country
        ELSE city
    END ASC;

SELECT
    customer_id,
    contact_name,
    city,
    country
FROM customers
WHERE customer_id IN ('AAAAA', 'BBBBB')
ORDER BY
    contact_name ASC,
    CASE
        WHEN city IS NULL THEN country
        ELSE city
    END ASC;


-- 2. Вывести наименование продукта, цену продукта и столбец со значениями:
-- too expensive если цена >= 100
-- average если цена >-50 но < 100
-- low price если цена <
SELECT
    product_name,
    unit_price,
    CASE
        WHEN unit_price >= 100 THEN 'too expensive'
        WHEN unit_price >= 50 AND unit_price < 100 THEN 'average'
        WHEN unit_price < 50 THEN 'low price'
        ELSE 'price is not set'
    END AS price_category
FROM products;

SELECT * FROM customers;

-- 3. Найти заказчиков, не сделавших ни одного заказа.
-- Вывести имя заказчика и значение 'no orders' если order id = NULL
SELECT
    c.company_name AS customer_name,
    'no orders' AS order_status
FROM customers AS c
LEFT JOIN orders AS o
    ON o.customer_id = c.customer_id
WHERE o.order_id IS NULL;


-- 4. Вывести ФИО сотрудников и их должности.
-- В случае если должность = Sales Represent ative
-- вывести вместо неё Sales Stuff
SELECT
    CONCAT(first_name, ' ', last_name) AS employee_name,
    CASE
        WHEN title = 'Sales Representative' THEN 'Sales Stuff'
        ELSE title
    END AS job_title
FROM employees;

-- Функция NULLIF в сравнивает два переданных выражения и возвращает NULL,
-- если они равны, или первое выражение, если они не равны.
--
-- COALESCE Заменяет NULL первым значением из списка, которое не равно NULL.

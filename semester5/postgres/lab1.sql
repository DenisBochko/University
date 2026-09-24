-- Выбрать все данные из таблицы customers;
SELECT * FROM customers;

-- Выбрать все записи из таблицы customers,
-- но только колонки "имя контакта" и "город“;
SELECT contact_name, city
FROM customers;

-- Выбрать все записи из таблицы orders, но взять две колонки:
-- идентификатор заказа и колонку, значение в которой мы рассчитываем
-- как разницу между датой отгрузки  и датой формирования заказа;
SELECT order_id, (shipped_date - order_date) AS delivery_days
FROM orders;

-- Выбрать все уникальные города в которых "зарегистрированы" заказчики;
SELECT DISTINCT city
FROM customers;

-- Выбрать все уникальные сочетания городов и стран в которых "зарегистрированы"  заказчики;
-- Суть тут в том, что DISTINCT применяется на всю строку, а не только на одно поле
SELECT DISTINCT city, country
FROM customers;

-- Посчитать кол-во заказчиков;
SELECT COUNT(customer_id)
FROM customers;

-- Посчитать кол-во уникальных стран в которых "зарегистрированы" заказчики;
SELECT COUNT(DISTINCT country)
FROM customers;

-- Выбрать все заказы из стран France, Austria, Spain
SELECT *
FROM orders
WHERE ship_country IN ('France', 'Austria', 'Spain');

-- Выбрать все заказы, отсортировать их по required_date (по убыванию) и
-- отсортировать по дате отгрузке (по возрастанию)
SELECT *
FROM orders
ORDER BY required_date DESC, shipped_date;

-- Выбрать минимальную цену товара среди тех продуктов, которых в продаже более 30 единиц;
SELECT MIN(unit_price)
FROM products
WHERE units_in_stock > 30;

-- Выбрать максимальное кол-во единиц товара среди тех продуктов, цена которых  более 30 у.е.;
SELECT MAX(units_in_stock)
FROM products
WHERE unit_price > 30;

-- Найти среднее значение дней уходящих на доставку с даты формирования заказа в USA;
SELECT ROUND(AVG(shipped_date - order_date), 3)
FROM orders
WHERE ship_country = 'USA' AND shipped_date IS NOT NULL;

-- Найти сумму, на которую имеется товаров (кол-во * цену) причём таких, которые
-- планируется продавать и в будущем (см. на поле discontinued);
SELECT SUM(units_in_stock * unit_price)
FROM products
WHERE discontinued = 0;

-- Выбрать все записи заказов в которых наименование страны отгрузки начинается с 'U';
SELECT *
FROM orders
WHERE ship_country LIKE 'U%';

-- Выбрать записи заказов (включить колонки идентификатора заказа, идентификатора  заказчика, веса и страны отгрузки),
-- которые должны быть отгружены в страны имя  которых начинается с 'N', отсортировать по весу (по убыванию)
-- и вывести только  первые 10 записей;
SELECT order_id, customer_id, freight, ship_country
FROM orders
WHERE ship_country LIKE 'N%'
ORDER BY freight DESC
LIMIT 10;

-- Выбрать записи работников (включить колонки имени, фамилии, телефона, региона)  в которых регион неизвестен;
SELECT first_name, last_name, home_phone, region
FROM employees
WHERE region IS NULL;

-- Подсчитать кол-во заказчиков регион которых известен;
SELECT COUNT(customer_id)
FROM customers
WHERE region IS NULL;

-- Подсчитать кол-во поставщиков в каждой из стран и отсортировать результаты  группировки по убыванию кол-ва;
SELECT country, COUNT(supplier_id) AS suppliers_count
FROM suppliers
GROUP BY country
ORDER BY suppliers_count DESC;

-- Подсчитать суммарный вес заказов (в которых известен регион) по странам, затем  отфильтровать по
-- суммарному весу (вывести только те записи где суммарный вес больше 2750) и отсортировать по
-- убыванию суммарного веса;
SELECT ship_country, SUM(freight) AS sum_freight
FROM orders
WHERE ship_region IS NOT NULL
GROUP BY ship_country
HAVING SUM(freight) > 2750
ORDER BY sum_freight DESC;

-- Выбрать все уникальные страны заказчиков и поставщиков и отсортировать страны по возрастанию;
SELECT country FROM customers
UNION
SELECT country FROM suppliers
ORDER BY country;

-- Выбрать такие страны в которых "зарегистрированы" одновременно и заказчики  и поставщики и работники;
SELECT country FROM customers
INTERSECT
SELECT country FROM suppliers
INTERSECT
SELECT country FROM employees;

-- Выбрать такие страны в которых "зарегистрированы" одновременно заказчики  и поставщики,
-- но при этом в них не "зарегистрированы" работники
SELECT country FROM customers
INTERSECT
SELECT country FROM suppliers
EXCEPT
SELECT country FROM employees;

-- UNION по сути добавляет результаты второго запроса к результатам первого
-- (хотя никакой порядок возвращаемых строк при этом не гарантируется).
-- Более того, эта операция убирает дублирующиеся строки из результата так же,
-- как это делает DISTINCT, если только не указано UNION ALL.
--
-- INTERSECT возвращает все строки, содержащиеся в результате и первого, и второго запроса.
-- Дублирующиеся строки отфильтровываются, если не указано ALL.
--
-- EXCEPT возвращает все строки, которые есть в результате первого запроса, но отсутствуют
-- в результате второго. (Иногда это называют разницей двух запросов.) И здесь дублирующиеся
-- строки отфильтровываются, если не указано ALL.

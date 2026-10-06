-- 1. Найти заказчиков и обслуживающих их заказы сотрудников таких, что и заказчики и сотрудники из города London, а доставка идёт компанией
-- Speedy Express. Вывести компанию заказчика и ФИО сотрудника.
-- Для вывода ФИО одним столбцом можно использовать в секции SELECT функцию CONCAT (first_name, ' ', last name), которая "склеивает" строчные аргументы;
SELECT cu.company_name, CONCAT(emp.first_name, ' ', emp.last_name)
FROM customers cu
JOIN orders ord ON ord.customer_id = cu.customer_id
JOIN employees emp ON emp.employee_id = ord.employee_id
JOIN shippers shp ON shp.shipper_id = ord.ship_via
WHERE cu.city = 'London' AND emp.city = 'London' AND shp.company_name = 'Speedy Express';

-- 2. Найти активные (см. поле discontinued) продукты из категории Beverages и
-- Seafood, которых в продаже менее 20 единиц. Вывести наименование продуктов, кол-во единиц в продаже, имя контакта поставщика и его телефонный номер
SELECT pr.product_name, pr.units_in_stock, sp.contact_name, sp.phone
FROM products pr
JOIN categories ct ON ct.category_id = pr.category_id
LEFT JOIN suppliers sp ON sp.supplier_id = pr.supplier_id
WHERE ct.category_name IN ('Beverages', 'Seafood') AND pr.units_in_stock < 20 AND pr.discontinued = 0;

-- 3. Найти заказчиков, не сделавших ни одного заказа. Вывести имя заказчика и order id
SELECT cu.contact_name, od.order_id
FROM customers cu
LEFT JOIN orders od ON od.customer_id = cu.customer_id
WHERE od.order_id IS NULL
ORDER BY cu.customer_id;

-- 4. Переписать предыдущий запрос, использовав симметричный вид джойна (подсказка: речь о LEFT и RIGHT)
SELECT cu.contact_name, od.order_id
FROM orders od
RIGHT JOIN customers cu ON od.customer_id = cu.customer_id
WHERE od.order_id IS NULL
ORDER BY cu.customer_id;

SELECT product_name, unit_price, units_in_stock,
CASE WHEN units_in_stock >= 100 THEN 'Lots of'
     WHEN units_in_stock >= 50 AND units_in_stock < 100 THEN 'Average'
     WHEN units_in_stock < 50 THEN 'Low number'
     ELSE 'Unknown'
END AS amount
FROM products
ORDER BY units_in_stock DESC;


SELECT order_id, order_date,
CASE WHEN date_part('month', order_date) BETWEEN 3 and 5 THEN 'spring'
      WHEN date_part('month', order_date) BETWEEN 6 and 8 THEN 'summer'
      WHEN date_part('month', order_date) BETWEEN 9 and 11 THEN 'autumn'
      ELSE 'winter'
END AS season
FROM orders
ORDER BY order_date;

SELECT order_id, order_date, COALESCE(ship_region, 'unknown') FROM orders;
SELECT contact_name, COALESCE(NULLIF(city, ''), 'unknown') AS city FROM customers;

SELECT * FROM customers;

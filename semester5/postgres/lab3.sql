-- Первая пачка заданий
-- 1. Создать таблицу teacher с полями teacher_id serial, first_name varchar,
-- last_name varchar, birthday date, phone varchar, title varchar
CREATE TABLE teacher (
    teacher_id SERIAL,
    first_name varchar,
    last_name varchar,
    birthdate date,
    phone varchar,
    title varchar
);

-- 2. Добавить в таблицу после создания колонку middle_name varchar
ALTER TABLE teacher
ADD COLUMN middle_name varchar;

-- 3. Удалить колонку middle name
ALTER TABLE teacher
DROP COLUMN middle_name;

-- 4. Переименовать колонку birthday в birth_date
ALTER TABLE teacher
RENAME birthdate TO birth_date;

-- 5. Изменить тип данных колонки phone на varchar(32)
ALTER TABLE teacher
ALTER COLUMN phone SET DATA TYPE varchar(32);

-- 6. Создать таблицу exam с полями exam id serial, exam_name varchar (256), exam_date date
CREATE TABLE exam (
    id SERIAL,
    exam_name varchar(256),
    exam_date date
);

-- 7. Вставить три любых записи с автогенерацией идентификатора
INSERT INTO exam (exam_name, exam_date)
VALUES ('алгебра', '2026-10-10'), ('русский язык', '2026-10-10'), ('физика', '2026-10-10');

-- 8. Посредством полной выборки убедиться, что данные были вставлены нормально и идентификаторы были сгенерированы с инкрементом
SELECT * FROM exam;

-- 9. Удалить все данные из таблицы со сбросом идентификатор в исходное состояние
TRUNCATE TABLE exam RESTART IDENTITY;

-- Вторая пачка заданий
-- Нужно перед заданиями:
-- CREATE TABLE publisher (
--     publisher_id SERIAL,
--     publisher_name varchar(128) NOT NULL,
--
--     CONSTRAINT PK_publisher_publisher_id PRIMARY KEY (publisher_id)
-- );
--
-- CREATE TABLE book (
--     book_id INT PRIMARY KEY,
--     title TEXT NOT NULL,
--     isbn VARCHAR(32) NOT NULL,
--     publisher_id INT REFERENCES publisher(publisher_id)
-- );

-- 6. Добавить колонку веса в таблицу book (создавали ранее) с ограничением, проверяющим вес (больше 0 но меньше 100)
ALTER TABLE book
ADD COLUMN weight INTEGER CONSTRAINT CH_book_weight CHECK (weight > 0 AND weight < 100);

-- 7. Убедиться в том, что ограничение на вес работает (попробуйте вставить невалидное значение)
INSERT INTO publisher (publisher_name) VALUES ('Денис');

-- не взлетит
INSERT INTO book (book_id, title, isbn, publisher_id, weight)
VALUES (1, 'какое-то название', '1123123123', 1, 0);

-- работать будет
INSERT INTO book (book_id, title, isbn, publisher_id, weight)
VALUES (1, 'какое-то название', '1123123123', 1, 12);

-- 8. Создать таблицу student с полями:
-- - идентификатора (автоинкремент)
-- - полное имя
-- - курс (по умолчанию 1)
CREATE TABLE student (
    student_id SERIAL PRIMARY KEY,
    student_name TEXT NOT NULL,
    year INTEGER DEFAULT 1 NOT NULL
);

-- 9. Вставить запись в таблицу студентов и убедиться, что ограничение на вставку значения по умолчанию работает
INSERT INTO student (student_name) VALUES ('Бочко Денис Андреевич');
INSERT INTO student (student_name, year) VALUES ('Ермаков Генадий Генадиевич', 3);

SELECT * FROM student;

-- 10. Удалить ограничение "по умолчанию" из таблицы студентов
ALTER TABLE student
ALTER COLUMN year DROP DEFAULT;

-- ошибка: null value in column "year" of relation "student" violates not-null constraint
INSERT INTO student (student_name) VALUES ('Бочко Денис Андреевич');

-- 11. Подключиться к БД northwind и добавить ограничение на поле unit price таблицы products (цена должна быть больше 0)
ALTER TABLE products
ADD CONSTRAINT CH_products_unit_price CHECK (unit_price > 0);

# Лабораторная работа №3.

1) Текущий каталог
```bash
cd ~
pwd

/home/denis
```

2) Переключить на другого пользователя.
```bash
su test1
cd ~
pwd

/home/test1
```

3) Создать 3 текстовых файла в домашних каталогах пользовтелей denis, test1, root, затем объеденить их в один у пользователя denis.
```bash
su denis
cd ~
touch d.txt
echo "Это файл Дениса" >> d.txt

su test1
cd ~
touch t.txt
echo "Это файл Теста" >> t.txt

su
cd ~
touch r.txt
echo "Это файл пользователя root" >> r.txt
cat r.txt >> /home/denis/d.txt
cat /home/test1/t.txt >> /home/denis/d.txt
cat /home/denis/d.txt

Это файл Дениса
Это файл пользователя root
Это файл Теста

# Удалить файл: rm /home/denis.d.txt
```
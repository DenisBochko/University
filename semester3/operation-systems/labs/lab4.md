# Лабораторная работа №4.

'''bash
ln       # Создать ярлык
ls -l    # Атрибуты файла

touch t1.txt
touch t2.txt
echo "Это первый файл" >> t1.txt
echo "Это второй файл" >> t2.txt
cat t1.txt t2.txt > t3.txt
cat t3.txt
Это первый файл
Это второй файл

mkdir newdir
mv t1.txt newdir/t1.txt
mv t2.txt newdir/t2.txt
mv t3.txt newdir/t3.txt
ls -l

# -rw-r--r--  1 denis  staff   0 17 сен 09:37 t1.txt
# -rw-r--r--  1 denis  staff   0 17 сен 09:37 t2.txt
# -rw-r--r--  1 denis  staff   0 17 сен 09:40 t3.txt
# обычный файл, доступ владельца, доступ членов группы, доступ для остальных пользователей 
# 1 связь, 0 байт

chmod g+x,o+x t1.txt # владелец u
chmod g+x,o+x t2.txt
chmod g+x,o+x t3.txt

# -rw-r-xr-x  1 denis  staff   0 17 сен 09:37 t1.txt
# -rw-r-xr-x  1 denis  staff   0 17 сен 09:37 t2.txt
# -rw-r-xr-x  1 denis  staff   0 17 сен 09:40 t3.txt

mkdir second
ln -s t3.txt /second/new-t3.txt

cd second
ls -a 
# new-t2.txt

echo "foo1" >> t1.txt 
echo "foo2" >> t1.txt

grep -l foo ./t1.txt 
./t1.txt

grep foo ./t1.txt 
foo1
foo2


top # процессы
'''


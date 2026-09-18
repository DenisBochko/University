function task1() {
    let number = 123456789;
    let sumDigits = 0;

    for (let i = 0; i < String(number).length; i++) {
        sumDigits += Number(String(number)[i]);
    }

  alert(
    `Число: ${number}\n` +
    `Делится ли число на 3 без остатка: ${number % 3 === 0 ? 'да' : 'нет'} \n` +
    `Делится ли сумма цифр числа (${sumDigits}) на 3 без остатка: ${sumDigits % 3 == 0 ? 'да' : 'нет'}`
  );
}

function task2() {
    let test_function = function (a, b) {
        return a + b;
    };

    let elements = [null, 5, 'teststring', [1, 2, 'str1'], test_function];
    let result = '<ul>';

    for (let i = 0; i < elements.length; i++) {
        result += '<li>' + String(elements[i]) + ' — ' + typeof elements[i] + '</li>';
    }

    result += '</ul>';
    document.write(result);
}

function task3() {
    function changeRegister(text) {
        let result = '';

        for (let i = 0; i < text.length; i++) {
            if (text[i] === text[i].toUpperCase()) {
                result += text[i].toLowerCase();
            } else {
                result += text[i].toUpperCase();
            }
        }

        return result;
    }

    let str = 'A1b2C3d4E5g6H';
    alert(`Исходная строка: ${str}\nПолученная строка: ${changeRegister(str)}`);
}

function task4() {
    let array1 = [2, 'name', 4.5, 'str1', 'str2', 9, ['true', 'false'], 0.5];
    let array2 = ['name', 'str1', 'str2', ['true', 'false']];

    function sumNumbers(array) {
        let sum = 0;
        let hasNumbers = false;

        for (let i = 0; i < array.length; i++) {
            if (typeof array[i] === 'number') {
                sum += array[i];
                hasNumbers = true;
            }
        }

        return hasNumbers ? sum : 'Числовых элементов нет';
    }

    alert(`Первый массив: ${sumNumbers(array1)}\nВторой массив: ${sumNumbers(array2)}`);
}

function task5() {
    function isPrime(number) {
        if (number < 2) {
            return false;
        }

        for (let i = 2; i < number; i++) {
            if (number % i === 0) {
                return false;
            }
        }

        return true;
    }

    function getPrimes(from, to) {
        let primes = [];

        for (let i = from; i <= to; i++) {
            if (isPrime(i)) {
              primes.push(i);
            }
        }

        return primes;
    }

    alert(getPrimes(1, 100).join(', '));
}

function task6() {
    function sortArray(array) {
      return array.slice().sort(function (a, b) {
        if (typeof a === 'number' && typeof b === 'number') {
          return a - b;
        }

        return String(a).localeCompare(String(b));
      });
    }

    let numbers = [32, 7, 90, -4, 15, 900, 64];
    let languages = ['HTML', 'RUBY', 'CSS', 'Python', 'C++'];

    alert(`Числа: ${sortArray(numbers).join(', ')}\nСтроки: ${sortArray(languages).join(', ')}`);
}

function task7() {
    function getWeekDay(days) {
        let date = new Date();
        let weekDays = ['воскресенье', 'понедельник', 'вторник', 'среда', 'четверг', 'пятница', 'суббота'];

        date.setDate(date.getDate() + days);
        return weekDays[date.getDay()];
    }

    alert(`Через 5 дней: ${getWeekDay(5)}\nЧерез 177 дней: ${getWeekDay(177)}`);
}

task3();

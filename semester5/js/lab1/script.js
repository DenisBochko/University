function task1() {
    let x = 10;
    let y = 15;
    let z = 0;

    alert(x + y / z); // Infinity
}

function task2() {
    let s1 = "123";
    let s2 = "456";
    let s3 = "name";
    let n = 123;

    alert(s1 + s2); // 123456
    alert(n + s2); // 123456
    alert(n + s3); // 123name
}

function task3() {
    let num1 = 123;
    let num2 = 456;

    alert(`Результат = ${num1 + num2}`); // Результат = 579
}

function task4() {
    let poly = "abcdedcba";
    let test = "teststring";

    function isPalindrome(str) {
        let left = 0;
        let right = str.length - 1;

        while (left < right) {
            if (str[left] !== str[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    alert(isPalindrome(poly)); // true
    alert(isPalindrome(test)); // 
}

function task5() {
    let a = 2;
    let b = 16;
    let c = 99;

    let max;

    if (a > b && a > c) {
        max = a;
    } else if (b > a && b > c) {
        max = b;
    } else {
        max = c;
    }

    alert(max);
}

function task6() {
    let a = Number(prompt("Введите сторону A:"));
    let b = Number(prompt("Введите сторону B:"));
    let c = Number(prompt("Введите сторону C:"));

    if (a + b > c && a + c > b && b + c > a) {
        // По формуле герона
        let p = (a + b + c) / 2;

        let area = Math.sqrt(p * (p - a) * (p - b) * (p - c));

        alert(`Площадь треугольника = ${area}`);
    } else {
        alert("Такого треугольника не существует");
    }

    // 5 6 7: 14.6969
    // 10 12 25: Такого треугольника не существует
}

function task7() {
    let number = Number(prompt("Введите число:"));

    switch (number) {
        case 1:
            alert("Равно 1");
            break;
        case 2:
            alert("Равно 2");
            break;
        case 3:
            alert("Равно 3");
            break;
        default:
            alert("Не равно 1, 2, 3");
    }
}

function task8() {
    let day = Number(prompt("Введите номер дня недели:"))

    function get_week_day(day) {
        switch (day) {
            case 1:
                return "Понедельник";
            case 2:
                return "Вторник";
            case 3:
                return "Среда";
            case 4:
                return "Четверг";
            case 5:
                return "Пятница";
            case 6:
                return "Суббота";
            case 7:
                return "Воскресенье";
            default:
                return "Неверный номер дня";
        }
    }

    alert(get_week_day(day))
}

function task9() {
    let my_name;

    my_name = my_name ?? "Денис";

    let friend_name = "Миша"

    friend_name = friend_name ?? "Вася"

    alert(my_name); // Денис
    alert(friend_name); // Миша
}


function extraTask() {
    function isValidUrl(url) {
        let regexp = /^https?:\/\/.+\.(php|html)$/;
        return regexp.test(url);
    }

    alert(isValidUrl("http://site.ru/index.php")); // true
    alert(isValidUrl("https://site.ru/page.html")); // true
    alert(isValidUrl("http://site.com")); // false
    alert(isValidUrl("site.ru/index.php")); // false
}

//task7();
//extraTask();
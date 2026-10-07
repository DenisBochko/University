function task3() {
    function binaryToDecimal(binaryStr) {
      return parseInt(binaryStr, 2); ;
    }

    alert(
        `'110011' = ${binaryToDecimal('110011')}\n` + // 51
        `'111' = ${binaryToDecimal('111')}` // 7
    );
}

function task4() {
    function bisect(equ, a, b, eps) {
        let leftValue = equ(a);
        let rightValue = equ(b);

        if (leftValue * rightValue > 0) {
            return 'На отрезке нет корня';
        }

        while (b - a > eps) {
            let middle = (a + b) / 2;
            let middleValue = equ(middle);

            if (middleValue === 0) {
                return middle;
            }

            if (leftValue * middleValue < 0) {
                b = middle;
                rightValue = middleValue;
            } else {
                a = middle;
                leftValue = middleValue;
            }
        }

        return (a + b) / 2;
    }

    let firstRoot = bisect(function (x) {
        return x * x - Math.cos(x);
    }, 0, 1, 0.001);

    let secondRoot = bisect(function (x) {
        return x ** 4 + 1.5 - Math.sin(x);
    }, 0, 1, 0.001);

    alert(
        `x² - cos(x): ${typeof firstRoot === 'number' ? firstRoot.toFixed(3) : firstRoot}\n` +
        `x⁴ + 1.5 - sin(x): ${typeof secondRoot === 'number' ? secondRoot.toFixed(3) : secondRoot}`
    );
}

function task5() {
    function showClock() {
        let date = new Date();
        let time = [date.getHours(), date.getMinutes(), date.getSeconds()];

        for (let i = 0; i < time.length; i++) {
            time[i] = String(time[i]).padStart(2, '0');
        }

        document.getElementById('clock').textContent = time.join(':');
    }

    document.write('<h2>Текущее время</h2><p id="clock"></p>');
    showClock();
    setInterval(showClock, 1000);
}

function task6() {
    let users = [
        { name: 'John', age: 30 },
        { name: 'Bob', age: 21 },
        { name: 'Anna', age: 19 }
    ];
    let an_obj = { 100: 'a', 2: 'b', 7: 'c' };
    let menu = { width: 200, height: 300, title: 'My menu' };
    let bob;

    function getKeys(object) {
        return Object.keys(object);
    }

    function addLogs(object) {
        for (let key in object) {
            if (typeof object[key] === 'number') {
                object['log_' + key] = Math.log10(object[key]);
            }
        }
    }

    function removeNonNumeric(object) {
        for (let key in object) {
            if (typeof object[key] !== 'number') {
                delete object[key];
            }
        }
    }

    for (let i = 0; i < users.length; i++) {
        if (users[i].name === 'Bob') {
            bob = users[i];
        }
    }

    addLogs(menu);
    removeNonNumeric(menu);

    document.write(
        '<h2>Объекты</h2>' +
        '<p>Bob: ' + JSON.stringify(bob) + '</p>' +
        '<p>Ключи an_obj: ' + getKeys(an_obj).join(', ') + '</p>' +
        '<p>menu: ' + JSON.stringify(menu) + '</p>'
    );
}

task3();

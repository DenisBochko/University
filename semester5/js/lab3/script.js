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
        let valueOnLeft = equ(a);
        let valueOnRight = equ(b);

        if (valueOnLeft === 0) {
            return a;
        }

        if (valueOnRight === 0) {
            return b;
        }

        if (valueOnLeft * valueOnRight > 0) {
            return 'На отрезке нет смены знака';
        }

        while (b - a > eps) {
          let middle = (a + b) / 2;

          let valueInMiddle = equ(middle);

          if (valueInMiddle === 0) {
            return middle;
          }

          // Оставляем ту половину отрезка, где функция меняет знак.
          if (valueOnLeft * valueInMiddle < 0) {
            b = middle;
          } else {
            a = middle;
            valueOnLeft = valueInMiddle;
          }
        }

        return (a + b) / 2;
    }

    function firstEqu(x) {
        return x * x - Math.cos(x);
    }

    function secondEqu(x) {
        return x ** 4 + 1.5 - Math.sin(x);
    }

    let firstRoot = bisect(firstEqu, 0, 1, 0.001);
    let secondRoot = bisect(secondEqu, 0, 1, 0.001);

    alert(
        `x**2 - cos(x): ${firstRoot}\n` +
        `x**4 + 1.5 - sin(x): ${secondRoot}`
    );
}

function task5() {
    function showClock() {
        let now = new Date();
        let hours = String(now.getHours()).padStart(2, '0');
        let minutes = String(now.getMinutes()).padStart(2, '0');
        let seconds = String(now.getSeconds()).padStart(2, '0');

        document.getElementById('clock').textContent = hours + ':' + minutes + ':' + seconds;
    }

    document.write('<h2>Текущее время</h2><p id="clock"></p>');
    showClock();
    setInterval(showClock, 1000);
}

function task6() {
    let users = [
      {
        name: 'John',
        age: 30
      },
      {
        name: 'Bob',
        age: 21
      },
      {
        name: 'Anna',
        age: 19
      }
    ];

    let u;

    for (let i = 0; i < users.length; i++) {
        if (users[i].name === 'Bob') {
            u = users[i];
            break;
        }
    }

    alert('Имя: ' + u.name + '\nВозраст: ' + u.age);
}

function task7() {
    let an_obj = {
      100: 'a',
      2: 'b',
      7: 'c'
    };

    function getKeys(object) {
      let keys = []
      for (let key in object) {
        keys.push(key)
      }

      return keys
    }

    let keys = getKeys(an_obj);
    alert('Ключи объекта: ' + keys.join(', '));
}

function task8a() {
    let obj = {
        width: 200,
        height: 300,
        title: 'My menu'
    };

    for (let key in obj) {
      if (typeof obj[key] === 'number') {
          obj['log_' + key] = Math.log10(obj[key]);
      }
    }

    let res = ''
    for (let key in obj) {
        res += `key: ${key}, value: ${obj[key]}\n`
    }

    alert(res)
}

function task8b() {
    let obj = {
        width: 200,
        height: 300,
        title: 'My menu'
    };

    for (let key in obj) {
      if (typeof obj[key] !== 'number') {
          delete obj[key];
      }
    }

    let res = ''
    for (let key in obj) {
        res += `key: ${key}, value: ${obj[key]}\n`
    }

    alert(res)
}

task8b();

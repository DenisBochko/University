function task1() {
    let user = {
        name: 'Бочко',
        age: 21,
        city: 'Москва',
        [Symbol.for('a')]: 'Значение A', // for создаёт или находит символ в глобальном реестре символов
        [Symbol.for('b')]: 'Значение B'
    };

    console.log('Object.keys():', Object.keys(user));
    console.log('JSON.stringify():', JSON.stringify(user));
    console.log('Reflect.ownKeys():', Reflect.ownKeys(user));
}

function task2() {
    let firstArray = [1, 2, 3];
    let secondArray = ['a', 'b', 'c'];
    let threeArray = ['Денис', 'Бочко']

    let map = new Map([
        [firstArray, 'Первый массив'],
        [secondArray, 'Второй массив']
    ]);

    map.set(threeArray, 'Третий массив')
    console.log('Map с массивами в качестве ключей:', map);
}

function task3() {
    let user = {
      name: 'Бочко Денис'
    };

    let map = new Map([
        ['age', 20],
        ['city', 'Ростов-на-Дону'],
        [user, 'Студент']
    ]);

    object = Object.fromEntries(map);

    console.log('Исходный Map:', map);
    console.log('Новый объект:', object); // Здесь будет выведено [object Object]
    // т.к. ключом объекта не может быть объект,
    // поэтому он по дефолту приводится к строке
}

function task4() {
    let languages = [
        { Hindi: 91 },
        { English: 91 },
        { French: 45 },
        { Arabic: 25 },
        { Spanish: 24 },
        { Russian: 9 },
        { Portuguese: 9 },
        { Dutch: 8 },
        { German: 7 },
        { Chinese: 5 },
        { Swahili: 4 },
        { Serbian: 4 }
    ];

    let top5 = languages.sort(
        function (a, b) {
            countA = Object.values(a)[0];
            countB = Object.values(b)[0];

            return countB - countA;
        });

    top5 = top5.slice(0, 5);

    console.log('исходный массив:', languages);
    console.log('5 наиболее употребительных языков:', top5);
}

function task5() {
    let arr = [
        'a', 'b', 'a',
        'a', 'c', 'b',
        'a', 'b', 'c'
    ];

    let unique = [...new Set(arr)];

    console.log('Исходный массив:', arr);
    console.log('Массив без повторений:', unique);
}

function task6() {
    function aclean(arr) {
        let map = new Map();

        for (let word of arr) {
            let key = word.toLowerCase().split('').sort().join('');
            map.set(key, word);
        }

        return [...map.values()];
    }

    let arr = ['aBc', 'bca', 'Cab', 'xyz'];

    console.log('Исходный массив:', arr);
    console.log('Массив без анаграмм:', aclean(arr));
}

function task7() {
    function foo(arr, sum) {
        let map = new Map();

        for (let i = 0; i < arr.length; i++) {
            let n = sum - arr[i]; // вычисляем число, которое нужно найти

            if (map.has(n)) {
                return true;
            }

            map.set(arr[i], '');
        }

        return false;
    }

    const sum = -6;

    const firstArray = [-1, -2, -3, -4];
    const secondArray = [1000, 1020, 20];

    console.log('Первый массив:', firstArray);
    console.log('Результат:', foo(firstArray, sum));

    console.log('Второй массив:', secondArray);
    console.log('Результат:', foo(secondArray, sum));
}

task7();

// подписывайтесь на тг канал https://t.me/reelcy0x00

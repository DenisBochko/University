function task1() {
    function Person(name, age, profession = 'unknown') {
        this.name = name;
        this.age = age;
        this.profession = profession;
    }

    const student1 = new Person('Бочко Денис', 20);
    const student2 = new Person('Бондаренко Илья', 25, 'Developer');
    const student3 = new Person('Селин Денис', 30, NaN);

    console.log('Без profession:', student1);
    console.log('С profession:', student2);
    console.log('При profession = NaN:', student3); // присваивается NaN, т.к. параметр передан
}

function task2() {
    const calculator = {
        firstNumber: 0,
        secondNumber: 0,

        read() {
            const firstNumber = Number(prompt('Введите первое число:'));
            const secondNumber = Number(prompt('Введите второе число:'));

            if (!Number.isFinite(firstNumber) || !Number.isFinite(secondNumber)) {
                console.log('Ошибка: необходимо ввести два числа.');
                return false;
            }

            this.firstNumber = firstNumber;
            this.secondNumber = secondNumber;
            return true;
        },

        sum() {
            return this.firstNumber + this.secondNumber;
        },

        mul() {
            return this.firstNumber * this.secondNumber;
        },

        substr() {
            return this.firstNumber - this.secondNumber;
        },

        div() {
            if (this.secondNumber === 0) {
                return 'Деление на ноль невозможно';
            }
            return this.firstNumber / this.secondNumber;
        }
    };

    if (calculator.read()) {
        console.log('Сумма:', calculator.sum());
        console.log('Произведение:', calculator.mul());
        console.log('Разность:', calculator.substr());
        console.log('Частное:', calculator.div());
    }
}

function task3() {
    function Book(title, price) {
        this.title = title;
        this.price = price;
        this.show = function () {
            console.log(`книга: ${this.title}, цена: ${this.price}`);
        };
    }

    const book1 = new Book('Книга 1', 111);
    const book2 = new Book('Книга 2', 222);
    const book3 = new Book('Книга 3', 333);

    book1.show();
    book2.show();
    book3.show();
}

function task4() {
    const ladder = {
        step: 0,
        up() {
            this.step++;
            return this;
        },
        down() {
            if (this.step > 0) {
                this.step--;
            }
            return this;
        },
        showStep() {
            console.log(`Текущая ступенька: ${this.step}`);
            return this;
        }
    };

    ladder.down().showStep();
    ladder.up().up().down().showStep().down().showStep();
}

function task5() {
    const callWithFunction = {
        caller: 'mom',
        says: function () {
            console.log(`Hey, ${this.caller} just called.`);
        }
    };

    const callWithArrow = {
        caller: 'mom',
        says: () => {
            console.log(`Hey, ${this.caller} just called.`);
        }
    };

    callWithFunction.says();
    callWithArrow.says(); // Стрелочная функция не получает this объекта callWithArrow, её this берётся из внешней области
}

function task6() {
    const unique = Symbol('unique');
    const user = {
        name: 'Бочко Денис',
        age: 20,
        profession: 'Student',
        salary: 10,
        [unique]: 'Уникальное значение'
    };

    console.log('Свойства, перечисленные через for...in:');
    for (const key in user) {
        console.log(`${key}: ${user[key]}`);
    }

    console.log('Символьное свойство:', user[unique]);
    console.log('for...in не выводит свойства с ключами Symbol.');
}

task6();

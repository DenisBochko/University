function task1() {
    let student = {
        name: "Артём",
        last_name: "Беспалов",
        year_of_birth: 2006,
        number: 2
    };

    console.log('Свойства объекта: \n')
    for (let key in student) {
      console.log(`ключ: ${key}, значение: ${student[key]}\n`)
    }
}

function task2() {
    let user = {
        name: "Беспалов",
        job: "Developer",
        salary: 100 * 2
    };

    let admin = user;

    admin.name = "Магомедов";
    console.log(`name user: ${user.name}`);

    user = null;
    console.log(`после user=null: ${JSON.stringify(admin)}`);

    let director = admin;
    director.salary += 1000;
    director.job = 'boss';

    console.log(`админ, после изменений у директора: ${JSON.stringify(admin)}`);

    admin = null;
    director = null;

  director = user;

    console.log(`job у директора: ${director.job}`)
}

function task3() {
    function multNum(obj) {
        for (let key in obj) {
            if (typeof obj[key] === 'number') {
                obj[key] *= 2;
            }
        }
    }

    let menu = {
        width: 200,
        height: 300,
        depth: 250,
        title: 'Куб студента Беспалов'
    };

    multNum(menu);
    console.log(JSON.stringify(menu));
}

function task4() {
    function foo(firstObject, secondObject) {
        let result = {};

        for (let key in firstObject) {
            if (key in secondObject && firstObject[key] === secondObject[key]) {
                result[key] = firstObject[key];
            }
        }

        return result;
    }

    let obj1 = { a: 1, b: 2, c: 3, d: 4, e: 5, str1: 31, str2: "Беспалов" };
    let obj2 = { z: 1, w: 2, c: 3, d: 4, e: 5, str1: "family", str2: "Беспалов" };

    console.log(JSON.stringify(foo(obj1, obj2)));
}

function task5() {
  let object = { name: "Беспалов", age: 20, city: "Ростов-на-Дону" };
  console.log(JSON.stringify(Object.entries(object)));
}

function task6() {
    function invertObject(obj) {
        return Object.entries(obj).reduce(function (accumulator, currentValue) {
            accumulator[currentValue[1]] = currentValue[0];
            return accumulator;
        }, {});
    }

    let object = { name: "Беспалов", age: 20, city: "Ростов-на-Дону" };

    console.log(`Исходный объект: ${JSON.stringify(object)} \nИнвертированный объект: ${JSON.stringify(invertObject(object))}`)

}

function task7() {
    let object = {
        js: ['jQuery', 'Angular'],
        php: 'hello',
        css: 'world'
    };

    function findJQuery(obj) {
      return Object.values(obj).flat().find(
        function (item) {
            return item === 'jQuery';
        }
      );
    }

    let jq = findJQuery(object);

    console.log(jq);
}

function task8() {
    let obj2 = {
      title: 'Объект2',
      author: 'Беспалов'
    };

    let obj1 = {
        title: 'Объект1',
        inner_obj: obj2
    };

    let obj3 = structuredClone(obj1);

    obj2.author = 'Магомедов';

    console.log('obj1 после изменения obj2:');
    console.log(JSON.stringify(obj1));

    console.log('obj3 после изменения obj2:');
    console.log(JSON.stringify(obj3));

    console.log('obj1.inner_obj.author:', obj1.inner_obj.author);
    console.log('obj3.inner_obj.author:', obj3.inner_obj.author);
}

task2();

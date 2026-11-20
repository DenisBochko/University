const http = require('http');
const fs = require('fs');
const path = require('path');

const host = '0.0.0.0';
const port = 3000;

function page(title, content) {
  return `
<!doctype html>
<html lang="ru">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>${title}</title>
</head>
<body>
  <nav>
    <a href="/">Главная</a>
    <a href="/about">О проекте</a>
  </nav>
  <main>
    ${content}
  </main>
  <footer>Сервер администрирует: Денис Бочко (Вариант 12)</footer>
</body>
</html>`;
}

const homePage = page(
  'Бронирование отелей', `
  <h1>Бронирование отелей</h1>
  <p>Отель «Орбита» встречает гостей панорамным остеклением и подсветкой фасада.
  В номерах можно настроить освещение по своему вкусу и отдохнуть с видом на вечерний город.
  Чтобы подобрать номер, определите даты поездки и количество гостей.
  Перед бронированием проверьте, включён ли в стоимость завтрак.
  Если планы могут измениться, выбирайте тариф с бесплатной отменой.</p>
  <figure>
    <img src="/media-1" alt="Футуристический фасад отеля с панорамным остеклением" width="700">
    <figcaption>Фасад отеля</figcaption>
  </figure>
  <figure>
    <img src="/media-2" alt="Гостиничный номер с двуспальной кроватью и панорамным окном" width="180">
    <figcaption>Гостиничный номер</figcaption>
  </figure>`
);

const aboutPage = page(
  'О проекте',
  `<h1>О проекте</h1>
  <p>Учебный сайт о бронировании отелей для лабы по JavaScript. Вариант 12.</p>`
);

const notFoundPage = page(
  '404 Страница не найдена',
  `<h1>404 Страница не найдена</h1>
  <p>Проверьте адрес или <a href="/">вернитесь на главную</a>.</p>`
);

function sendHtml(res, status, html) {
  res.writeHead(status, { 'Content-Type': 'text/html; charset=utf-8' });
  res.end(html);
}

function sendImage(res, file) {
  const imagePath = path.join(path.join(__dirname, 'public'), file);

  fs.readFile(imagePath, (error, data) => {
    if (error?.code === 'ENOENT') {
      sendHtml(res, 404, notFoundPage);
      return;
    }

    if (error) {
      const errorPage = page(
        '500 Ошибка сервера',
        `<h1>500 Ошибка сервера</h1>
        <p>Не удалось прочитать изображение.</p>`
      );
      sendHtml(res, 500, errorPage);
      return;
    }

    res.writeHead(200, { 'Content-Type': 'image/png', 'Content-Length': data.length });
    res.end(data);
  });
}

const server = http.createServer((req, res) => {
  if (req.method !== 'GET') {
    res.writeHead(405, { 'Allow': 'GET', 'Content-Type': 'text/plain; charset=utf-8' });
    return res.end('Метод не поддерживается');
  }

  const route = req.url.split('?')[0];

  if (route === '/') return sendHtml(res, 200, homePage);
  if (route === '/about') return sendHtml(res, 200, aboutPage);

  const imageRoutes = {
    '/media-1': 'img1.png',
    '/media-2': 'img2.png',
    '/img1.png': 'img1.png',
    '/img2.png': 'img2.png',
  };

  if (Object.hasOwn(imageRoutes, route)) return sendImage(res, imageRoutes[route]);

  return sendHtml(res, 404, notFoundPage);
});

server.listen(port, host, () => {
  console.log(`Сервер запущен на http://${host}:${port}`);
});

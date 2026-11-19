const http = require('http');
const fs = require('fs');
const path = require('path');

const port = 3000;
const publicDir = path.join(__dirname, 'public');
const lastname = 'Бочко';

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
  <footer>Сервер администрирует: ${lastname} (Вариант 12)</footer>
</body>
</html>`;
}

const home = page('Бронирование отелей', `
  <h1>Бронирование отелей</h1>
  <p>Отель «Орбита» встречает гостей панорамным остеклением и подсветкой фасада.
  В номерах можно настроить освещение по своему вкусу и отдохнуть с видом на вечерний город.
  Чтобы подобрать номер, определите даты поездки и количество гостей.
  Перед бронированием проверьте, включён ли в стоимость завтрак.
  Если планы могут измениться, выбирайте тариф с бесплатной отменой.</p>
  <figure>
    <img src="/media-1" alt="Футуристический фасад отеля с панорамным остеклением">
    <figcaption>Фасад отеля</figcaption>
  </figure>
  <figure>
    <img src="/media-2" alt="Гостиничный номер с двуспальной кроватью и панорамным окном">
    <figcaption>Гостиничный номер</figcaption>
  </figure>`);

const about = page('О проекте', '<h1>О проекте</h1><p>Учебный сайт о бронировании отелей для лабораторной работы № 7 по JavaScript. Вариант 12.</p>');
const notFound = page('404 — Страница не найдена', '<h1>404 — Страница не найдена</h1><p>Проверьте адрес или <a href="/">вернитесь на главную</a>.</p>');

function sendHtml(res, status, html) {
  res.writeHead(
    status,
    {
      'Content-Type': 'text/html; charset=utf-8'
    }
  );
  res.end(html);
}

function sendImage(res, [file, ...fallbacks]) {
  fs.readFile(path.join(publicDir, file), (error, data) => {
    if (error?.code === 'ENOENT') {
      if (fallbacks.length) return sendImage(res, fallbacks);
      return sendHtml(res, 404, notFound);
    }

    if (error) {
      return sendHtml(res, 500, page('500 — Ошибка сервера', '<h1>500 — Ошибка сервера</h1><p>Не удалось прочитать изображение.</p>'));
    }

    const type = path.extname(file) === '.png' ? 'image/png' : 'image/jpeg';

    res.writeHead(200, { 'Content-Type': type, 'Content-Length': data.length });
    res.end(data);
  });
}

const imageRoutes = {
  '/img1.png': ['img1.png'],
  '/img2.png': ['img2.png'],
  '/media-1': ['img1.png'],
  '/media-2': ['img2.png'],
};

const server = http.createServer((req, res) => {
  const route = req.url.split('?')[0];

  if (route === '/') return sendHtml(res, 200, home);
  if (route === '/about') return sendHtml(res, 200, about);

  if (Object.hasOwn(imageRoutes, route)) return sendImage(res, imageRoutes[route]);

  return sendHtml(res, 404, notFound);
})

server.listen(port, () => {
  console.log(`Сервер запущен на порту ${port}`);
});

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
  <script>
    const themeKey = 'orbita-theme';
    const root = document.documentElement;

    try {
      if (localStorage.getItem(themeKey) === 'light') root.dataset.theme = 'light';
    } catch {
      // Переключатель работает и без доступа к хранилищу браузера.
    }

    document.addEventListener('DOMContentLoaded', () => {
      const toggle = document.querySelector('#theme-toggle');
      toggle.setAttribute('aria-pressed', root.dataset.theme === 'light');
      toggle.hidden = false;

      toggle.addEventListener('click', () => {
        const light = root.dataset.theme !== 'light';
        root.dataset.theme = light ? 'light' : 'dark';
        toggle.setAttribute('aria-pressed', light);
        try {
          localStorage.setItem(themeKey, root.dataset.theme);
        } catch {
          // Выбранная тема применяется к текущей странице.
        }
      });
    });
  </script>
  <style>
    :root {
      color-scheme: dark;
      --background: #000;
      --text: #fff;
    }
    :root[data-theme="light"] {
      color-scheme: light;
      --background: #fff;
      --text: #000;
    }
    * { box-sizing: border-box; }
    body {
      margin: 0;
      background: var(--background);
      color: var(--text);
      font: 1rem/1.55 "Courier New", monospace;
    }
    .shell { width: min(1040px, calc(100% - 32px)); margin: clamp(20px, 5vw, 52px) auto; }
    nav { display: flex; align-items: baseline; flex-wrap: wrap; gap: 4px 18px; }
    a { color: inherit; text-underline-offset: 3px; }
    a:hover, .theme-toggle:hover, ::selection { color: var(--background); background: var(--text); }
    a:focus-visible, .theme-toggle:focus-visible { outline: 1px dashed currentColor; outline-offset: 4px; }
    .theme-toggle {
      margin-inline-start: auto;
      padding: 0;
      border: 0;
      background: transparent;
      color: inherit;
      font: inherit;
      cursor: pointer;
    }
    main { margin-block: 18px 22px; padding-block: 24px 0; border-top: 3px double currentColor; }
    h1 { margin: 0 0 14px; font-size: clamp(1.4rem, 4vw, 2.2rem); line-height: 1.2; overflow-wrap: anywhere; }
    p { max-width: 68ch; margin: 0; }
    .intro { display: grid; grid-template-columns: auto minmax(0, 1fr); align-items: center; gap: 24px 32px; }
    .banner { margin: 0; font: clamp(9px, 2.5vw, 15px)/1.05 "Courier New", monospace; }
    .hotel-grid { display: grid; grid-template-columns: repeat(2, minmax(0, 1fr)); gap: 12px 20px; margin-top: 24px; }
    figure { margin: 0; min-width: 0; }
    figcaption { margin-bottom: 6px; padding-top: 6px; border-top: 1px dashed currentColor; font-size: 0.875rem; }
    img { display: block; width: 100%; aspect-ratio: 16 / 9; object-fit: cover; filter: grayscale(1); }
    footer { padding-top: 10px; border-top: 1px dashed currentColor; font-size: 0.875rem; }
    @media (max-width: 760px) { .intro { grid-template-columns: 1fr; } }
    @media (max-width: 540px) {
      .hotel-grid { grid-template-columns: 1fr; }
      .theme-toggle { margin-inline-start: 0; }
    }
  </style>
</head>
<body>
  <div class="shell">
    <nav aria-label="Навигация">
      <span aria-hidden="true">orbita:~$</span>
      <a href="/">[ Главная ]</a><a href="/about">[ О проекте ]</a>
      <button class="theme-toggle" id="theme-toggle" type="button" aria-pressed="false" hidden>[ Светлая тема ]</button>
    </nav>
    <main>
      ${content}
    </main>
    <footer>Сервер администрирует: ${lastname} (Вариант 12)</footer>
  </div>
</body>
</html>`;
}

const home = page('Бронирование отелей', `
  <div class="intro">
    <pre class="banner" aria-hidden="true">          .           *
    *                      .
          +---------------+
          | O R B I T A   |
    +=====+===============+====+
    | [] [] [] [] [] [] [] []  |
    +--------------------------+
    | [] [] [] [] [] [] [] []  |
    +--------------------------+
    | [] [] [] [] [] [] [] []  |
    +---------------+----------+
    |  []  []  []   |  []  []  |
    |               |          |
====+===============+==========+==
  .       .       .       .      .</pre>
    <div>
      <h1>Бронирование отелей</h1>
      <p>Отель «Орбита» встречает гостей панорамным остеклением и подсветкой фасада.
      В номерах можно настроить освещение по своему вкусу и отдохнуть с видом на вечерний город.
      Чтобы подобрать номер, определите даты поездки и количество гостей.
      Перед бронированием проверьте, включён ли в стоимость завтрак.
      Если планы могут измениться, выбирайте тариф с бесплатной отменой.</p>
    </div>
  </div>
  <div class="hotel-grid">
    <figure>
      <figcaption>[ Фасад отеля ]</figcaption>
      <img src="/media-1" alt="Футуристический фасад отеля с панорамным остеклением">
    </figure>
    <figure>
      <figcaption>[ Гостиничный номер ]</figcaption>
      <img src="/media-2" alt="Гостиничный номер с двуспальной кроватью и панорамным окном">
    </figure>
  </div>`);

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

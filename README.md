# CatSplashinator 😺✨

Добро пожаловать в мир котиков! 🐾 Здесь одно нажатие Enter превращает ваш день в пушистое приключение! 😸 Эта дерзкая консольная штука на C++ скачивает случайных котиков с `https://cataas.com/cat` и сохраняет их прямо на ваш диск. Никаких сложностей, только коты и код — всё, как мы любим! 🐱💻

## Что это такое? 🤔
**CatSplashinator** — это кошачий коллекционер, который одним махом (ну, почти) приносит вам нового мурлыку. В первых версиях он открывал котиков в браузере, а теперь загружает их как `cat1.jpg`, `cat2.jpg` и так далее, запоминая последний номер в `last_cat_number.txt`. Хотите нового котика? Жмите Enter! 😼 Для выхода — просто бросьте `q` и уходите с миром. ✌️

**Фишки:**
- Котики появляются быстрее, чем вы скажете "мяу"! ⚡
- Русский текст в консоли — для наших кошачьих душ. 🇷🇺❤️
- Нумерация файлов и сохранение прогресса — теперь это настоящая коллекция! 📂

## Что нужно для запуска? 🛠️
- ОС: Windows (раньше был `ShellExecuteA`, теперь `WinHTTP` — наш кошачий билет на диск 🎟️).
- Компилятор: Любой, кто понимает C++ (Visual Studio, MinGW — выбирайте свой меч! ⚔️).
- Библиотека: `winhttp.lib` (часть Windows SDK, нужна для v1.0.0).

## Как запустить это чудо? 🚀
1. Хватайте код с GitHub:
   ```bash
   git clone https://github.com/KDGOfficial/CatSplashinator.git
   ```
2. Соберите котика в исполняемый файл:
   - Visual Studio: Открывайте код, жмите F5 — и вперёд! 🎮
   - Командная строка (MSVC): `cl main.cpp /EHsc /link winhttp.lib`.
   - MinGW: `g++ main.cpp -o CatSplashinator -lwinhttp`.
3. Запускайте и наслаждайтесь:
   ```bash
   CatSplashinator.exe
   ```
4. Жмите Enter для нового котика 😻 или `q`, чтобы сбежать от мурлыкающего безумия. 😹

## История кошачьей эволюции 📜
Наш путь начался с простых прыжков в браузер и дошёл до настоящего кошачьего архива. Вот как это было:  
- **v0.1.0 - "Kitty Launcher"**  
  Первый мяу! Котики прыгали в браузер через `ShellExecuteA`. Просто, мило и без лишнего — как котёнок на подоконнике. 😺  
- **v0.2.0 - "Tab Tamer"**  
  Попытка приручить хаос: окна сворачивались, а `taskkill` грозился закрыть всё. Котики всё ещё в браузере, но уже с характером! 🐾  
- **v1.0.0 - "Cat Collector"** (29 апреля 2025)  
  Революция! Теперь котики скачиваются через `WinHTTP` и остаются с вами в виде `catN.jpg`. Больше никаких вкладок — только пушистый архив! 😸  

## Подводные кошачьи камни ⚠️
- Работает только на Windows — котики пока не освоили Linux и Mac. 🐧🍎
- Нет графического отображения — любуйтесь котиками в проводнике (пока!). 🖼️
- Старые версии оставляли вкладки, как шерсть на диване, но теперь всё локально! 🧹

## Кто сотворил это? 👨‍💻
Сделано с любовью к котам студентом второго курса KDG. Код писал ✍️, котов гладил 🐈, Enter нажимал ▶️ — всё сам!

## Лицензия 📜
MIT License — берите, творите, делитесь котиками с миром! 🌍😺

---
**Мяу-мяу и пушистых вам файлов!** 😽🎉

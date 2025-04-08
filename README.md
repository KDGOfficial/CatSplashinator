
# CatSplashinator 😺✨

---

## **English Version**
## (Avable only on v1.2.0 )

Welcome to the world of cats! 🐾 One press of Enter turns your day into a fluffy adventure! 😸 This bold C++ console app downloads random cats from `https://cataas.com/cat` and opens them in your system viewer. No hassle, just cats and code — the way we love it! 🐱💻

### What is this? 🤔
**CatSplashinator** is a cat collector that brings you a new purr in one go (well, almost). It started by opening cats in the browser, then learned to download them as `cat1.jpg`, `cat2.jpg`, and so on, and now it opens them in your system viewer with support for Russian and English languages! The last number is saved in `last_cat_number.txt`. Want a new cat? Press Enter! 😼 To exit, just hit `q` and leave in peace. ✌️

**Features:**
- Cats appear faster than you can say "meow"! ⚡
- Support for Russian and English languages — choose at startup! 🇷🇺🇬🇧
- File numbering and progress saving — a true collection! 📂
- Checks for existing cats — no overwrites! 🐾✅
- Opens cats in the system viewer — admire your purrs without extra libraries! 🖼️👀
- Stylish ASCII-art interface with a dotted-line title! 🎨

### What do you need to run it? 🛠️
- OS: Windows (we use `WinHTTP` for downloading and `ShellExecuteA` for opening images 🎟️).
- Compiler: Any that supports C++ (Visual Studio, MinGW — pick your sword! ⚔️).
- Libraries:
  - `winhttp.lib` (part of Windows SDK, needed for downloading).
  - `shell32.lib` (part of Windows SDK, needed for opening files).

### How to run this wonder? 🚀
1. Grab the code from GitHub:
   ```bash
   git clone https://github.com/KDGOfficial/CatSplashinator.git
   ```
2. Build the cat in Visual Studio:
   - Open the project in Visual Studio.
   - Ensure the project settings include the dependencies:
     - **Linker > Input > Additional Dependencies**: `winhttp.lib;shell32.lib`.
   - Press F5 to build and run 🎮.
3. Run and enjoy:
   - Through Visual Studio (F5).
   - Or directly: `.\Debug\CatSplashinator.exe`.
4. Choose your language (1 for English, 2 for Russian), then press Enter for a new cat 😻 or `q` to escape the purring madness. 😹

#### Alternative build via command line
If you prefer the command line:
```bash
cl main.cpp /EHsc /link winhttp.lib shell32.lib
```
Run: `main.exe`.

### History of Cat Evolution 📜
Our journey started with simple browser jumps and evolved into a convenient cat viewer. Here’s how it happened:  
- **v0.1.0 - "Kitty Launcher"**  
  First meow! Cats jumped into the browser via `ShellExecuteA`. Simple, cute, and no fuss — like a kitten on a windowsill. 😺  
- **v0.2.0 - "Tab Tamer"**  
  Taming the chaos: windows minimized, and `taskkill` threatened to close everything. Cats were still in the browser, but with attitude! 🐾  
- **v1.0.0 - "Cat Collector"** (29 April 2025)  
  Revolution! Cats are downloaded via `WinHTTP` and stay with you as `catN.jpg`. No more tabs! 😸  
- **v1.1.0 - "Purrfect Keeper"** (08 April 2025)  
  Perfect protection! The program checks if a cat with that number exists and avoids overwriting. 😺🔒  
- **v1.2.0 - "PurrViewer"**  (08 April 2025)  
  Purr-fect viewing! Added language support (Russian/English), a stylish ASCII-art interface with a dotted-line title, and cats now open in the system viewer! 🖼️👀  

### Catty Pitfalls ⚠️
- Works only on Windows — cats haven’t mastered Linux or Mac yet. 🐧🍎
- Opening in the system viewer depends on your system settings.

### Who created this? 👨‍💻
Made with love for cats by a 2nd-year KDG student. Wrote the code ✍️, petted the cats 🐈, pressed Enter ▶️ — all by myself!

### License 📜
MIT License — take it, create, share cats with the world! 🌍😺

**Meow-meow and fluffy files to you!** 😽🎉

---

## **Русская версия**

Добро пожаловать в мир котиков! 🐾 Одно нажатие Enter превращает ваш день в пушистое приключение! 😸 Эта дерзкая консольная программа на C++ скачивает случайных котиков с `https://cataas.com/cat` и открывает их в системном просмотрщике. Никаких сложностей, только коты и код — всё, как мы любим! 🐱💻

### Что это такое? 🤔
**CatSplashinator** — это кошачий коллекционер, который одним махом (ну, почти) приносит вам нового мурлыку. В первых версиях он открывал котиков в браузере, потом научился их скачивать как `cat1.jpg`, `cat2.jpg` и так далее, а теперь открывает их в системном просмотрщике с поддержкой русского и английского языков! Последний номер запоминается в `last_cat_number.txt`. Хотите нового котика? Жмите Enter! 😼 Для выхода — просто нажмите `q` и уходите с миром. ✌️

**Фишки:**
- Котики появляются быстрее, чем вы скажете "мяу"! ⚡
- Поддержка русского и английского языков — выбирайте при запуске! 🇷🇺🇬🇧
- Нумерация файлов и сохранение прогресса — настоящая коллекция! 📂
- Проверка существующих котиков — никаких перезаписей! 🐾✅
- Открытие котиков в системном просмотрщике — любуйтесь мурлыками без лишних библиотек! 🖼️👀
- Стильный ASCII-арт интерфейс с пунктирным заголовком! 🎨

### Что нужно для запуска? 🛠️
- ОС: Windows (используем `WinHTTP` для скачивания и `ShellExecuteA` для открытия изображений 🎟️).
- Компилятор: Любой с поддержкой C++ (Visual Studio, MinGW — выбирайте свой меч! ⚔️).
- Библиотеки:
  - `winhttp.lib` (часть Windows SDK, нужна для скачивания).
  - `shell32.lib` (часть Windows SDK, нужна для открытия файлов).

### Как запустить это чудо? 🚀
1. Скачайте код с GitHub:
   ```bash
   git clone https://github.com/KDGOfficial/CatSplashinator.git
   ```
2. Соберите котика в Visual Studio:
   - Откройте проект в Visual Studio.
   - Убедитесь, что в настройках проекта добавлены зависимости:
     - **Linker > Input > Additional Dependencies**: `winhttp.lib;shell32.lib`.
   - Нажмите F5 для сборки и запуска 🎮.
3. Запускайте и наслаждайтесь:
   - Через Visual Studio (F5).
   - Или напрямую: `.\Debug\CatSplashinator.exe`.
4. Выберите язык (1 для английского, 2 для русского), затем жмите Enter для нового котика 😻 или `q`, чтобы сбежать от мурлыкающего безумия. 😹

#### Альтернативная сборка через командную строку
Если вы предпочитаете командную строку:
```bash
cl main.cpp /EHsc /link winhttp.lib shell32.lib
```
Запустите: `main.exe`.

### История кошачьей эволюции 📜
Наш путь начался с простых прыжков в браузер и дошёл до удобного просмотра котиков. Вот как это было:  
- **v0.1.0 - "Kitty Launcher"**  
  Первый мяу! Котики прыгали в браузер через `ShellExecuteA`. Просто, мило и без лишнего — как котёнок на подоконнике. 😺  
- **v0.2.0 - "Tab Tamer"**  
  Попытка приручить хаос: окна сворачивались, а `taskkill` грозился закрыть всё. Котики всё ещё в браузере, но уже с характером! 🐾  
- **v1.0.0 - "Cat Collector"** (29 апреля 2025)  
  Революция! Котики скачиваются через `WinHTTP` и остаются с вами в виде `catN.jpg`. Больше никаких вкладок! 😸  
- **v1.1.0 - "Purrfect Keeper"** (08 апреля 2025)  
  Идеальная защита! Программа проверяет, есть ли котик с таким номером, и не перезаписывает его. 😺🔒  
- **v1.2.0 - "PurrViewer"**  (08 апреля 2025)  
  Идеальный просмотр! Добавлена поддержка языков (русский/английский), стильный ASCII-арт интерфейс с пунктирным заголовком, и котики открываются в системном просмотрщике! 🖼️👀  

### Подводные кошачьи камни ⚠️
- Работает только на Windows — котики пока не освоили Linux и Mac. 🐧🍎
- Открытие в системном просмотрщике зависит от настроек вашей системы.

### Кто сотворил это? 👨‍💻
Сделано с любовью к котам студентом второго курса KDG. Код писал ✍️, котов гладил 🐈, Enter нажимал ▶️ — всё сам!

### Лицензия 📜
MIT License — берите, творите, делитесь котиками с миром! 🌍😺

**Мяу-мяу и пушистых вам файлов!** 😽🎉

  ```



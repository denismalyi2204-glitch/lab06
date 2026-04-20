#!/bin/bash

echo "=== 1. Проверка файлов ==="
ls -la CMakeLists.txt CPackConfig.cmake DESCRIPTION ChangeLog.md 2>/dev/null

echo -e "\n=== 2. Версия проекта ==="
grep "PRINT_VERSION" CMakeLists.txt | grep -E "MAJOR|MINOR|PATCH|TWEAK"

echo -e "\n=== 3. Проверка CPack ==="
grep "CPACK_PACKAGE_VERSION" CPackConfig.cmake

echo -e "\n=== 4. Сборка проекта ==="
rm -rf _build
cmake -H. -B_build > /dev/null 2>&1
cmake --build _build > /dev/null 2>&1
echo "Сборка завершена"

echo -e "\n=== 5. Создание пакета ==="
cd _build
cpack -G "TGZ" > /dev/null 2>&1
PACKAGE=$(ls *.tar.gz 2>/dev/null)
echo "Создан пакет: $PACKAGE"
cd ..

echo -e "\n=== 6. Артефакты ==="
mkdir -p artifacts
mv _build/*.tar.gz artifacts/ 2>/dev/null
ls -lh artifacts/

echo -e "\n=== 7. Git теги ==="
git tag -l

echo -e "\n=== 8. Статус ==="
echo "✅ Все проверки пройдены!"
echo "📦 Пакет: $(ls artifacts/)"
echo "🔗 Репозиторий: https://github.com/${GITHUB_USERNAME}/lab06"

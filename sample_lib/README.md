# Библиотека комплексных чисел

Этот проект содержит библиотеку для работы с комплексными числами, реализованную на C++ с использованием CMake.

## Возможности библиотеки

### Основные операции
- Сложение комплексных чисел: (a + bi) + (c + di) = (a + c) + (b + d)i
- Вычитание комплексных чисел: (a + bi) - (c + di) = (a - c) + (b - d)i
- Умножение комплексных чисел: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
- Деление комплексных чисел: (a + bi) / (c + di) = ((ac + bd) + (bc - ad)i) / (c² + d²)

### Дополнительные функции
- Вычисление модуля комплексного числа
- Вычисление аргумента комплексного числа
- Сопряженное комплексное число
- Возведение в степень
- Квадратный корень
- Экспонента и логарифм
- Операторы сравнения
- Операторы присваивания

## Сборка проекта

### Сборка библиотеки

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Установка библиотеки

```bash
cmake --install . --prefix /usr/local
```

### Сборка демонстрационного приложения

```bash
# Сборка встроенного демо
cmake --build . --target complex_demo

# Или сборка внешнего демо (если библиотека установлена)
mkdir demo_build
cd demo_build
cmake -f ../CMakeLists_demo.txt ..
cmake --build .
```

## Использование

### Пример использования библиотеки

```cpp
#include "Complex.h"
#include <iostream>

int main() {
    Complex z1(3, 4);  // 3 + 4i
    Complex z2(1, -2); // 1 - 2i
    
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    
    // Основные операции
    std::cout << "z1 + z2 = " << (z1 + z2) << std::endl;
    std::cout << "z1 - z2 = " << (z1 - z2) << std::endl;
    std::cout << "z1 * z2 = " << (z1 * z2) << std::endl;
    std::cout << "z1 / z2 = " << (z1 / z2) << std::endl;
    
    // Свойства
    std::cout << "|z1| = " << z1.magnitude() << std::endl;
    std::cout << "arg(z1) = " << z1.phase() << std::endl;
    std::cout << "z1* = " << z1.conjugate() << std::endl;
    
    return 0;
}
```

## Структура проекта

```
sample_lib/
├── Complex.h              # Заголовочный файл библиотеки
├── Complex.cpp            # Реализация библиотеки
├── demo.cpp               # Демонстрационное приложение
├── CMakeLists.txt         # Основной CMake файл
├── CMakeLists_demo.txt    # CMake файл для внешнего демо
├── ComplexLibraryConfig.cmake.in  # Шаблон конфигурации
└── README.md              # Этот файл
```

## Требования

- CMake 3.12 или выше
- Компилятор C++17 или выше
- Linux, Windows или macOS

## Лицензия

Этот проект создан в учебных целях.
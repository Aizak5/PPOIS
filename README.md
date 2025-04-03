# Отчет по первой лр(вариант 80)

## Текст задания 

Модель танка 80

Предметная область: боевая техника и военное дело.

Важные сущности: танк, экипаж, боекомплект, топливо, военные операции.

Операции: операция обеспечения боеспособности танка, операция движения и маневрирования, операция ведения огня и стрельбы, операция ремонта и технического обслуживания, операция участия в военных учениях и конфликтах.


# Tank.py

## Описание

`Tank.py` — класс, который моделирует поведение военного танка с различными функциями, такими как движение, стрельба, участие в операциях, ремонт и пополнение ресурсов. Класс учитывает такие параметры, как количество топлива, боеприпасов, состояние танка и состав экипажа.

## Класс Tank

### Конструктор `__init__(self, model: str, fuel: int, ammo: int, crew: Dict[str, str])`

- **model** (str) — модель танка.
- **fuel** (int) — начальное количество топлива.
- **ammo** (int) — начальное количество боеприпасов.
- **crew** (Dict[str, str]) — экипаж танка, где ключи — это роли (например, "водитель", "наводчик"), а значения — имена членов экипажа.

### Методы

#### `drive(self, km: float) -> None`

Этот метод позволяет танку двигаться на заданное количество километров. 
- Проверяет, готов ли танк к движению, есть ли водитель и достаточно ли топлива.
- Если всё в порядке, уменьшает количество топлива на необходимое для движения количество.

#### `shoot(self) -> None`

Метод для стрельбы из танка.
- Проверяет, готов ли танк к стрельбе, есть ли наводчик и боеприпасы.
- Если все условия выполнены, уменьшает количество боеприпасов на 1.

#### `participate_in_operation(self, operation_name: str) -> None`

Метод для участия в военной операции.
- Проверяет, готов ли танк, есть ли топливо и боеприпасы.
- После операции танк может быть поврежден случайным образом, потерять топливо и боеприпасы.
- Выводит информацию о потерях и статусе танка.

#### `repair(self) -> None`

Метод для ремонта танка.
- Если танк поврежден, восстанавливает его работоспособность.

#### `refuel(self) -> None`

Метод для заправки танка.
- Если танк не полон, пополняет топливо до первоначального уровня.

#### `replenish_ammo(self) -> None`

Метод для пополнения боекомплекта.
- Если танк не полон, пополняет боеприпасы до первоначального уровня.

#### `status(self) -> None`

Метод для отображения текущего состояния танка.
- Выводит информацию о работоспособности танка, оставшемся топливе, боеприпасах и экипаже.

## Пример использования

```python
# Создание танка
tank = Tank(
    model="T-90",
    fuel=100,
    ammo=50,
    crew={"водитель": "Иван", "наводчик": "Петр"}
)

# Статус танка
tank.status()

# Движение на 30 км
tank.drive(30)

# Стрельба
tank.shoot()

# Участие в операции
tank.participate_in_operation("Операция Восток")

# Ремонт танка
tank.repair()

# Заправка танка
tank.refuel()

# Пополнение боеприпасов
tank.replenish_ammo()

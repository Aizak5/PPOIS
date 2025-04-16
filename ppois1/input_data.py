from typing import Dict

def input_tank_model() -> str:
    print("Введите модель танка:")
    return input().strip()

def input_fuel() -> int:
    while True:
        try:
            print("Введите количество топлива в литрах(примерно 500-1000):")
            fuel = int(input().strip())
            if fuel < 0:
                raise ValueError("Количество топлива не может быть отрицательным.")
            return fuel
        except ValueError as e:
            print(f"Ошибка: {e}. Пожалуйста, введите целое число.")

def input_ammo() -> int:
    while True:
        try:
            print("Введите количество боеприпасов:")
            ammo = int(input().strip())
            if ammo < 0:
                raise ValueError("Количество боеприпасов не может быть отрицательным.")
            return ammo
        except ValueError as e:
            print(f"Ошибка: {e}. Пожалуйста, введите целое число.")

def input_crew() -> Dict[str, str]:
    crew: Dict[str, str] = {}
    roles = ["капитан", "наводчик", "водитель"]
    for role in roles:
        while True:
            try:
                print(f"Введите имя {role}:",end="")
                entry = input().strip()
                if entry=="":
                    raise ValueError("имя не может быть пустым.")
                crew[role]=entry
                break
            except ValueError as e:
                print(f"Ошибка: {e} Пожалуйста, введите не пустое имя.")
    return crew

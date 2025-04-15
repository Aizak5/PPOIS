from Tank import Tank
from input_data import input_tank_model, input_fuel, input_ammo, input_crew

def main() -> None:
    try:
        model = input_tank_model()
        fuel = input_fuel()
        ammo = input_ammo()
        crew = input_crew()

        tank = Tank(model, fuel, ammo, crew)

        while True:
            print("\nВыберите действие:")
            print("1. Двигаться на заданное количество километров.")
            print("2. Выстрелить.")
            print("3. Участвовать в военной операции.")
            print("4. Отремонтировать танк.")
            print("5. Заправить танк.")
            print("6. Пополнить боекомплект.")
            print("7. Посмотреть состояние танка.")
            print("8. Выход.")

            choice = input("Ваш выбор: ").strip()

            if choice == "1":
                try:
                    km = float(input("Введите количество километров для движения: "))
                    if km < 0:
                        raise ValueError("Количество километров не может быть отрицательным.")
                    tank.drive(km)
                except ValueError as e:
                    print(f"Ошибка: {e}")
            elif choice == "2":
                tank.shoot()
            elif choice == "3":
                operation = input("Введите название операции: ")
                tank.participate_in_operation(operation)
            elif choice == "4":
                tank.repair()
            elif choice == "5":
                tank.refuel()
            elif choice == "6":
                tank.replenish_ammo()
            elif choice == "7":
                tank.status()
            elif choice == "8":
                print("Завершение программы.")
                break
            else:
                print("Неверный выбор, попробуйте снова.")
    except Exception as e:
        print(f"Произошла ошибка: {e}")

if __name__ == "__main__":
    main()

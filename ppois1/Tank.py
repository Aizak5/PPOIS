import random
from typing import Dict

class Tank:
    def __init__(self, model: str, fuel: int, ammo: int, crew: Dict[str, str]):
        self.model = model
        self.initial_fuel = fuel
        self.initial_ammo = ammo
        self.fuel = fuel
        self.ammo = ammo
        self.operational = True
        self.crew = crew

    def drive(self, km: float) -> None:
        if not self.operational:
            print("Танк не готов к движению.")
            return
        if "водитель" not in self.crew:
            print("Без водителя танк не может двигаться!")
            return
        fuel_needed = km*3
        if self.fuel < fuel_needed:
            print("Недостаточно топлива для движения!")
            return
        self.fuel -= fuel_needed
        print(f"Танк проехал {km} км. Оставшееся топливо: {self.fuel:.2f} литров.")

    def shoot(self) -> None:
        if not self.operational:
            print("Танк не готов к стрельбе.")
            return
        if "наводчик" not in self.crew:
            print("Без наводчика танк не может стрелять!")
            return
        if self.ammo <= 0:
            print("Нет боеприпасов для стрельбы!")
            return
        self.ammo -= 1
        print(f"Танк выстрелил. Осталось боеприпасов: {self.ammo}.")

    def participate_in_operation(self, operation_name: str) -> None:
        """Участие в военной операции с возможностью повреждения танка и уменьшением запасов."""
        if not self.operational:
            print("Танк не может участвовать в операции, он поврежден.")
            return

        if self.fuel <= 0:
            print("Танк не может участвовать в операции, недостаточно топлива!")
            return
        if self.ammo <= 0:
            print("Танк не может участвовать в операции, недостаточно боеприпасов!")
            return

        print(f"Танк участвует в операции: {operation_name}...")
        self.operational = random.choice([True, False])  

        fuel_lost = min(random.randint(1, int(self.fuel+1)),self.fuel)
        ammo_lost = random.randint(0, self.ammo)

        self.fuel = max(0, self.fuel - fuel_lost)  
        self.ammo = max(0, self.ammo - ammo_lost) 

        print(f"После операции: Потеряно топлива: {fuel_lost:.2f} литров, Потеряно боеприпасов: {ammo_lost}.")
        print(f"Оставшееся топливо: {self.fuel:.2f} литров, боеприпасов: {self.ammo}.")
        if not self.operational:
            print("Танк поврежден и требует ремонта.")

    def repair(self) -> None:
        if self.operational:
            print("Танк уже в рабочем состоянии.")
            return
        self.operational = True
        print("Танк отремонтирован и снова в строю.")

    def refuel(self) -> None:
        if self.fuel == self.initial_fuel:
            print("Танк уже полностью заправлен.")
        else:
            self.fuel = self.initial_fuel
            print(f"Танк заправлен. Текущее количество топлива: {self.fuel} литров.")

    def replenish_ammo(self) -> None:
        if self.ammo == self.initial_ammo:
            print("Боекомплект уже полон.")
        else:
            self.ammo = self.initial_ammo
            print(f"Боекомплект пополнен. Текущее количество боеприпасов: {self.ammo}.")

    def status(self) -> None:
        operational_status = "работает" if self.operational else "не работает"
        print(f"Танк {self.model} — {operational_status}. Топливо: {self.fuel:.2f} литров, боеприпасов: {self.ammo}.")
        print("Экипаж: ")
        for role, name in self.crew.items():
            print(f"{role}:{name}")

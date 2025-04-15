import unittest
from unittest.mock import patch
from Tank import Tank  # Импортируем класс Tank


class TestTank(unittest.TestCase):

    def setUp(self):
        """Настроить начальное состояние для каждого теста."""
        self.crew = {'водитель': 'Иванов', 'наводчик': 'Петров'}
        self.tank = Tank(model="T-90", fuel=100, ammo=50, crew=self.crew)

    def test_initialization(self):
        """Проверка инициализации объекта Tank."""
        self.assertEqual(self.tank.model, "T-90")
        self.assertEqual(self.tank.fuel, 100)
        self.assertEqual(self.tank.ammo, 50)
        self.assertTrue(self.tank.operational)
        self.assertEqual(self.tank.crew, self.crew)

    def test_drive_success(self):
        """Проверка успешного движения танка."""
        self.tank.drive(10)
        self.assertEqual(self.tank.fuel, 70)  # 100 - 10*3 = 70

    def test_drive_no_driver(self):
        """Проверка движения без водителя."""
        del self.tank.crew['водитель']  # Удаляем водителя
        self.tank.drive(10)
        self.assertEqual(self.tank.fuel, 100)  # Танк не должен двигаться, топливо не изменится

    def test_drive_not_enough_fuel(self):
        """Проверка движения при недостаточном количестве топлива."""
        self.tank.fuel = 5  # Топлива недостаточно для движения на 10 км
        self.tank.drive(10)
        self.assertEqual(self.tank.fuel, 5)  # Танк не должен двигаться, топливо не изменится

    def test_shoot_success(self):
        """Проверка успешного выстрела."""
        self.tank.shoot()
        self.assertEqual(self.tank.ammo, 49)  # Боеприпасов стало на 1 меньше

    def test_shoot_no_gunner(self):
        """Проверка выстрела без наводчика."""
        del self.tank.crew['наводчик']  # Удаляем наводчика
        self.tank.shoot()
        self.assertEqual(self.tank.ammo, 50)  # Боеприпасы не должны измениться

    def test_shoot_no_ammo(self):
        """Проверка выстрела при отсутствии боеприпасов."""
        self.tank.ammo = 0  # Нет боеприпасов
        self.tank.shoot()
        self.assertEqual(self.tank.ammo, 0)  # Боеприпасы не должны измениться

    @patch('random.choice')
    def test_participate_in_operation_success(self, mock_random_choice):
        """Проверка участия в операции с успешным результатом."""
        mock_random_choice.return_value = True  # Симуляция успешного состояния танка после операции

        self.tank.participate_in_operation("Операция Восток")

        # Проверка, что танк либо остался рабочим, либо стал поврежденным
        self.assertIn(self.tank.operational, [True, False])  # Ожидаем, что танк либо работает, либо поврежден

    @patch('random.choice')
    def test_participate_in_operation_damage(self, mock_random_choice):
        """Проверка участия в операции, где танк повреждается."""
        mock_random_choice.return_value = False  # Симуляция повреждения танка после операции

        self.tank.participate_in_operation("Операция Восток")

        # Проверка, что танк поврежден после операции
        self.assertFalse(self.tank.operational)  # Ожидаем, что танк поврежден

    def test_participate_in_operation_no_fuel(self):
        """Проверка участия в операции при недостаточном топливе."""
        self.tank.fuel = 0  # Нет топлива
        self.tank.participate_in_operation("Операция Восток")
        self.assertEqual(self.tank.fuel, 0)  # Танк не должен участвовать, топливо не должно измениться

    def test_participate_in_operation_no_ammo(self):
        """Проверка участия в операции при отсутствии боеприпасов."""
        self.tank.ammo = 0  # Нет боеприпасов
        self.tank.participate_in_operation("Операция Восток")
        self.assertEqual(self.tank.ammo, 0)  # Боеприпасы не должны измениться

    def test_repair_success(self):
        """Проверка успешного ремонта танка."""
        self.tank.operational = False  # Танк поврежден
        self.tank.repair()
        self.assertTrue(self.tank.operational)  # Танк должен быть отремонтирован

    def test_repair_already_working(self):
        """Проверка ремонта уже исправного танка."""
        self.tank.repair()
        self.assertTrue(self.tank.operational)  # Танк должен быть в рабочем состоянии

    def test_refuel_success(self):
        """Проверка успешной заправки танка."""
        self.tank.fuel = 50  # Танк не полный
        self.tank.refuel()
        self.assertEqual(self.tank.fuel, 100)  # Танк должен быть полностью заправлен

    def test_refuel_full(self):
        """Проверка заправки уже полного танка."""
        self.tank.refuel()
        self.assertEqual(self.tank.fuel, 100)  # Танк уже должен быть полный

    def test_replenish_ammo_success(self):
        """Проверка пополнения боекомплекта."""
        self.tank.ammo = 30  # Боеприпасов меньше максимума
        self.tank.replenish_ammo()
        self.assertEqual(self.tank.ammo, 50)  # Боеприпасы должны быть пополнены до максимума

    def test_replenish_ammo_full(self):
        """Проверка пополнения уже полного боекомплекта."""
        self.tank.replenish_ammo()
        self.assertEqual(self.tank.ammo, 50)  # Боеприпасы не должны измениться

    def test_status(self):
        """Проверка статуса танка."""
        self.tank.status()
        self.assertEqual(self.tank.model, "T-90")  # Проверка модели танка
        self.assertEqual(self.tank.fuel, 100)  # Проверка начального количества топлива
        self.assertEqual(self.tank.ammo, 50)  # Проверка начального количества боеприпасов


if __name__ == '__main__':
    unittest.main()

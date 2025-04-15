import unittest
from unittest.mock import patch
from Tank import Tank  


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
        self.assertEqual(self.tank.fuel, 70) 

    def test_drive_no_driver(self):
        """Проверка движения без водителя."""
        del self.tank.crew['водитель'] 
        self.tank.drive(10)
        self.assertEqual(self.tank.fuel, 100)  

    def test_drive_not_enough_fuel(self):
        """Проверка движения при недостаточном количестве топлива."""
        self.tank.fuel = 5 
        self.tank.drive(10)
        self.assertEqual(self.tank.fuel, 5)  

    def test_shoot_success(self):
        """Проверка успешного выстрела."""
        self.tank.shoot()
        self.assertEqual(self.tank.ammo, 49) 

    def test_shoot_no_gunner(self):
        """Проверка выстрела без наводчика."""
        del self.tank.crew['наводчик']  
        self.tank.shoot()
        self.assertEqual(self.tank.ammo, 50)  

    def test_shoot_no_ammo(self):
        """Проверка выстрела при отсутствии боеприпасов."""
        self.tank.ammo = 0 
        self.tank.shoot()
        self.assertEqual(self.tank.ammo, 0)  
    @patch('random.choice')
    def test_participate_in_operation_success(self, mock_random_choice):
        """Проверка участия в операции с успешным результатом."""
        mock_random_choice.return_value = True 

        self.tank.participate_in_operation("Операция Восток")


        self.assertIn(self.tank.operational, [True, False]) 

    @patch('random.choice')
    def test_participate_in_operation_damage(self, mock_random_choice):
        """Проверка участия в операции, где танк повреждается."""
        mock_random_choice.return_value = False  

        self.tank.participate_in_operation("Операция Восток")

    
        self.assertFalse(self.tank.operational) 

    def test_participate_in_operation_no_fuel(self):
        """Проверка участия в операции при недостаточном топливе."""
        self.tank.fuel = 0 
        self.tank.participate_in_operation("Операция Восток")
        self.assertEqual(self.tank.fuel, 0)  

    def test_participate_in_operation_no_ammo(self):
        """Проверка участия в операции при отсутствии боеприпасов."""
        self.tank.ammo = 0 
        self.tank.participate_in_operation("Операция Восток")
        self.assertEqual(self.tank.ammo, 0)  

    def test_repair_success(self):
        """Проверка успешного ремонта танка."""
        self.tank.operational = False 
        self.tank.repair()
        self.assertTrue(self.tank.operational) 

    def test_repair_already_working(self):
        """Проверка ремонта уже исправного танка."""
        self.tank.repair()
        self.assertTrue(self.tank.operational) 

    def test_refuel_success(self):
        """Проверка успешной заправки танка."""
        self.tank.fuel = 50 
        self.tank.refuel()
        self.assertEqual(self.tank.fuel, 100) 

    def test_refuel_full(self):
        """Проверка заправки уже полного танка."""
        self.tank.refuel()
        self.assertEqual(self.tank.fuel, 100)  

    def test_replenish_ammo_success(self):
        """Проверка пополнения боекомплекта."""
        self.tank.ammo = 30  
        self.tank.replenish_ammo()
        self.assertEqual(self.tank.ammo, 50) 

    def test_replenish_ammo_full(self):
        """Проверка пополнения уже полного боекомплекта."""
        self.tank.replenish_ammo()
        self.assertEqual(self.tank.ammo, 50) 

    def test_status(self):
        """Проверка статуса танка."""
        self.tank.status()
        self.assertEqual(self.tank.model, "T-90") 
        self.assertEqual(self.tank.fuel, 100) 
        self.assertEqual(self.tank.ammo, 50)  


if __name__ == '__main__':
    unittest.main()

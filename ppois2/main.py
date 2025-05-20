import tkinter as tk
from model import PatientRecordModel
from views import MainView
from controller import MainController


if __name__ == "__main__":
    root = tk.Tk()
    root.title("Учет пациентов")
    model = PatientRecordModel()
    controller = MainController(model, None)
    view = MainView(root, controller)
    controller.view = view
    root.geometry("800x600")
    root.mainloop()
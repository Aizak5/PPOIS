import tkinter as tk
from tkinter import ttk, messagebox
from tkcalendar import DateEntry


class MainView:
    def __init__(self, root, controller):
        self.root = root
        self.controller = controller
        self.page_size = tk.IntVar(value=10)
        self.current_page = tk.IntVar(value=0)

        # Меню
        menubar = tk.Menu(root)
        file_menu = tk.Menu(menubar, tearoff=0)
        file_menu.add_command(label="Открыть", command=controller.open_file)
        file_menu.add_command(label="Сохранить", command=controller.save_file)
        menubar.add_cascade(label="Файл", menu=file_menu)
        action_menu = tk.Menu(menubar, tearoff=0)
        action_menu.add_command(label="Добавить", command=controller.show_add_dialog)
        action_menu.add_command(label="Поиск", command=controller.show_search_dialog)
        action_menu.add_command(label="Удалить", command=controller.show_delete_dialog)
        menubar.add_cascade(label="Действия", menu=action_menu)
        root.config(menu=menubar)

        # Панель инструментов
        toolbar = ttk.Frame(root)
        ttk.Button(toolbar, text="Открыть", command=controller.open_file).pack(side=tk.LEFT)
        ttk.Button(toolbar, text="Сохранить", command=controller.save_file).pack(side=tk.LEFT)
        ttk.Button(toolbar, text="Добавить", command=controller.show_add_dialog).pack(side=tk.LEFT)
        ttk.Button(toolbar, text="Поиск", command=controller.show_search_dialog).pack(side=tk.LEFT)
        ttk.Button(toolbar, text="Удалить", command=controller.show_delete_dialog).pack(side=tk.LEFT)
        toolbar.pack(fill=tk.X)

        # Таблица
        self.tree = ttk.Treeview(root, columns=(
        "fullName", "address", "birthDate", "admissionDate", "doctorFullName", "diagnosis"), show="headings")
        for col in self.tree["columns"]:
            self.tree.heading(col, text=col.replace("fullName", "ФИО пациента").replace("address", "Адрес")
                              .replace("birthDate", "Дата рождения").replace("admissionDate", "Дата приема")
                              .replace("doctorFullName", "ФИО врача").replace("diagnosis", "Заключение"))
            self.tree.column(col, width=150)
        self.tree.pack(fill=tk.BOTH, expand=True)

        # Панель постраничного отображения
        pagination_frame = ttk.Frame(root)
        ttk.Button(pagination_frame, text="Первая", command=lambda: controller.update_page(0)).pack(side=tk.LEFT)
        ttk.Button(pagination_frame, text="Предыдущая",
                   command=lambda: controller.update_page(self.current_page.get() - 1)).pack(side=tk.LEFT)
        ttk.Button(pagination_frame, text="Следующая",
                   command=lambda: controller.update_page(self.current_page.get() + 1)).pack(side=tk.LEFT)
        ttk.Button(pagination_frame, text="Последняя", command=self.go_to_last_page).pack(side=tk.LEFT)
        ttk.Label(pagination_frame, text="Записей на странице:").pack(side=tk.LEFT)
        vcmd = (root.register(self.validate_page_size), '%P')
        self.page_size_entry = ttk.Entry(pagination_frame, textvariable=self.page_size, width=5, validate="key",
                                         validatecommand=vcmd)
        self.page_size_entry.pack(side=tk.LEFT)
        self.page_size.trace("w", lambda *args: controller.update_page(0))
        self.page_info = ttk.Label(pagination_frame, text="")
        self.page_info.pack(side=tk.LEFT)
        pagination_frame.pack(fill=tk.X)

    def validate_page_size(self, new_value):
        if new_value == "":
            return True
        try:
            value = int(new_value)
            return value > 0
        except ValueError:
            return False

    def go_to_last_page(self):
        try:
            page_size = self.page_size.get()
            if page_size <= 0:
                page_size = 10
                self.page_size.set(10)
            total_records = self.controller.model.get_total_records()
            last_page = (total_records - 1) // page_size if total_records > 0 else 0
            print(f"Go to last page: total_records={total_records}, page_size={page_size}, last_page={last_page}")
            self.controller.update_page(last_page)
        except tk.TclError:
            print("Invalid page_size, setting default")
            self.page_size.set(10)
            self.controller.update_page(0)

    def update_table(self, records, page, total_pages, total_records):
        for item in self.tree.get_children():
            self.tree.delete(item)
        for record in records:
            self.tree.insert("", tk.END, values=(record.full_name, record.address, record.birth_date,
                                                 record.admission_date, record.doctor_full_name, record.diagnosis))
        self.page_info.config(text=f"Страница {page + 1} из {total_pages}, Всего записей: {total_records}")


class AddRecordDialog:
    def __init__(self, parent, controller):
        self.dialog = tk.Toplevel(parent)
        self.dialog.title("Добавить запись")
        self.controller = controller

        ttk.Label(self.dialog, text="ФИО пациента:").grid(row=0, column=0, padx=5, pady=5)
        self.full_name = ttk.Entry(self.dialog)
        self.full_name.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Адрес:").grid(row=1, column=0, padx=5, pady=5)
        self.address = ttk.Entry(self.dialog)
        self.address.grid(row=1, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Дата рождения:").grid(row=2, column=0, padx=5, pady=5)
        self.birth_date = DateEntry(self.dialog, date_pattern="y-mm-dd")
        self.birth_date.grid(row=2, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Дата приема:").grid(row=3, column=0, padx=5, pady=5)
        self.admission_date = DateEntry(self.dialog, date_pattern="y-mm-dd")
        self.admission_date.grid(row=3, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="ФИО врача:").grid(row=4, column=0, padx=5, pady=5)
        self.doctor_full_name = ttk.Entry(self.dialog)
        self.doctor_full_name.grid(row=4, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Заключение:").grid(row=5, column=0, padx=5, pady=5)
        self.diagnosis = ttk.Entry(self.dialog)
        self.diagnosis.grid(row=5, column=1, padx=5, pady=5)

        ttk.Button(self.dialog, text="Добавить", command=self.add).grid(row=6, column=0, columnspan=2, pady=10)
        ttk.Button(self.dialog, text="Отмена", command=self.dialog.destroy).grid(row=7, column=0, columnspan=2, pady=10)

    def add(self):
        try:
            record = PatientRecord(
                self.full_name.get(),
                self.address.get(),
                self.birth_date.get_date(),
                self.admission_date.get_date(),
                self.doctor_full_name.get(),
                self.diagnosis.get()
            )
            self.controller.add_record(record)
            self.dialog.destroy()
        except ValueError as e:
            messagebox.showerror("Ошибка", "Проверьте правильность введенных данных")


class SearchDialog:
    def __init__(self, parent, controller):
        self.dialog = tk.Toplevel(parent)
        self.dialog.title("Поиск записей")
        self.controller = controller
        self.page_size = tk.IntVar(value=10)
        self.current_page = tk.IntVar(value=0)

        ttk.Label(self.dialog, text="Фамилия пациента:").grid(row=0, column=0, padx=5, pady=5)
        self.surname = ttk.Entry(self.dialog)
        self.surname.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Адрес:").grid(row=1, column=0, padx=5, pady=5)
        self.address = ttk.Entry(self.dialog)
        self.address.grid(row=1, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Дата рождения:").grid(row=2, column=0, padx=5, pady=5)
        self.birth_date = DateEntry(self.dialog, date_pattern="y-mm-dd")
        self.birth_date.grid(row=2, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="ФИО врача:").grid(row=3, column=0, padx=5, pady=5)
        self.doctor_name = ttk.Entry(self.dialog)
        self.doctor_name.grid(row=3, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Дата приема:").grid(row=4, column=0, padx=5, pady=5)
        self.admission_date = DateEntry(self.dialog, date_pattern="y-mm-dd")
        self.admission_date.grid(row=4, column=1, padx=5, pady=5)

        ttk.Button(self.dialog, text="Найти", command=self.search).grid(row=5, column=0, columnspan=2, pady=10)

        self.tree = ttk.Treeview(self.dialog, columns=(
        "fullName", "address", "birthDate", "admissionDate", "doctorFullName", "diagnosis"), show="headings")
        for col in self.tree["columns"]:
            self.tree.heading(col, text=col.replace("fullName", "ФИО пациента").replace("address", "Адрес")
                              .replace("birthDate", "Дата рождения").replace("admissionDate", "Дата приема")
                              .replace("doctorFullName", "ФИО врача").replace("diagnosis", "Заключение"))
            self.tree.column(col, width=150)
        self.tree.grid(row=6, column=0, columnspan=2, padx=5, pady=5)

        pagination_frame = ttk.Frame(self.dialog)
        ttk.Button(pagination_frame, text="Первая", command=lambda: self.update_page(0)).pack(side=tk.LEFT)
        ttk.Button(pagination_frame, text="Предыдущая",
                   command=lambda: self.update_page(self.current_page.get() - 1)).pack(side=tk.LEFT)
        ttk.Button(pagination_frame, text="Следующая",
                   command=lambda: self.update_page(self.current_page.get() + 1)).pack(side=tk.LEFT)
        ttk.Button(pagination_frame, text="Последняя", command=self.go_to_last_page).pack(side=tk.LEFT)
        ttk.Label(pagination_frame, text="Записей на странице:").pack(side=tk.LEFT)
        vcmd = (self.dialog.register(self.validate_page_size), '%P')
        self.page_size_entry = ttk.Entry(pagination_frame, textvariable=self.page_size, width=5, validate="key",
                                         validatecommand=vcmd)
        self.page_size_entry.pack(side=tk.LEFT)
        self.page_size.trace("w", lambda *args: self.update_page(0))
        self.page_info = ttk.Label(pagination_frame, text="")
        self.page_info.pack(side=tk.LEFT)
        pagination_frame.grid(row=7, column=0, columnspan=2, pady=5)

    def validate_page_size(self, new_value):
        if new_value == "":
            return True
        try:
            value = int(new_value)
            return value > 0
        except ValueError:
            return False

    def search(self):
        try:
            birth_date = self.birth_date.get_date() if self.birth_date.get() else None
            admission_date = self.admission_date.get_date() if self.admission_date.get() else None
            print(f"Searching with: surname={self.surname.get()}, address={self.address.get()}, "
                  f"birth_date={birth_date}, doctor_name={self.doctor_name.get()}, admission_date={admission_date}")
            self.controller.search_records(
                self.surname.get() or None,
                self.address.get() or None,
                birth_date,
                self.doctor_name.get() or None,
                admission_date
            )
            print(f"Search results: {len(self.controller.search_results)} records")
            if not self.controller.search_results:
                messagebox.showinfo("Поиск", "Записи не найдены")
            self.update_page(0)
        except ValueError:
            messagebox.showerror("Ошибка", "Некорректный формат даты")

    def go_to_last_page(self):
        try:
            page_size = self.page_size.get()
            if page_size <= 0:
                page_size = 10
                self.page_size.set(10)
            total_records = len(self.controller.search_results)
            last_page = (total_records - 1) // page_size if total_records > 0 else 0
            print(f"Go to last page: total_records={total_records}, page_size={page_size}, last_page={last_page}")
            self.update_page(last_page)
        except tk.TclError:
            print("Invalid page_size, setting default")
            self.page_size.set(10)
            self.update_page(0)

    def update_page(self, page):
        try:
            page_size = self.page_size.get()
            if page_size <= 0:
                page_size = 10
                self.page_size.set(10)
                messagebox.showwarning("Предупреждение",
                                       "Количество записей на странице должно быть больше 0. Установлено значение по умолчанию: 10.")
        except tk.TclError:
            page_size = 10
            self.page_size.set(10)
            messagebox.showwarning("Предупреждение", "Некорректное значение. Установлено значение по умолчанию: 10.")
        total_records = len(self.controller.search_results)
        total_pages = (total_records + page_size - 1) // page_size if total_records > 0 else 1
        if page < 0 or page >= total_pages:
            print(f"Invalid page: {page}, total_pages={total_pages}, total_results={total_records}")
            return
        self.current_page.set(page)
        start = page * page_size
        end = start + page_size
        records = self.controller.search_results[start:end]
        print(f"Displaying page {page}, records: {len(records)}")
        for item in self.tree.get_children():
            self.tree.delete(item)
        for record in records:
            self.tree.insert("", tk.END, values=(record.full_name, record.address, record.birth_date,
                                                 record.admission_date, record.doctor_full_name, record.diagnosis))
        self.page_info.config(text=f"Страница {page + 1} из {total_pages}, Всего записей: {total_records}")


class DeleteDialog:
    def __init__(self, parent, controller):
        self.dialog = tk.Toplevel(parent)
        self.dialog.title("Удалить записи")
        self.controller = controller

        ttk.Label(self.dialog, text="Фамилия пациента:").grid(row=0, column=0, padx=5, pady=5)
        self.surname = ttk.Entry(self.dialog)
        self.surname.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Адрес:").grid(row=1, column=0, padx=5, pady=5)
        self.address = ttk.Entry(self.dialog)
        self.address.grid(row=1, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Дата рождения:").grid(row=2, column=0, padx=5, pady=5)
        self.birth_date = DateEntry(self.dialog, date_pattern="y-mm-dd")
        self.birth_date.grid(row=2, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="ФИО врача:").grid(row=3, column=0, padx=5, pady=5)
        self.doctor_name = ttk.Entry(self.dialog)
        self.doctor_name.grid(row=3, column=1, padx=5, pady=5)

        ttk.Label(self.dialog, text="Дата приема:").grid(row=4, column=0, padx=5, pady=5)
        self.admission_date = DateEntry(self.dialog, date_pattern="y-mm-dd")
        self.admission_date.grid(row=4, column=1, padx=5, pady=5)

        ttk.Button(self.dialog, text="Удалить", command=self.delete).grid(row=5, column=0, columnspan=2, pady=10)
        ttk.Button(self.dialog, text="Отмена", command=self.dialog.destroy).grid(row=6, column=0, columnspan=2, pady=10)

    def delete(self):
        try:
            birth_date = self.birth_date.get_date() if self.birth_date.get() else None
            admission_date = self.admission_date.get_date() if self.admission_date.get() else None
            count = self.controller.delete_records(
                self.surname.get() or None,
                self.address.get() or None,
                birth_date,
                self.doctor_name.get() or None,
                admission_date
            )
            messagebox.showinfo("Результат", f"Удалено записей: {count}" if count > 0 else "Записи не найдены")
            self.dialog.destroy()
        except ValueError:
            messagebox.showerror("Ошибка", "Некорректный формат даты")
from tkinter import messagebox, filedialog
from views import AddRecordDialog, SearchDialog, DeleteDialog
from model import PatientRecord


class MainController:
    def __init__(self, model, view):
        self.model = model
        self.view = view
        self.search_results = []

    def add_record(self, record):
        self.model.add_record(record)
        self.update_page(0)

    def search_records(self, surname, address, birth_date, doctor_name, admission_date):
        self.search_results = self.model.search_records(surname, address, birth_date, doctor_name, admission_date)

    def delete_records(self, surname, address, birth_date, doctor_name, admission_date):
        count = self.model.delete_records(surname, address, birth_date, doctor_name, admission_date)
        self.update_page(self.view.current_page.get())
        return count

    def update_page(self, page):
        if not self.view:
            return
        try:
            page_size = self.view.page_size.get()
            if page_size <= 0:
                page_size = 10
                self.view.page_size.set(10)
                messagebox.showwarning("Предупреждение",
                                      "Количество записей на странице должно быть больше 0. Установлено значение по умолчанию: 10.")
        except tk.TclError:
            page_size = 10
            self.view.page_size.set(10)
            messagebox.showwarning("Предупреждение", "Некорректное значение. Установлено значение по умолчанию: 10.")

        total_records = self.model.get_total_records()
        total_pages = (total_records + page_size - 1) // page_size if total_records > 0 else 1
        if page < 0 or page >= total_pages:
            print(f"Invalid page: {page}, total_pages={total_pages}, total_records={total_records}")
            return
        self.view.current_page.set(page)
        records = self.model.get_page(page, page_size)
        print(f"Displaying page {page}, records: {len(records)}")
        self.view.update_table(records, page, total_pages, total_records)

    def show_add_dialog(self):
        AddRecordDialog(self.view.root, self)

    def show_search_dialog(self):
        SearchDialog(self.view.root, self)

    def show_delete_dialog(self):
        DeleteDialog(self.view.root, self)

    def open_file(self):
        filename = filedialog.askopenfilename(filetypes=[("XML files", "*.xml")])
        if filename:
            self.model.load_from_xml(filename)
            self.update_page(0)

    def save_file(self):
        filename = filedialog.asksaveasfilename(defaultextension=".xml", filetypes=[("XML files", "*.xml")])
        if filename:
            self.model.save_to_xml(filename)
import xml.dom.minidom as minidom
import xml.sax
from datetime import date


class PatientRecord:
    def __init__(self, full_name, address, birth_date, admission_date, doctor_full_name, diagnosis):
        self.full_name = full_name
        self.address = address
        self.birth_date = birth_date  # date object
        self.admission_date = admission_date  # date object
        self.doctor_full_name = doctor_full_name
        self.diagnosis = diagnosis

    def __str__(self):
        return (f"{self.full_name}, {self.address}, {self.birth_date}, "
                f"{self.admission_date}, {self.doctor_full_name}, {self.diagnosis}")


class PatientRecordModel:
    def __init__(self):
        self.records = []

    def add_record(self, record):
        self.records.append(record)

    def search_records(self, surname=None, address=None, birth_date=None, doctor_name=None, admission_date=None):
        print(f"Search params: surname={surname}, address={address}, birth_date={birth_date}, "
              f"doctor_name={doctor_name}, admission_date={admission_date}")
        print(f"Total records in model: {len(self.records)}")
        results = []
        for record in self.records:
            match = True
            if surname and surname.lower() not in record.full_name.lower():
                match = False
            if address and address.lower() not in record.address.lower():
                match = False
            if birth_date and record.birth_date != birth_date:
                match = False
            if doctor_name and doctor_name.lower() not in record.doctor_full_name.lower():
                match = False
            if admission_date and record.admission_date != admission_date:
                match = False
            if match:
                results.append(record)
        print(f"Found {len(results)} records")
        return results

    def delete_records(self, surname=None, address=None, birth_date=None, doctor_name=None, admission_date=None):
        to_delete = self.search_records(surname, address, birth_date, doctor_name, admission_date)
        for record in to_delete:
            self.records.remove(record)
        return len(to_delete)

    def get_page(self, page, page_size):
        start = page * page_size
        end = start + page_size
        return self.records[start:end]

    def get_total_records(self):
        return len(self.records)

    def save_to_xml(self, filename):
        doc = minidom.Document()
        root = doc.createElement("records")
        doc.appendChild(root)
        for record in self.records:
            record_elem = doc.createElement("record")
            for field, value in [
                ("fullName", record.full_name),
                ("address", record.address),
                ("birthDate", record.birth_date.isoformat()),
                ("admissionDate", record.admission_date.isoformat()),
                ("doctorFullName", record.doctor_full_name),
                ("diagnosis", record.diagnosis)
            ]:
                elem = doc.createElement(field)
                elem.appendChild(doc.createTextNode(value))
                record_elem.appendChild(elem)
            root.appendChild(record_elem)
        with open(filename, "w", encoding="utf-8") as f:
            doc.writexml(f, indent="  ", addindent="  ", newl="\n")

    def load_from_xml(self, filename):
        class RecordHandler(xml.sax.ContentHandler):
            def __init__(self, model):
                self.model = model
                self.current_record = {}
                self.current_field = None

            def startElement(self, name, attrs):
                if name != "record":
                    self.current_field = name

            def characters(self, content):
                if self.current_field:
                    self.current_record[self.current_field] = self.current_record.get(self.current_field, "") + content

            def endElement(self, name):
                if name == "record":
                    try:
                        record = PatientRecord(
                            self.current_record.get("fullName", ""),
                            self.current_record.get("address", ""),
                            date.fromisoformat(self.current_record.get("birthDate", "2000-01-01")),
                            date.fromisoformat(self.current_record.get("admissionDate", "2000-01-01")),
                            self.current_record.get("doctorFullName", ""),
                            self.current_record.get("diagnosis", "")
                        )
                        self.model.add_record(record)
                        print(f"Loaded record: {record}")
                    except ValueError as e:
                        print(f"Error loading record: {self.current_record}, {e}")
                    self.current_record = {}
                self.current_field = None

        self.records.clear()
        parser = xml.sax.make_parser()
        parser.setContentHandler(RecordHandler(self))
        parser.parse(filename)
import tkinter as tk
from tkinter import ttk

class Pegawai:
    def __init__(self, nama, id_pegawai):
        self.nama = nama
        self.id_pegawai = id_pegawai

    def info(self):
        return f"Nama: {self.nama}, ID Pegawai: {self.id_pegawai}"

class PegawaiTetap(Pegawai):
    def __init__(self, nama, id_pegawai, gaji_bulanan):
        super().__init__(nama, id_pegawai)
        self.gaji_bulanan = gaji_bulanan

    def info(self):
        return f"{super().info()}, Gaji Bulanan: {self.gaji_bulanan}"

class PegawaiHarian(Pegawai):
    def __init__(self, nama, id_pegawai, jam_kerja, tarif_per_jam):
        super().__init__(nama, id_pegawai)
        self.jam_kerja = jam_kerja
        self.tarif_per_jam = tarif_per_jam

    def info(self):
        return f"{super().info()}, Jam Kerja: {self.jam_kerja}, Tarif per Jam: {self.tarif_per_jam}"

class PegawaiKontrak(Pegawai):
    def __init__(self, nama, id_pegawai, durasi_kontrak, gaji_total):
        super().__init__(nama, id_pegawai)
        self.durasi_kontrak = durasi_kontrak
        self.gaji_total = gaji_total

    def info(self):
        return f"{super().info()}, Durasi Kontrak: {self.durasi_kontrak}, Gaji Total: {self.gaji_total}"

def show_info():
    selected_index = tree.selection()
    if selected_index:
        item = tree.item(selected_index)
        info_label.config(text=item["values"])

def add_employee():
    name = name_entry.get()
    emp_type = type_var.get()

    if emp_type == "Pegawai Tetap":
        salary = salary_entry.get()
        employee = PegawaiTetap(name, len(tree.get_children()) + 1, salary)
    elif emp_type == "Pegawai Harian":
        hours_worked = hours_entry.get()
        rate_per_hour = rate_entry.get()
        employee = PegawaiHarian(name, len(tree.get_children()) + 1, hours_worked, rate_per_hour)
    elif emp_type == "Pegawai Kontrak":
        contract_duration = duration_entry.get()
        total_salary = total_salary_entry.get()
        employee = PegawaiKontrak(name, len(tree.get_children()) + 1, contract_duration, total_salary)
    else:
        return

    tree.insert("", "end", values=(employee.info()))

# GUI setup
root = tk.Tk()
root.title("Manajemen Pegawai")

# Input Frame
input_frame = ttk.Frame(root, padding="10")
input_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

name_label = ttk.Label(input_frame, text="Nama:")
name_label.grid(row=0, column=0, sticky=tk.W)
name_entry = ttk.Entry(input_frame)
name_entry.grid(row=0, column=1, sticky=(tk.W, tk.E))

type_label = ttk.Label(input_frame, text="Tipe Pegawai:")
type_label.grid(row=1, column=0, sticky=tk.W)
type_var = tk.StringVar()
type_combobox = ttk.Combobox(input_frame, textvariable=type_var, values=["Pegawai Tetap", "Pegawai Harian", "Pegawai Kontrak"])
type_combobox.grid(row=1, column=1, sticky=(tk.W, tk.E))

salary_label = ttk.Label(input_frame, text="Gaji Bulanan:")
salary_label.grid(row=2, column=0, sticky=tk.W)
salary_entry = ttk.Entry(input_frame)
salary_entry.grid(row=2, column=1, sticky=(tk.W, tk.E))

hours_label = ttk.Label(input_frame, text="Jam Kerja:")
hours_label.grid(row=2, column=0, sticky=tk.W)
hours_entry = ttk.Entry(input_frame)
hours_entry.grid(row=2, column=1, sticky=(tk.W, tk.E))

rate_label = ttk.Label(input_frame, text="Tarif per Jam:")
rate_label.grid(row=3, column=0, sticky=tk.W)
rate_entry = ttk.Entry(input_frame)
rate_entry.grid(row=3, column=1, sticky=(tk.W, tk.E))

duration_label = ttk.Label(input_frame, text="Durasi Kontrak:")
duration_label.grid(row=4, column=0, sticky=tk.W)
duration_entry = ttk.Entry(input_frame)
duration_entry.grid(row=4, column=1, sticky=(tk.W, tk.E))

total_salary_label = ttk.Label(input_frame, text="Gaji Total:")
total_salary_label.grid(row=5, column=0, sticky=tk.W)
total_salary_entry = ttk.Entry(input_frame)
total_salary_entry.grid(row=5, column=1, sticky=(tk.W, tk.E))

add_button = ttk.Button(input_frame, text="Tambah Pegawai", command=add_employee)
add_button.grid(row=6, column=0, columnspan=2, pady=10)

# Treeview
tree_frame = ttk.Frame(root)
tree_frame.grid(row=1, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

columns = ("ID Pegawai", "Info")
tree = ttk.Treeview(tree_frame, columns=columns, show="headings", selectmode="browse")
tree.heading("ID Pegawai", text="ID Pegawai")
tree.heading("Info", text="Info")
tree.column("ID Pegawai", width=100, anchor=tk.CENTER)
tree.column("Info", anchor=tk.W)

tree.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

scrollbar = ttk.Scrollbar(tree_frame, orient="vertical", command=tree.yview)
scrollbar.grid(row=0, column=1, sticky=(tk.W, tk.E, tk.N, tk.S))
tree.configure(yscrollcommand=scrollbar.set)

# Info Label
info_label = ttk.Label(root, text="")
info_label.grid(row=2, column=0, pady=10)

# Bindings
tree.bind("<ButtonRelease-1>", lambda event: show_info())

root.mainloop()

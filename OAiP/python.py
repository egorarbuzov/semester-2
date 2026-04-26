import tkinter as tk
from tkinter import messagebox, filedialog
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# --- Физическое кодирование (возвращает интервалы) ---

def nrz_encode(bits):
    intervals = []
    for i, bit in enumerate(bits):
        level = 1 if bit == '1' else -1
        intervals.append((i, i+1, level))
    return intervals

def ami_encode(bits):
    intervals = []
    last = 1
    for i, bit in enumerate(bits):
        if bit == '1':
            level = last
            last = -last
        else:
            level = 0
        intervals.append((i, i+1, level))
    return intervals

def nrzi_encode(bits):
    intervals = []
    current = -1
    for i, bit in enumerate(bits):
        if bit == '1':
            current = -current
        intervals.append((i, i+1, current))
    return intervals

def _2b1q_encode(bits):
    intervals = []
    mapping = {'00': -2.5, '01': -0.833, '10': 2.5, '11': 0.833}
    for i in range(0, len(bits), 2):
        pair = bits[i:i+2]
        level = mapping.get(pair, 0)
        intervals.append((i, i+2, level))
    return intervals

def bipolar_rz_encode(bits):
    intervals = []
    for i, bit in enumerate(bits):
        if bit == '1':
            intervals.append((i, i+0.5, 1))
            intervals.append((i+0.5, i+1, 0))
        else:
            intervals.append((i, i+0.5, -1))
            intervals.append((i+0.5, i+1, 0))
    return intervals

def manchester_encode(bits):
    intervals = []
    for i, bit in enumerate(bits):
        if bit == '0':
            intervals.append((i, i+0.5, -1))
            intervals.append((i+0.5, i+1, 1))
        else:
            intervals.append((i, i+0.5, 1))
            intervals.append((i+0.5, i+1, -1))
    return intervals

# --- Логическое кодирование (возвращает новую битовую строку) ---

def scramble(bits):
    """Скремблер по формуле Bi = Ai XOR Bi-3 XOR Bi-5 (для i>=5)"""
    result = []
    n = len(bits)
    for i in range(n):
        a = int(bits[i])
        b = a
        if i >= 3:
            b ^= result[i-3]
        if i >= 5:
            b ^= result[i-5]
        result.append(b)
    return ''.join(str(b) for b in result)

def hdb3_logic(bits):
    """Замена 4 подряд нулей по правилам HDB3"""
    result = []
    i = 0
    count_ones = 0
    N = len(bits)
    while i < N:
        if bits[i] == '1':
            result.append('1')
            count_ones += 1
            i += 1
        else:
            if i + 3 < N and all(bits[j] == '0' for j in range(i, i+4)):
                if count_ones % 2 == 0:  # чётное -> 100V
                    result.extend(['1', '0', '0', '1'])
                    count_ones = 2
                else:                    # нечётное -> 000V
                    result.extend(['0', '0', '0', '1'])
                    count_ones = 1
                i += 4
            else:
                result.append('0')
                i += 1
    return ''.join(result)

def b8zs_logic(bits):
    """Замена 8 подряд нулей по правилам B8ZS (000V1*0V1*) = 00011011"""
    result = []
    i = 0
    N = len(bits)
    while i < N:
        if bits[i] == '1':
            result.append('1')
            i += 1
        else:
            if i + 7 < N and all(bits[j] == '0' for j in range(i, i+8)):
                result.extend(['0', '0', '0', '1', '1', '0', '1', '1'])
                i += 8
            else:
                result.append('0')
                i += 1
    return ''.join(result)

# --- Комбинированные коды: логическое преобразование + AMI ---

def scramble_ami(bits):
    new_bits = scramble(bits)
    return ami_encode(new_bits), new_bits

def hdb3_ami(bits):
    new_bits = hdb3_logic(bits)
    return ami_encode(new_bits), new_bits

def b8zs_ami(bits):
    new_bits = b8zs_logic(bits)
    return ami_encode(new_bits), new_bits

# --- Список кодов ---
encoders = [
    ("NRZ", nrz_encode, False),
    ("AMI", ami_encode, False),
    ("NRZI", nrzi_encode, False),
    ("2B1Q", _2b1q_encode, False),
    ("Bipolar RZ", bipolar_rz_encode, False),
    ("Manchester", manchester_encode, False),
    ("Scramble + AMI", scramble_ami, True),
    ("B8ZS + AMI", b8zs_ami, True),
    ("HDB3 + AMI", hdb3_ami, True)
]

# --- Добавление служебных битов ---
def add_parity_start_stop(data_bits):
    cnt_ones = data_bits.count('1')
    parity = '0' if cnt_ones % 2 == 0 else '1'
    return '0' + data_bits + parity + '1'

# --- Преобразование интервалов в координаты ---
def intervals_to_plot_data(intervals):
    x = []
    y = []
    for i, (start, end, level) in enumerate(intervals):
        if i == 0:
            x.append(start)
            y.append(level)
        else:
            x.append(start)
            y.append(level)
        x.append(end)
        y.append(level)
    return x, y

# --- Построение графиков ---
def plot_signals(original_bits):
    win = tk.Toplevel()
    win.title("Коды линейного кодирования")

    # Верхняя надпись с последовательностью (немного уменьшим шрифт)
    label_seq = tk.Label(win, text=f"Исходная последовательность (старт+30+чётность+стоп): {original_bits}",
                         font=("Courier", 12), bg="lightyellow")
    label_seq.pack(pady=2, padx=5, fill=tk.X)

    # Фрейм для кнопок (компактнее)
    btn_frame = tk.Frame(win)
    btn_frame.pack(pady=2)

    def save_plots():
        file_path = filedialog.asksaveasfilename(defaultextension=".png",
                                                 filetypes=[("PNG files", "*.png"),
                                                            ("PDF files", "*.pdf"),
                                                            ("All files", "*.*")])
        if file_path:
            fig.savefig(file_path, dpi=300, bbox_inches='tight')
            messagebox.showinfo("Сохранение", f"Графики сохранены в:\n{file_path}")

    btn_save = tk.Button(btn_frame, text="Сохранить графики", command=save_plots)
    btn_save.pack(side=tk.LEFT, padx=5)

    btn_close = tk.Button(btn_frame, text="Закрыть", command=win.destroy)
    btn_close.pack(side=tk.LEFT, padx=5)

    # УВЕЛИЧИВАЕМ РАЗМЕР ФИГУРЫ, чтобы графики занимали больше места
    fig, axes = plt.subplots(3, 3, figsize=(22, 16), dpi=100)
    # Настраиваем отступы, чтобы максимально использовать пространство
    fig.subplots_adjust(left=0.04, right=0.98, top=0.96, bottom=0.04, hspace=0.3, wspace=0.15)

    for ax, (name, encoder, is_combi) in zip(axes.flat, encoders):
        if is_combi:
            intervals, bits_for_labels = encoder(original_bits)
        else:
            intervals = encoder(original_bits)
            bits_for_labels = original_bits

        x, y = intervals_to_plot_data(intervals)
        ax.plot(x, y, color='blue', linewidth=2)
        ax.set_title(name, fontsize=10)  # чуть уменьшим шрифт заголовков

        # Убираем подписи осей
        ax.set_xlabel('')
        ax.set_ylabel('')

        # Устанавливаем пределы для корректного отображения графика
        if intervals:
            x_max = intervals[-1][1]
        else:
            x_max = len(original_bits)
        ax.set_xlim(0, x_max)
        ax.set_ylim(-4, 4)

        # --- НАСТРОЙКА ЧАСТОЙ СЕТКИ ---
        ax.set_xticks(range(0, int(x_max) + 1))
        ax.set_xticks([i + 0.5 for i in range(int(x_max))], minor=True)
        ax.set_yticks([-3, -2, -1, 0, 1, 2, 3])
        ax.set_yticks([-2.5, -1.5, -0.5, 0.5, 1.5, 2.5], minor=True)

        ax.grid(True, which='major', linestyle='-', alpha=0.6)
        ax.grid(True, which='minor', linestyle=':', alpha=0.3)

        # Для всех графиков, кроме 2B1Q, убираем подписи делений
        if name != "2B1Q":
            ax.set_xticklabels([])
            ax.set_yticklabels([])
        else:
            # Для 2B1Q оставляем подписи по оси Y (шкала напряжения)
            # Можно также подписать ось Y
            ax.set_ylabel('Напряжение', fontsize=8)
            # Убираем подписи по X, чтобы не загромождать
            ax.set_xticklabels([])
            # Метки Y оставляем по умолчанию (они заданы set_yticks)

        # Метки битов сверху (немного меньший шрифт)
        n_bits = len(bits_for_labels)
        for i, bit in enumerate(bits_for_labels):
            ax.text(i + 0.5, 3.5, bit, ha='center', va='center', fontsize=8,
                    bbox=dict(boxstyle='round,pad=0.1', facecolor='yellow', alpha=0.7))

    # Встраиваем фигуру в окно Tkinter
    canvas = FigureCanvasTkAgg(fig, master=win)
    canvas.draw()
    canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)

# --- Обработчики главного окна ---
def on_generate():
    input_str = entry.get().strip()
    if len(input_str) == 30 and all(c in '01' for c in input_str):
        data_bits = input_str
        full_bits = add_parity_start_stop(data_bits)
        plot_signals(full_bits)
    else:
        messagebox.showerror("Ошибка", "Введите 30 бит (только 0 и 1).")

def on_paste():
    try:
        clipboard_text = root.clipboard_get()
    except tk.TclError:
        messagebox.showerror("Ошибка", "Буфер обмена пуст или не содержит текста.")
        return
    clean = ''.join(clipboard_text.split())
    if len(clean) != 30 or not all(c in '01' for c in clean):
        messagebox.showerror("Ошибка", "В буфере должна быть строка из 30 символов 0 и 1 без пробелов.")
        return
    entry.delete(0, tk.END)
    entry.insert(0, clean)

# --- Главное окно ---
root = tk.Tk()
root.title("Кодирование сигналов")
root.geometry("450x180")

label = tk.Label(root, text="Введите 30 бит (0 или 1):")
label.pack(pady=5)

entry = tk.Entry(root, width=40)
entry.pack(pady=5)

frame_buttons = tk.Frame(root)
frame_buttons.pack(pady=10)

btn_paste = tk.Button(frame_buttons, text="Вставить из буфера", command=on_paste)
btn_paste.pack(side=tk.LEFT, padx=5)

btn_generate = tk.Button(frame_buttons, text="Построить графики", command=on_generate)
btn_generate.pack(side=tk.LEFT, padx=5)

root.mainloop()
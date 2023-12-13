import os
import matplotlib.pyplot as plt

def read_file(filename):
    sizes = []
    times = []
    with open(filename, 'r') as file:
        for line in file:
            size, time = map(float, line.split())
            sizes.append(size)
            times.append(time)
    return sizes, times

def plot_and_save(filename, sizes, times, label):
    plt.plot(sizes, times, label=label)
    plt.xlabel('Tamanho do Array')
    plt.ylabel('Tempo (s)')
    plt.title(f'Desempenho do ShellSort - {label}')
    plt.legend()
    script_dir = os.path.dirname(os.path.abspath(__file__))
    image_path = os.path.join(script_dir, filename)
    plt.savefig(image_path)
    plt.close()

# Leitura dos arquivos
melhorcaso_sizes, melhorcaso_times = read_file('melhorcaso.txt')
pirocaso_sizes, pirocaso_times = read_file('piorcaso.txt')

# Plotagem e salvamento das imagens
plot_and_save('melhorcaso.png', melhorcaso_sizes, melhorcaso_times, 'Melhor Caso')
plot_and_save('piorcaso.png', pirocaso_sizes, pirocaso_times, 'Pior Caso')

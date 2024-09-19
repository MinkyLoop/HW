import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.widgets import Slider
from scipy.special import legendre
from mpl_toolkits.mplot3d import Axes3D


#Задача 1

x = np.linspace(-1, 1, 500)

plt.figure(figsize=(10, 6))
plt.title("Полиномы Лежандра")

for n in range(1, 8):
    Pn = legendre(n)
    plt.plot(x, Pn(x), label=f'n = {n}')

plt.legend(loc='best')
plt.xlabel('x')
plt.ylabel('P_n(x)')
plt.grid(True)
plt.show()

#Задача 2

fig, axs = plt.subplots(2, 2, figsize=(10, 10))

ratios = [(3, 2), (3, 4), (5, 4), (5, 6)]
t = np.linspace(0, 2 * np.pi, 1000)

for ax, (a, b) in zip(axs.flat, ratios):
    x = np.sin(a * t)
    y = np.sin(b * t)
    ax.plot(x, y)
    ax.set_title(f'Соотношение частот {a}:{b}')
    ax.axis('equal')

plt.show()

#Задача 3

fig, ax = plt.subplots()
ax.set_xlim(-1, 1)
ax.set_ylim(-1, 1)
line, = ax.plot([], [])

def init():
    line.set_data([], [])
    return line,

def update(frame):
    t = np.linspace(0, 2 * np.pi, 1000)
    a = 1
    b = frame
    x = np.sin(a * t)
    y = np.sin(b * t)
    line.set_data(x, y)
    return line,

ani = animation.FuncAnimation(fig, update, frames=np.linspace(0, 1, 100), init_func=init, blit=True)
plt.show()

#Задача 4

x = np.linspace(0, 2 * np.pi, 1000)

init_freq1 = 1
init_amp1 = 1
init_freq2 = 1
init_amp2 = 1

fig, axs = plt.subplots(3, 1, figsize=(10, 8))

l1, = axs[0].plot(x, init_amp1 * np.sin(init_freq1 * x), 'r')
axs[0].set_title('Волна 1')

l2, = axs[1].plot(x, init_amp2 * np.sin(init_freq2 * x), 'b')
axs[1].set_title('Волна 2')

l3, = axs[2].plot(x, init_amp1 * np.sin(init_freq1 * x) + init_amp2 * np.sin(init_freq2 * x), 'g')
axs[2].set_title('Сложенная волна')

plt.subplots_adjust(left=0.1, bottom=0.25)

axcolor = 'lightgoldenrodyellow'
amp1_ax = plt.axes([0.1, 0.1, 0.65, 0.03], facecolor=axcolor)
freq1_ax = plt.axes([0.1, 0.15, 0.65, 0.03], facecolor=axcolor)
amp2_ax = plt.axes([0.1, 0.05, 0.65, 0.03], facecolor=axcolor)
freq2_ax = plt.axes([0.1, 0.2, 0.65, 0.03], facecolor=axcolor)

amp1_slider = Slider(amp1_ax, 'Amp 1', 0.1, 2.0, valinit=init_amp1)
freq1_slider = Slider(freq1_ax, 'Freq 1', 0.1, 10.0, valinit=init_freq1)
amp2_slider = Slider(amp2_ax, 'Amp 2', 0.1, 2.0, valinit=init_amp2)
freq2_slider = Slider(freq2_ax, 'Freq 2', 0.1, 10.0, valinit=init_freq2)

def update(val):
    amp1 = amp1_slider.val
    freq1 = freq1_slider.val
    amp2 = amp2_slider.val
    freq2 = freq2_slider.val
    y1 = amp1 * np.sin(freq1 * x)
    y2 = amp2 * np.sin(freq2 * x)
    l1.set_ydata(y1)
    l2.set_ydata(y2)
    l3.set_ydata(y1 + y2)
    fig.canvas.draw_idle()

amp1_slider.on_changed(update)
freq1_slider.on_changed(update)
amp2_slider.on_changed(update)
freq2_slider.on_changed(update)

plt.show()

#Задача 5

def mse(X, Y):
    return (X - Y)**2

x = np.linspace(-1, 1, 100)
y = np.linspace(-1, 1, 100)
X, Y = np.meshgrid(x, y)
Z = mse(X, Y)

fig = plt.figure(figsize=(14, 6))

ax1 = fig.add_subplot(121, projection='3d')
ax1.plot_surface(X, Y, Z, cmap='viridis')
ax1.set_title('MSE')
ax1.set_xlabel('X')
ax1.set_ylabel('Y')
ax1.set_zlabel('MSE')

ax2 = fig.add_subplot(122, projection='3d')
ax2.plot_surface(X, Y, np.log(Z + 1e-10), cmap='viridis')
ax2.set_title('Log MSE')
ax2.set_xlabel('X')
ax2.set_ylabel('Y')
ax2.set_zlabel('Log MSE')

plt.show()
import numpy as np
import cv2
from matplotlib import pyplot as plt
t,a,z = np.loadtxt('output.txt',delimiter = ',',unpack = True)
plt.ticklabel_format(style = 'plain')
plt.plot(t,a, color = "blue",label = "promedio")
plt.plot(t,z, color = "green",label = "1 + lg(n)")
plt.title('Comparación - Máximo')
plt.xlabel('Tamaño del arreglo (n)')
plt.ylabel('Comparaciones')
plt.legend()
plt.show();

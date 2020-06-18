import numpy as np
import cv2
from matplotlib import pyplot as plt

t,a = np.loadtxt('output.txt',delimiter = ',',unpack = True)

plt.plot(t,a,color = "blue",label = "comparaciones")

plt.title('Comparacion promedio máximo')
plt.xlabel('# elementos')
plt.ylabel('comparaciones_promedio')
plt.legend()
plt.show();

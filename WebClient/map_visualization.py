# Approach
# Read the text file with all the vector data
# Use plotting library to dislpay the map
# Plot tutorial found on: https://stackoverflow.com/questions/12265234/how-to-plot-2d-math-vectors-with-matplotlib

import numpy as np
import matplotlib.pyplot as plt
import ast

path_to_txt_file = 'map_vectors.txt'
f = open(path_to_txt_file,'r')
lines = f.read().splitlines()
vectors = []
for i in lines:
    vectors.append(ast.literal_eval(i))
soa = np.array(vectors)
X,Y,U,V = zip(*soa)
plt.figure()
ax = plt.gca()
ax.quiver(X,Y,U,V,angles='xy',scale_units='xy',scale=1)
ax.set_xlim([-5,10])
ax.set_ylim([-5,10])
plt.draw()
plt.show()

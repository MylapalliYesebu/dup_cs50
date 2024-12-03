import numpy as np
from scipy.spatial import distance_matrix

x = np.array([[1,2],[2,1],[2,2]])
y = np.array([[5,0],[1,2],[2,0]])

print("matrix  X:\n",x)
print("matrix  Y:\n",y)

dict_mat =distance_matrix(x,y,p=2)
print("Distance matrix:\n",dict_mat)
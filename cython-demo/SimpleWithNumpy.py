import numpy as np 


def JNI_API_testNumPy(param):
  print("congratulation!!! you call python NumPy success!!")
  x = np.empty([3,2], dtype = int) 
  print (x)
  print(pd.Series([2, 3, 4]))
  return x
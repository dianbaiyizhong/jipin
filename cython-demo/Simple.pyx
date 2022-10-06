import numpy as np 
import pandas as pd
# 接口函数，导出给Java Native的接口
def JNI_API_callPython(param):
  print("congratulation!!! you call python success!!")
  x = np.empty([3,2], dtype = int) 
  print(x)
  print(pd.Series([2, 3, 4]))
  return x

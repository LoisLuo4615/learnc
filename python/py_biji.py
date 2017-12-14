##插值
from scipy.interpolate import *
x=[100,200,300,400]
y=[10,20,30,40]
f=lagrange(x,y)

###去重
import numpy as np
import pandas as pd
x=pd.Series([1,1,2,3,4])
x.unique()
np.unique(x)

###

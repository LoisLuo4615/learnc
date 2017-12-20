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

###主成分分析
from sklearn.decomposition import PCA
D=np.random.rand(10,4)#生成随机矩阵
#pca=PCA(n_components='mle')#自动确定保留的特征数
pca=PCA()
pca.fit(D)

from pylab import *
plot(pca.explained_variance_ratio_)# 方差百分比
eigenvector=pca.components_ #返回模型特征向量

pca=PCA(3)#降成3维
pca.fit(D)
low_d=pca.transform(D)#降低纬度
pd.DataFrame(low_d).to_excel('low_d.csv')#保存结果
#pca.inverse_transform(low_d)# 复原数据

####统计特征函数
A=pd.Series(range(0,20))#构造向量
A.cumsum()#给出前N项和

pd.rolling_sum(A,2) #依次对相邻两项求和

###
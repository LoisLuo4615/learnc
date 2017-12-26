#-*- coding: utf-8 -*-
#逻辑回归 自动建模
#随机逻辑回归 or 递归特征消除法 特征选择
#refer to 《python数据分析与挖掘实践》
###数据量太少，结果不可靠。
import pandas as pd
import numpy as np
from sklearn.linear_model import LogisticRegression as LR
#参数初始化
filename = 'E:/git/learn/python/data/bankloan.xls'
data = pd.read_excel(filename)
X = np.array(data.iloc[:,:8])#dataframe 转 ndarray
y = np.array(data.iloc[:,8])#dataframe 转 ndarray


#1、随机逻辑回归选取特征向量
#模型的平均正确率为：0.814
#测试集准确率为0.814
from sklearn.linear_model import RandomizedLogisticRegression as RLR
rlr = RLR() #建立随机逻辑回归模型，筛选变量
rlr.fit(X, y) #训练模型
b=rlr.get_support() #获取特征筛选结果，也可以通过.scores_方法获取各个特征的分数
print('通过随机逻辑回归模型筛选特征结束。')
print('有效特征为：%s' % ','.join(data.columns[:8][b]))
x = X[:,b] #筛选好特征


# #2、递归特征消除法，返回特征选择后的数据
# #参数estimator为基模型
# #参数n_features_to_select为选择的特征个数
# #测试集预测准确率0.814
# from sklearn.feature_selection import RFE
# b=RFE(estimator=LR(), n_features_to_select=4).fit(X, y).support_##特征选取向量
# print(u'有效特征为：%s' % ','.join(data.columns[:8][b]))
# x=X[:,b]


lr = LR() #建立逻辑货柜模型
lr.fit(x, y) #用筛选后的特征数据来训练模型
print('模型训练结束。')
print('模型的平均正确率为：%s' % lr.score(x, y))
#给出模型的平均正确率，随机逻辑回归模型为80.6%

Y=lr.predict(x)#测试集预测类别
y_proba=lr.predict_proba(x)#测试集预测概率
print(int(sum(Y==y))/len(y))

from cm_plot import * #导入自行编写的混淆矩阵可视化函数
cm_plot(y,Y).show()
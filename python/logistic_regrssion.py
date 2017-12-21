#-*- coding: utf-8 -*-
#逻辑回归 自动建模
#refer to 《python数据分析与挖掘实践》
import pandas as pd
import numpy as np
from sklearn.linear_model import LogisticRegression as LR

#参数初始化
filename = 'E:/git/learn/python/data/bankloan.xls'
data = pd.read_excel(filename)
x = np.array(data.iloc[:500,:8])#dataframe 转 ndarray
y = np.array(data.iloc[:500,8])#dataframe 转 ndarray

x_test=np.array(data.iloc[500:,:8])#dataframe 转 ndarray
y_test=np.array(data.iloc[500:,8])
# from sklearn.linear_model import RandomizedLogisticRegression as RLR
# DeprecationWarning: Class RandomizedLogisticRegression is deprecated; The class RandomizedLogisticRegression is deprecated in 0.19 and will be removed in 0.21.
# RLR出错不可用
# rlr = RLR() #建立随机逻辑回归模型，筛选变量
# rlr.fit(x, y) #训练模型
# rlr.get_support() #获取特征筛选结果，也可以通过.scores_方法获取各个特征的分数
# print(u'通过随机逻辑回归模型筛选特征结束。')
# print(u'有效特征为：%s' % ','.join(data.columns[rlr.get_support()]))
# x = data[data.columns[rlr.get_support()]].as_matrix() #筛选好特征

from sklearn.feature_selection import RFE
#递归特征消除法，返回特征选择后的数据
#参数estimator为基模型
#参数n_features_to_select为选择的特征个数
b=RFE(estimator=LR(), n_features_to_select=3).fit(x, y).support_##特征选取向量
lr = LR() #建立逻辑货柜模型
lr.fit(x[:,b], y) #用筛选后的特征数据来训练模型
print(u'逻辑回归模型训练结束。')
print(u'模型的平均正确率为：%s' % lr.score(x[:,b], y))
#给出模型的平均正确率，随机逻辑回归模型，筛选变量为81.4%,本例为80.6%

Y=lr.predict(x_test[:,b])#测试集预测类别
y_proba=lr.predict_proba(x_test[:,b])#测试集预测概率
print(int(sum(Y==y_test))/len(y_test))#预测准确率0.8
#-*- coding: utf-8 -*-
#使用ID3决策树算法预测销量高低
#数据量太小
import pandas as pd

#参数初始化
inputfile = 'E:/git/learn/python/data/sales_data.xls'
data = pd.read_excel(inputfile, index_col = '序号') #导入数据

#数据是类别标签，要将它转换为数据
#用1来表示“好”、“是”、“高”这三个属性，用-1来表示“坏”、“否”、“低”
data[data == '好'] = 1
data[data == '是'] = 1
data[data == '高'] = 1
data[data != 1] = -1
x = data.iloc[:,:3].as_matrix().astype(int)
y = data.iloc[:,3].as_matrix().astype(int)

from sklearn.tree import DecisionTreeClassifier as DTC
dtc = DTC(criterion='entropy') #建立决策树模型，基于信息熵

#dtc = DTC(criterion='gini')#建立决策树模型，基于gini
dtc.fit(x, y) #训练模型

#导入相关函数，可视化决策树。
#导出的结果是一个dot文件，需要安装Graphviz才能将它转换为pdf或png等格式。
from sklearn.tree import export_graphviz
from sklearn import tree

from sklearn.externals.six import StringIO
import pydotplus
x = pd.DataFrame(x)
dot_data = StringIO()
# x = pd.DataFrame(x)
# with open("tree.pdf", 'w') as f:
#   f = export_graphviz(dtc, feature_names = x.columns, out_file = f)
tree.export_graphviz(dtc, out_file=dot_data)
graph = pydotplus.graph_from_dot_data(dot_data.getvalue())
graph.write_pdf("ID3.pdf")
#类别看value，value[0]>value[1]第一类，value[10]<value[1]第二类

Y_predict = dtc.predict(x)###用训练集来测试下准确率
print(int(sum(Y_predict==y))/len(y))#准确率为0.7647

from cm_plot import *##画混淆矩阵图，对比Y
cm_plot(y,Y_predict).show()
#!/usr/bin/env python
# -*- coding:utf-8 -*-

import pymysql
import os
import time
from configparser import ConfigParser

print(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))


con = pymysql.connect(host='XXXX', port=3306, user='XXXX', passwd='XXXX', db='XXXXX', charset='utf8')

##读取conf文件
cf = ConfigParser()
cf.read('XXXXX.conf')

id_max = cf.getint('SQL', 'id_max')
cur = con.cursor()
cur.execute('SELECT max(id) FROM XXXXX')
id_end = cur.fetchall()
print(id_end[0][0]-id_max)

###SQL code

#写入conf文件
id_max = id_end
cf.set('SQL', 'id_max', str(id_max[0][0]))
cf.write(open('XXXXX.conf', 'w'))
# print(id_max)


##删除文件
PATH = r'E:\up_ps\XXXX.csv'
if os.path.exists(PATH):
    os.remove(PATH)
else:
    pass


outfile = open('XXXX.csv', 'w+', encoding='utf-8')
outfile.write('"id"' + ',' + '"name"' + '\n')
for sumpay in XXXX:
    id = sumpay[0]
    name = sumpay[1]
    outfile.write('"' + str(id) + '"' + ',' + '"' + name + '"' + '\n')

outfile.close()

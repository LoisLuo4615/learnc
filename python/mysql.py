#ZSY

import pymysql
import pandas as pd
province = pd.read_csv('province.csv', encoding='utf-8',header=0,quotechar='"')

con=pymysql.connect(host='XXXX',port=XXXX,user='XXXX',passwd='XXXX',db='XXXX',charset='XXXX')
cur=con.cursor()

outfile = open('pr_end.csv', 'w+', encoding='utf-8')
for i in range(0,len(province)):
    sql="SELECT count(1) from c_base WHERE address like '{}%'".format(province['name'][i])
    print(sql)
    cur.execute(sql)
    num = cur.fetchall()
    print(num)
    outfile.write('"' + str(province['name'][i]) + '"' + ',' + '"' + str(num) + '"' + '\n')

cur.close()
con.close()
outfile.close()

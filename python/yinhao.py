import re
import pandas as pd
ps_title = pd.read_csv('ps_title3.csv', encoding='utf-8',header=0,quotechar='"')

def marks_replace(string):
    if string:
        while '"' in string:
            string = re.sub('"', '“', string, count=1)
            string = re.sub('"', '”', string, count=1)
        while "'" in string:
            string = re.sub("'", '‘', string, count=1)
            string = re.sub("'", '’', string, count=1)
    else:
        string = ''
    return string

outfile = open('ps_end2.csv', 'w+', encoding='utf-8')
outfile.write('"article_id"' + ',' + '"content"' + '\n')
for i in range(1,len(ps_title)):
    article_id = ps_title['article_id'][i]
    title=marks_replace(ps_title['content'][i])
    outfile.write('"' + str(article_id) + '"' + ',' + '"' + title + '"' + '\n')
outfile.close()

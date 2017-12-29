# -*- coding: utf-8 -*-
#@author: zhechengma

import requests
import time,random
from lxml.html import etree

d=[]
city='guangdong'

type1=['jixie','jichuang']
for j in range(0,2):
    c = 'a'
    z = ['a', 'b'] * 5000
    print(type1[j])
    print('-------------------------------------------------------------------------------------------------------------')
    try:

        f=open('company_name.txt','w+')
        for i in range(1,100000,1):
            time.sleep(random.randint(1, 10))
            url = ('http://b2b.huangye88.com/'+city+'/'+type1[j]+'/pn%d') % i
            print(url)
            headers = {
                'User-Agent': "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36"
            }
            response = requests.get(url, headers=headers)
            text=response.text
            tree = etree.HTML(text)
            url = tree.xpath('//a[@itemprop="name"]/@title')
    # for i in range(1,20):
    #     name = tree.xpath('//*[@id="jubao"]/dl[%d]/dt/h4')%i
    #     print(url,name)
    #print(type(url))
            for u in url:
                print(u)
                c = u
            z[i] = c
            print(type1[j])
            if z[i - 1] == z[i]:
                break
            print('\n')
        if __name__ == "__main__":
            pass
        if c=='a':
            d.append(j)
    except:
        print(type1[j])
        continue


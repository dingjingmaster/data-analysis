#!/usr/bin/env python
# -*- coding=utf-8 -*-
import os
import re
import sys
from functools import reduce


def time_str_format(t:str) ->int:
    timeArr = t.replace('"', '').split('-')
    # print(timeArr)
    return int("{:04d}{:02d}{:02d}".format(int(timeArr[0]), int(timeArr[1]), int(timeArr[2])))

def number_format(s:str)->float:
    n = 0
    s = s.replace(',', '')
    if s == '':
        return 0
    if s.endswith("B") or s.endswith("b"):
        n = float(s.replace('B', '').replace('b', ''))
        n *= 1000000000
    elif s.endswith("M") or s.endswith("m"):
        n = float(s.replace('M', '').replace('m', ''))
        n *= 1000000
    elif s.endswith('%'):
        n = float(s.replace('%', ''))
        n /= 100
    else:
        n = float(s)
    return n

def line_format(l:str) ->str:
    ll = l.strip()
    ll = ll.strip('"')
    return ll

def average_lately_xx_days(title: tuple, allData1: list, dayNum: int) -> None:
    allData1.sort(key=lambda  x: int(x[0]), reverse=True)
    allData = allData1[:dayNum]
    size = len(allData)
    days = reduce(lambda x, y : x if int(x[0]) > int(y[0]) else y, allData)[0]
    finValue = reduce(lambda x, y : float(x) + float(y[1]), allData, 0) / size
    staValue = reduce(lambda x, y : float(x) + float(y[2]), allData, 0) / size
    higValue = reduce(lambda x, y : float(x) + float(y[3]), allData, 0) / size
    lowValue = reduce(lambda x, y : float(x) + float(y[4]), allData, 0) / size
    jylValue = reduce(lambda x, y : float(x) + float(y[5]), allData, 0) / size
    zdfValue = reduce(lambda x, y : float(x) + float(y[6]), allData, 0) / size
    print("{} - {}, 最近{}天平均值: ".format(allData[len(allData) - 1][0], allData[0][0], dayNum))
    print("  {}: {}, {}: {:.3f}, {}: {:.3f}, {}: {:.3f}, {}: {:.3f}, {}: {:.3f}B, {}: {:.3f}%"
          .format(title[0], days,
                  title[1], finValue,
                  title[2], staValue,
                  title[3], higValue,
                  title[4], lowValue,
                  title[5], jylValue / 1000000000,
                  title[6], zdfValue * 100))
    pass

def average_all_result(title: tuple, allData: list) ->None:
    size = len(allData)
    days = reduce(lambda x, y : x if int(x[0]) > int(y[0]) else y, allData)[0]
    finValue = reduce(lambda x, y : float(x) + float(y[1]), allData, 0) / size
    staValue = reduce(lambda x, y : float(x) + float(y[2]), allData, 0) / size
    higValue = reduce(lambda x, y : float(x) + float(y[3]), allData, 0) / size
    lowValue = reduce(lambda x, y : float(x) + float(y[4]), allData, 0) / size
    jylValue = reduce(lambda x, y : float(x) + float(y[5]), allData, 0) / size
    zdfValue = reduce(lambda x, y : float(x) + float(y[6]), allData, 0) / size
    print("全量平均值: ")
    print("  {}: {}, {}: {:.3f}, {}: {:.3f}, {}: {:.3f}, {}: {:.3f}, {}: {:.3f}B, {}: {:.3f}%"
          .format(title[0], days,
                  title[1], finValue,
                  title[2], staValue,
                  title[3], higValue,
                  title[4], lowValue,
                  title[5], jylValue / 1000000000,
                  title[6], zdfValue * 100))
    pass

def read_all_data(filePath:str) ->(tuple, list):
    title = ()
    allData = []
    isFirstLine = True
    with open(filePath, 'r', encoding='utf-8-sig') as fr:
        for line in fr.readlines():
            line = line_format(line)
            arr = line.split('","')
            if isFirstLine:
                title = arr
                isFirstLine = False
                continue
            if len(arr) != 7:
                continue
            timeStamp = time_str_format(arr[0])
            finValue = arr[1].replace(',', '')
            staValue = number_format(arr[2])
            higValue = number_format(arr[3])
            lowValue = number_format(arr[4])
            jylValue = number_format(arr[5])
            zdfValue = number_format(arr[6])
            allData.append((timeStamp, finValue, staValue, higValue, lowValue, jylValue, zdfValue))
        fr.close()
    return title, allData

def main(sysArgs:list[str]) ->int:

    szHistory = os.path.dirname(sysArgs[0]) + "/../data/上证指数历史数据.csv"
    if not os.path.exists(szHistory):
        print("数据文件不存在!")
        exit(1)
    title, allData = read_all_data(szHistory)

    average_all_result(title, allData)

    print("\n")

    average_lately_xx_days(title, allData, 1)
    average_lately_xx_days(title, allData, 2)
    average_lately_xx_days(title, allData, 3)
    average_lately_xx_days(title, allData, 4)
    average_lately_xx_days(title, allData, 5)
    average_lately_xx_days(title, allData, 10)
    average_lately_xx_days(title, allData, 20)
    average_lately_xx_days(title, allData, 30)
    average_lately_xx_days(title, allData, 60)
    average_lately_xx_days(title, allData, 90)
    average_lately_xx_days(title, allData, 365)

    return 0


if __name__ == '__main__':
    exit(main(sys.argv))

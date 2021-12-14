#!/usr/bin/python
import json

def key_load(path):
    tlist=json.load(open(path))
    return tlist

def key_dump(tlist, path):
    json.dump(tlist, open(path,"w"), ensure_ascii=False)

def key_add(klist, rowNo, colNo, width, value1, value2, value3, value4, vicevalue1, vicevalue2, vicevalue3, vicevalue4):
    tmp = {}
    tmp["rowNo"] = rowNo
    tmp["colNo"] = colNo
    tmp["width"] = width
    tmp["valueLayer1"] = value1
    tmp["valueLayer2"] = value2
    tmp["valueLayer3"] = value3
    tmp["valueLayer4"] = value4
    tmp["viceValueLayer1"] = vicevalue1
    tmp["viceValueLayer2"] = vicevalue2
    tmp["viceValueLayer3"] = vicevalue3
    tmp["viceValueLayer4"] = vicevalue4
    klist.append(tmp)
    return klist



if __name__ == "__main__":
    path = "keymap.json"
    print("Input row: ")
    row = int(input())
    cols = []
    total = 0
    klist = []
    for i in range(row):
        print("Input col_" + str(i) +": ")
        tmp = int(input())
        cols.append(tmp)
        total += tmp
    for i in range(total):
        tmp = i
        for j in range(len(cols)):
            if tmp < cols[j]:
                colNo = tmp
                rowNo = j
                break
            else:
                tmp -= cols[j]

        #width = input("Row_"+str(rowNo)+"Col_" + str(colNo) +"width input: ")
        width,value1,value2 = input("Row_"+str(rowNo)+"Col_" + str(colNo) +" width,value1,value2 input: ").split(" ")
        klist = key_add(klist, rowNo, colNo, int(width), int(value1), int(value2), 0, 0, 0, 0, 0, 0)

    fin_list = {}
    fin_list["rows"] = row
    fin_list["cols"] = cols
    fin_list["data"] = klist
    key_dump(fin_list, path)







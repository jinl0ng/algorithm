def permutation(list, k, str=''):
    if len(list) == 1:
        print(k[0],str.lstrip(',')+','+list[0]+'\n')
        k[0]+=1
    else:
        for temp_str in list:
            temp_list = list[:]
            temp_list.remove(temp_str)
            permutation(temp_list, k, str+','+temp_str)
